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
#include <string>
#include "node.h"
#include "function.h"
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
  LBRACK  "{"
  RBRACK  "}"
  COMMA   ","
  FUNCTION "func"
  RETURN  "return"
;

%token <string> IDENTIFIER "identifier"
%token <float> NUMBER "number"
%token <string> TEXT "text"
%token <int> ZAHL "zahl"
%token <char> SIGN "sign"
%token <string> BLOCK "block"
%token <string> FUNCCALL "funccall"

%type  <string> assignments
%type  <string> assignment
%type  <string> funcBody
%type  <string> type
%type  <string> parameter
%type  <string> paramList
%type  <node*> exp

%printer { yyoutput << $$; } <*>;

%%
%start unit;
unit: assignments exp 	{
				//driver.root = new node($2);
//				driver.root->label = "ROOT";
                               // TO DO : Save $2 irgendwo sinnvoll
};

function:
"func" "identifier" "(" paramList ")" type "{" funcBody "}"{
  driver.printLine("func " + $2 + "(" + $4 +") " + $6 + "{\n"+ $8 +"}");
  driver.functions[$2] = new function($2, $6);
  driver.functions[$2]->variables = driver.tmpfunction->variables;
  driver.functions[$2]->parameters = driver.tmpfunction->parameters;
  driver.functions[$2]->returnExp = driver.tmpfunction->returnExp;
  driver.functions[$2]->Codegen(driver.TheModule, driver.Builder, driver.NamedValues);
  driver.tmpfunction = NULL;
  driver.tmpfunction = new function();
}
;

paramList:
%empty    {}
| parameter paramList {
  $$ += $1 + $2;
}
| "," paramList  {$$ += "," + $2;}
;

parameter:
"identifier" type{
  $$ = $1 + " " + $2;
  node* curr = new node();
  curr->type = $2;
  curr->label = "Ident: " + $1;
  driver.tmpfunction->variables[$1] = curr;
  driver.tmpfunction->nodes.push_back(curr);
  driver.tmpfunction->parameters[$1] = $2;
}
;

type:
%empty  {$$ = "";}
|"identifier"  {
  $$ = $1;
}

funcBody:
"identifier" ":=" exp funcBody {
    $3->label = "Ident: " + $1;
    if(driver.tmpfunction->variables.find($1) != driver.tmpfunction->variables.end()){
      node* var = driver.tmpfunction->variables[$1];
      var->type = $3->type;
      var->fval = $3->fval;
      var->sval = $3->fval;
      var->ival = $3->ival;
      var->cval = $3->ival;
      if(driver.tmpfunction->variables[$1]->label == driver.tmpfunction->returnExp->label){
        driver.tmpfunction->returnExp = var;
      }
    }
    else{
      driver.tmpfunction->variables[$1] = $3;
    }
    $$ += $1 + " := " + driver.to_string($3->fval) + "\n";
}
| "return" exp {
  $$ += "return " + $2->label + "\n";
  driver.tmpfunction->returnExp = driver.tmpfunction->getNode($2->label);
  if(driver.tmpfunction->returnExp == NULL && driver.tmpfunction->returnType != "void"){
    driver.tmpfunction->returnExp = new node($2);
    string prefix = "Ident: ";
    string name = $2->label.substr($2->label.find("prefix")+prefix.length()+1);
    driver.tmpfunction->variables[name] = $2;
  }
  //cout << "Trying to return " << $2 << " with label " << $2->label << " ,type " << $2->type << " and value " << $2->fval << endl;
}
|  %empty {}
;

assignments:
  %empty                 {}
| assignments function {

}
| assignments assignment
{
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
			};

%left "+" "-";
%left "*" "/";
exp:
  exp "+" exp   { //$$ = $1 + $3;
			node*tmp = new node($1, $3);
			tmp->label = "Operator: +";
			tmp->type = "+";
			$$ = tmp;
			  //$$ = new node(tmp, (node*)NULL);
      if($1->type == "function"){
        $1 = driver.functions[$1->label]->returnExp;
      }
      if($3->type == "function"){
        $3 = driver.functions[$3->label]->returnExp;
        cout << "Teilerfolg! " << $3 << endl;
      }
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
			}else{cout << "Type mismatch between " << $1->type << " and " << $3->type << endl;
        cout << "$1: " << $1->label << ", " << $1->fval << endl;
        cout << "$3: " << $3->label << ", " << $3->fval << endl;
        /*exit(1);*/}
		  }
| exp "-" exp   { //$$ = $1 - $3;
		  node*tmp = new node($1, $3);
		  tmp->type = "-";
		  tmp->label = "Operator: -";
		  $$ = tmp;
			//$$ = new node(tmp, (node*)NULL);

      if($1->type == "function"){
        $1 = driver.functions[$1->label]->returnExp;
      }
      if($3->type == "function"){
        $3 = driver.functions[$3->label]->returnExp;
      }
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
			}else{cout << "Type mismatch between " << $1->type << " and " << $3->type << endl; /*exit(1);*/}
		}
| exp "*" exp   { //$$ = $1 * $3;
		  node*tmp = new node($1, $3);
		  tmp->type = "*";
		  tmp->label = "Operator: *";
		  $$ = tmp;
			//$$ = new node(tmp, (node*)NULL);

      if($1->type == "function"){
        $1 = driver.functions[$1->label]->returnExp;
      }
      if($3->type == "function"){
        $3 = driver.functions[$3->label]->returnExp;
      }
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
			}else{
      cout << "Type mismatch between " << $1->type << " and " << $3->type << endl;
      cout << "$1: " << $1->label << " Type: " << $1->type << endl;
      cout << "$3: " << $3->label << " Type: " << $3->type << endl;
      /* exit(1);*/}
		}
| exp "/" exp   { //$$ = $1 / $3;
		  node*tmp = new node($1, $3);
		  tmp->type = "/";
		  tmp->label = "Operator: /";
		  $$ = tmp;
			//$$ = new node(tmp, (node*)NULL);

      if($1->type == "function"){
        $1 = driver.functions[$1->label]->returnExp;
      }
      if($3->type == "function"){
        $3 = driver.functions[$3->label]->returnExp;
      }
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
			}else{ cout << "Type mismatch between " << $1->type << " and " << $3->type << endl; /*exit(1);*/}
		  }
| "(" exp ")"   { $$ = $2; }
| "identifier"  { //$$ = driver.getVariable($1)
		    if(driver.variables.find($1) != driver.variables.end()){
		      $$ = new node(driver.variables[$1]);
		    }
        else if(driver.tmpfunction->variables.find($1) != driver.tmpfunction->variables.end()){
              $$ = new node(driver.tmpfunction->variables[$1]);
        }
        else{
            $$ = new node();
            $$->label = "Ident: " + $1;
        }
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
		  char c = (char) $1;
		  string label = "Sign: ";
		  label.insert(label.end(), c);
		  $$->label = label;
		}
| "funccall"	{
    $$ = driver.filterFunc($1);
		   if($$ == NULL){
			   std::cout << "Funktion \"" << $1 << "\" entweder nicht gefunden oder falsche Parameter!" << std::endl;
			   exit(0);
		   }
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
