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

%token <std::string> IDENTIFIER "identifier"
%token <float> NUMBER "number"
%token <std::string> TEXT "text"
%type  <float> exp
%type  <std::string> sexp

%printer { yyoutput << $$; } <*>;

%%
%start unit;
unit: assignments exp  { driver.result = $2; }
| assignments sexp {driver.erg = $2;};

assignments:
  %empty                 {}
| assignments assignment {};

assignment:
  "identifier" ":=" exp { driver.variables[$1] = $3; driver.addGraph($1, $3);
			  driver.printLine($1 + " = "  + driver.to_string($3));
			  //std::cout << $1 << " = " << $3 << std::endl;
			}
  | "identifier" ":=" sexp {
				driver.svar[$1] = (string) $3;// std::cout << $1 << " = " << $3 << std::endl;
				driver.printLine($1 + " = "  + $3);
			   };

%left "+" "-";
%left "*" "/";
exp:
  exp "+" exp   { $$ = $1 + $3;
		  std::string tmp = driver.addGraph(std::to_string($1) + " + " + std::to_string($3));
		  driver.setTmpID(tmp);
		  driver.connect(driver.getTmpID(), driver.addGraph($1));
		  driver.connect(driver.getTmpID(), driver.addGraph($3));
		  driver.setTmpID(driver.addGraph($$));
		  driver.connect(driver.getTmpID(), tmp);
//		  driver.printLine(driver.to_string($$) + " = "  + driver.to_string($1) + " + " + driver.to_string($3));
//		  std::cout << $$ << " = " << $1 << " + " << $3 << std::endl;
		  }
| exp "-" exp   { $$ = $1 - $3;
		  std::string tmp = driver.addGraph(driver.to_string($1) + " - " + driver.to_string($3));
		  driver.setTmpID(tmp);
		  driver.connect(driver.getTmpID(), driver.addGraph($1));
		  driver.connect(driver.getTmpID(), driver.addGraph($3));
		  driver.setTmpID(driver.addGraph($$));
		  driver.connect(driver.getTmpID(), tmp);
//		  driver.printLine(driver.to_string($$) + " = "  + driver.to_string($1) + " - " + driver.to_string($3));
//		  std::cout << $$ << " = " << $1 << " - " << $3 << std::endl;
		}
| exp "*" exp   { $$ = $1 * $3;
		  std::string tmp = driver.addGraph(driver.to_string($1) + " * " + driver.to_string($3));
		  driver.setTmpID(tmp);
		  driver.connect(driver.getTmpID(), driver.addGraph($1));
		  driver.connect(driver.getTmpID(), driver.addGraph($3));
		  driver.setTmpID(driver.addGraph($$));
		  driver.connect(driver.getTmpID(), tmp);
//		  driver.printLine(driver.to_string($$) + " = "  + driver.to_string($1) + " * " + driver.to_string($3));
//		  std::cout << $$ << " = " << $1 << " * " << $3 << std::endl;
		}
| exp "/" exp   { $$ = $1 / $3;
		  std::string tmp = driver.addGraph(driver.to_string($1) + " / " + driver.to_string($3));
		  driver.setTmpID(tmp);
		  driver.connect(driver.getTmpID(), driver.addGraph($1));
		  driver.connect(driver.getTmpID(), driver.addGraph($3));
		  driver.setTmpID(driver.addGraph($$));
		  driver.connect(driver.getTmpID(), tmp);
//		  driver.printLine(driver.to_string($$) + " = "  + driver.to_string($1) + " / " + driver.to_string($3));
//		  std::cout << $$ << " = " << $1 << " / " << $3 << std::endl;
		  }
| "(" exp ")"   { std::swap ($$, $2); }
| "identifier"  { $$ = driver.getVariable($1);
		  //cout << endl << $1 << " = " << $$ << endl;
                  driver.printLine($1 + " = " + driver.to_string($$));
                }
| "number"      { std::swap ($$, $1); };

sexp:
  sexp "+" sexp {
		  $$ = ((std::string)$1).append($3);
		  std::string tmp = driver.addGraph($1 + " + " + $3);
		  driver.setTmpID(tmp);
		  driver.connect(driver.getTmpID(), driver.addGraph($1));
		  driver.connect(driver.getTmpID(), driver.addGraph($3));
		  driver.setTmpID(driver.addGraph($$));
		  driver.connect(driver.getTmpID(), tmp);
		  //driver.printLine($1 + " = "  + $3);
//		  std::cout << $$  << " = \"" << $1 << "\" + \"" << $3 << "\"" << std::endl;
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
