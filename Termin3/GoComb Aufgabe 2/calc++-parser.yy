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
class calcxx_driver;
class node;
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
#include "node.h"
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

%token <std::string> IDENTIFIER "identifier"
%token <float> NUMBER "number"
%token <std::string> TEXT "text"
%type  <node> exp
%type  <std::string> sexp

%printer { yyoutput << $$; } <*>;

%%
%start unit;
unit: assignments exp  { driver.result = $2.fval; }
| assignments sexp {driver.erg = $2;};

assignments:
  %empty                 {}
| assignments assignment {};

assignment:
  "identifier" ":=" exp { driver.variables[$1] = $3.fval; /*driver.addGraph($1, $3);
			  driver.printLine($1 + " = "  + driver.to_string($3));*/
			}
  | "identifier" ":=" sexp {
				driver.svar[$1] = (string) $3;
				driver.printLine($1 + " = "  + $3);
			   };

%left "+" "-";
%left "*" "/";
exp:
  exp "+" exp   { //$$ = $1 + $3;
  
		  $$ = new node($1, $3);
		  $$.fval = $1.fval + $3.fval;/*
		  std::string tmp = driver.addGraph(driver.to_string($1) + " + " + driver.to_string($3));
		  driver.setTmpID(tmp);
		  driver.connect(driver.getTmpID(), driver.addGraph($1));
		  driver.connect(driver.getTmpID(), driver.addGraph($3));
		  driver.setTmpID(driver.addGraph($$));
		  driver.connect(driver.getTmpID(), tmp);*/
		  }
| exp "-" exp   { //$$ = $1 - $3;

		  $$ = new node($1, $3);
		  $$.fval = $1.fval - $3.fval;/*
		  std::string tmp = driver.addGraph(driver.to_string($1) + " - " + driver.to_string($3));
		  driver.setTmpID(tmp);
		  driver.connect(driver.getTmpID(), driver.addGraph($1));
		  driver.connect(driver.getTmpID(), driver.addGraph($3));
		  driver.setTmpID(driver.addGraph($$));
		  driver.connect(driver.getTmpID(), tmp);*/
		}
| exp "*" exp   { //$$ = $1 * $3;

		  $$ = new node($1, $3);
		  $$.fval = $1.fval * $3.fval;/*
		  std::string tmp = driver.addGraph(driver.to_string($1) + " * " + driver.to_string($3));
		  driver.setTmpID(tmp);
		  driver.connect(driver.getTmpID(), driver.addGraph($1));
		  driver.connect(driver.getTmpID(), driver.addGraph($3));
		  driver.setTmpID(driver.addGraph($$));
		  driver.connect(driver.getTmpID(), tmp);*/
		}
| exp "/" exp   { //$$ = $1 / $3;
		  $$ = new node($1, $3);
		  $$.fval = $1.fval / $3.fval;/*
		  std::string tmp = driver.addGraph(driver.to_string($1) + " / " + driver.to_string($3));
		  driver.setTmpID(tmp);
		  driver.connect(driver.getTmpID(), driver.addGraph($1));
		  driver.connect(driver.getTmpID(), driver.addGraph($3));
		  driver.setTmpID(driver.addGraph($$));
		  driver.connect(driver.getTmpID(), tmp);*/
		  }
| "(" exp ")"   { $$ = $2; }
| "identifier"  { //$$ = driver.getVariable($1);
		  if(driver.variables.find($1) == driver.variables.end()){
		    $$ = new node();
		    $$.name = $1;
		  }else{
		    $$ = new node();
		    $$.name = $1;
		    $$.fval = driver.variables[$1];
		  }
                }
| "number"      { //std::swap ($$, $1); 
		  $$ = new node();
		  $$.fval = $1;
		};

sexp:
  sexp "+" sexp {
		  $$ = ((std::string)$1).append($3);
		  std::string tmp = driver.addGraph($1 + " + " + $3);
		  driver.setTmpID(tmp);
		  driver.connect(driver.getTmpID(), driver.addGraph($1));
		  driver.connect(driver.getTmpID(), driver.addGraph($3));
		  driver.setTmpID(driver.addGraph($$));
		  driver.connect(driver.getTmpID(), tmp);
		  }
| "identifier"  { $$ = driver.svar[$1];}
| "text"	{ $$ = $1;};


%%

void
yy::calcxx_parser::error (const location_type& l,
                          const std::string& m)
{
  driver.error (l, m);
}
