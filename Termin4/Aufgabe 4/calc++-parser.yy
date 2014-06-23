/***********************
 * Example of C++ in Bison (yacc)
 * Compare Bison Manual, Section 10.1.6 A Complete C++ Example
 * https://www.gnu.org/software/bison/manual/html_node/A-Complete-C_002b_002b-Example.html
 * The Makefile has been simplified radically, but otherwise
 * everything here comes from the Bison source code (see also).
 * (This comment added by Prof. R. C. Moore, fbi.h-da.de)
 *
 * This is the yacc (bison) file, i.e. grammar file.
 * See also calc++-scanner.ll for the lexical scanner
 * (flex input).
 *
 ***********************/

%skeleton "lalr1.cc" /* -*- C++ -*- */
%require "3.0.2"
%defines
%define parser_class_name {calcxx_parser}

%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires
{
# include <string>
#include "node.h"
class calcxx_driver;
using namespace std;
}

// The parsing context.
%param { calcxx_driver& driver }

%locations
%initial-action
{
  // Initialize the initial location.
  @$.begin.filename = @$.end.filename = &driver.file;
};

%define parse.trace
%define parse.error verbose

%code
{
# include "calc++-driver.hh"
using namespace std;
}

%define api.token.prefix {TOK_}
%token
  END  0  "end of file"
  ASSIGN  ":="
  MINUS   "-"
  PLUS    "+"
  STAR    "*"
  SLASH   "/"
  LPAREN  "("
  RPAREN  ")"
;

%token <string> IDENTIFIER "identifier"
%token <float> NUMBER "number"
%token <string> TEXT "text"
%token <int> ZAHL "zahl"
%token <char> SIGN "sign"
%type  <node*> exp

%printer { yyoutput << $$; } <*>;

%%
%start unit;
unit: assignments exp  	{
				//driver.root = new node($2);
//				driver.root->label = "ROOT";
                               // TO DO : Save $2 irgendwo sinnvoll
			}

//
assignments:
  %empty                 {}
| assignments assignment {	
//				driver.result.push_back();			
			};

assignment:
  "identifier" ":=" exp { 
			  driver.variables[$1] = $3;
			  if($3->sval != ""){
			    driver.printLine($1 + " := " + $3->sval);
			  }
			  else{
			    driver.printLine($1 + " := " + driver.to_string($3->fval));
			  }
			  driver.result.push_back($3);
			}

%left "+" "-";
%left "*" "/";
exp:
  exp "+" exp   { //$$ = $1 + $3;
			node*tmp = new node($1, $3);
			tmp->label = "Operator: +";
			tmp->type = "+";
			$$ = tmp;
			  //$$ = new node(tmp, (node*)NULL);
			if($1->type == "string" && $3->type == "string"){
				$$->sval = $1->sval;
				$$->sval = $$->sval.append($3->sval);
				$$->label = "Value: " + $$->sval;
				$$->type = "string";
				cout << $1->sval << " + " << $3->sval << " = " << $$->sval << endl;
			}
			else if($1->type == "float" && $3->type == "float"){
				$$->type = "float";
				$$->fval = $1->fval + $3->fval;
				$$->label = driver.to_string($$->fval);
				cout << $1->fval << " + " << $3->fval << " = " << $$->fval << endl;
			}
			else if($1->type == "int" && $3->type == "int"){
				$$->type = "int";
				$$->ival = $1->ival + $3->ival;
				$$->label = "Zahl: ";// + std::to_string($$->ival);
				cout << $1->ival << " + " << $3->ival << " = " << $$->ival << endl;
			}
			else if($1->type == "char" && $3->type == "char"){
				$$->type = "char";
				$$->cval = $1->cval + $3->cval;
				$$->label = (char)$$->cval;
				cout << $1->cval << " + " << $3->cval << " = " << $$->cval << endl;
			}else{cout << "Type mismatch between " << $1->type << " and " << $3->type << endl; exit(1);}
		  }
| exp "-" exp   { //$$ = $1 - $3;
		  node*tmp = new node($1, $3);
		  tmp->type = "-";
		  tmp->label = "Operator: -";
		  $$ = tmp;
			//$$ = new node(tmp, (node*)NULL);
		  if($1->type == "float" && $3->type == "float"){
				$$->type = "float";
				$$->fval = $1->fval - $3->fval;
				$$->label = driver.to_string($$->fval);
				cout << $1->fval << " - " << $3->fval << " = " << $$->fval << endl;
			}
			else if($1->type == "int" && $3->type == "int"){
				$$->type = "int";
				$$->ival = $1->ival - $3->ival;
				$$->label = "Zahl: ";// + std::to_string($$->ival);
				cout << $1->ival << " - " << $3->ival << " = " << $$->ival << endl;
			}
			else if($1->type == "char" && $3->type == "char"){
				$$->type = "char";
				$$->cval = $1->cval - $3->cval;
				$$->label = (char)$$->cval;
				cout << $1->cval << " - " << $3->cval << " = " << $$->cval << endl;
			}else{cout << "Type mismatch between " << $1->type << " and " << $3->type << endl; exit(1);}
		}
| exp "*" exp   { //$$ = $1 * $3;
		  node*tmp = new node($1, $3);
		  tmp->type = "*";
		  tmp->label = "Operator: *";
		  $$ = tmp;
			//$$ = new node(tmp, (node*)NULL);
		  if($1->type == "float" && $3->type == "float"){
				$$->type = "float";
				$$->fval = $1->fval * $3->fval;
				$$->label = driver.to_string($$->fval);
				cout << $1->fval << " * " << $3->fval << " = " << $$->fval << endl;
			}
			else if($1->type == "int" && $3->type == "int"){
				$$->type = "int";
				$$->ival = $1->ival * $3->ival;
				$$->label = "Zahl: "; // + std::to_string($$->ival);
				cout << $1->ival << " * " << $3->ival << " = " << $$->ival << endl;
			}
			else if($1->type == "char" && $3->type == "char"){
				$$->type = "char";
				$$->cval = $1->cval * $3->cval;
				$$->label = (char)$$->cval;
				cout << $1->cval << " * " << $3->cval << " = " << $$->cval << endl;
			}else{cout << "Type mismatch between " << $1->type << " and " << $3->type << endl; exit(1);}
		}
| exp "/" exp   { //$$ = $1 / $3;
		  node*tmp = new node($1, $3);
		  tmp->type = "/";
		  tmp->label = "Operator: /";
		  $$ = tmp;
			//$$ = new node(tmp, (node*)NULL);
		  if($1->type == "float" && $3->type == "float"){
				$$->type = "float";
				$$->fval = $1->fval / $3->fval;
				$$->label = driver.to_string($$->fval);
				cout << $1->fval << " / " << $3->fval << " = " << $$->fval << endl;
			}
			else if($1->type == "int" && $3->type == "int"){
				$$->type = "int";
				$$->ival = $1->ival / $3->ival;
				$$->label = "Zahl: ";// + std::to_string($$->ival);
				cout << $1->ival << " / " << $3->ival << " = " << $$->ival << endl;
			}
			else if($1->type == "char" && $3->type == "char"){
				$$->type = "char";
				$$->cval = $1->cval / $3->cval;
				$$->label = (char)$$->cval;
				cout << $1->cval << " / " << $3->cval << " = " << $$->cval << endl;
			}else{ cout << "Type mismatch between " << $1->type << " and " << $3->type << endl; exit(1);}
		  }
| "(" exp ")"   { $$ = $2; }
| "identifier"  { //$$ = driver.getVariable($1)
		    if(driver.variables.find($1) != driver.variables.end()){
		      $$ = new node(driver.variables[$1]);
			  
		    }else {
		      $$ = new node();
		    }
			$$->label = "Ident: " + $1;
		    //$$->label = driver.variables[$1]->type + "Identifier: " + $1 + " = " + driver.variables[$1]->label;
                }
| "number"      { //swap ($$, $1); 
		  $$ = new node();
		  $$->fval = $1;
		  $$->type = "float";
		  $$->label = "Number: " + driver.to_string($1);
		}
| "zahl"		{
		  $$ = new node();
		  $$->ival = $1;
		  $$->type = "int";
		  //$$->label = "Zahl: " + std::itoa($1);
		}
| "sign"	{
		  $$ = new node();
		  $$->cval = $1;
		  $$->type = "char";
		  $$->label = "Sign: " + (char)($1);
		}
| "text"	{ $$ = new node();
		  $$->sval = $1;
		  $$->type = "string";
		  $$->label = "Text: " + $1;};


%%

void
yy::calcxx_parser::error (const location_type& l,
                          const string& m)
{
  driver.error (l, m);
}
