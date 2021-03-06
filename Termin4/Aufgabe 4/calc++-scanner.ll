/***********************
 * Example of C++ in Bison (yacc)
 * Compare Bison Manual, Section 10.1.6 A Complete C++ Example
 * https://www.gnu.org/software/bison/manual/html_node/A-Complete-C_002b_002b-Example.html
 * The Makefile has been simplified radically, but otherwise
 * everything here comes from the Bison source code (see also).
 * (This comment added by Prof. R. C. Moore, fbi.h-da.de)
 *
 * This is the (f)lex file, i.e. token definitions
 * See also calc++-parser.yy for the parser (grammar)
 * (yacc/bison input).
 *
 ***********************/

%{ /* -*- C++ -*- */
# include <cerrno>
# include <climits>
# include <cstdlib>
# include <string>
# include "node.h"
# include "calc++-driver.hh"

# include "calc++-parser.hh"

// Work around an incompatibility in flex (at least versions
// 2.5.31 through 2.5.33): it generates code that does
// not conform to C89.  See Debian bug 333231
// <http://bugs.debian.org/cgi-bin/bugreport.cgi?bug=333231>.
# undef yywrap
# define yywrap() 1

// The location of the current token.
static yy::location loc;
%}
%option noyywrap nounput batch debug noinput

comment		"//".*
id    		[a-zA-Z][a-zA-Z_0-9]*
zahl   		[0-9]+
sign 		"'"[a-zA-Z0-9]"'"
number 		{zahl}+\.{zahl}*
text 		"\""[a-zA-Z0-9 !$%&/()=?;:-_]*"\""
blank 		[ \t]
funccall	{id}"("(({id}|{text}|{sign}|{zahl}|{number})+[","{id}|{text}|{sign}|{zahl}|{number}]*|^a)")"
logop     ["&&"|"||"]
compareto "=="|"<"|">"|"!="
block     "{"[^\}]*"}"

%{
  // funccall	{id}"("(({id}|{text}|{sign}|{zahl}|{number})+[","{id}|{text}|{sign}|{zahl}|{number}]*|^a)")"
  // Code run each time a pattern is matched.
  # define YY_USER_ACTION  loc.columns (yyleng);
%}

%%

%{
  // Code run each time yylex is called.
  loc.step ();
%}
{comment}+ loc.lines (yyleng); loc.step();
{blank}+   loc.step ();
[\n]+      loc.lines (yyleng); loc.step ();
"-"      return yy::calcxx_parser::make_MINUS(loc);
"+"      return yy::calcxx_parser::make_PLUS(loc);
"*"      return yy::calcxx_parser::make_STAR(loc);
"/"      return yy::calcxx_parser::make_SLASH(loc);
"("      return yy::calcxx_parser::make_LPAREN(loc);
")"      return yy::calcxx_parser::make_RPAREN(loc);
"{"      return yy::calcxx_parser::make_LBRACK(loc);
"}"      return yy::calcxx_parser::make_RBRACK(loc);
","      return yy::calcxx_parser::make_COMMA(loc);
":="     return yy::calcxx_parser::make_ASSIGN(loc);
"func"   return yy::calcxx_parser::make_FUNCTION(loc);
"return" return yy::calcxx_parser::make_RETURN(loc);
"if"     return yy::calcxx_parser::make_IF(loc);
"else"   return yy::calcxx_parser::make_ELSE(loc);
"!"      return yy::calcxx_parser::make_NOT(loc);

{compareto} {
  return yy::calcxx_parser::make_COMPARETO(yytext,loc);
}

{logop} {
  return yy::calcxx_parser::make_LOGOP(yytext,loc);
}

{number}	{
  errno = 0;
  float n = strtof (yytext, NULL);
  return yy::calcxx_parser::make_NUMBER(n, loc);
}

{sign}		{
  std::string tmp = yytext;
  char c = tmp[1];
  return yy::calcxx_parser::make_SIGN(c, loc);
}

{zahl}		{
  int zahl = std::atoi(yytext);
  return yy::calcxx_parser::make_ZAHL(zahl, loc);
}

{text}		{
  std::string tmp = yytext;
  tmp = tmp.erase(0,1);
  tmp = tmp.erase(tmp.length() -1, 1);
  return yy::calcxx_parser::make_TEXT(tmp, loc);
}

{funccall} {return yy::calcxx_parser::make_FUNCCALL(yytext, loc);}

{id}       {return yy::calcxx_parser::make_IDENTIFIER(yytext, loc);}

          driver.error (loc, "invalid character");
<<EOF>>    return yy::calcxx_parser::make_END(loc);
%%

void
calcxx_driver::scan_begin ()
{
  yy_flex_debug = trace_scanning;
  if (file.empty () || file == "-")
    yyin = stdin;
  else if (!(yyin = fopen (file.c_str (), "r")))
    {
      error ("cannot open " + file + ": " + strerror(errno));
      exit (EXIT_FAILURE);
    }
}



void
calcxx_driver::scan_end ()
{
  fclose (yyin);
}
