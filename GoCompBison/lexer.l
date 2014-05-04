%{
	#include <iostream>
	#include "Expression.h"
	using namespace std;
	int yylval = 0;
	/*Definition der mainfesten Konstanten*/
%}

/*reguläre Definitionen*/
LPAREN		"("
RPAREN		")"
PLUS		"+"
MINUS		"-"
MULTIPLY	"*"
DIVIDE		"/"
delim [ \t\n]
ws {delim}+
letter [A-Za-z]
digit [0-9]
id {letter}({letter}|{digit})*
number {digit}+(\.{digit}+)?(E[+-]?{digit}+)?

%%

{ws}		{}
{PLUS} 		{return PLUS;}
{MINUS}		{return MINUS;}
{MULTIPLY}	{return MULTIPLY;}
{DIVIDE}	{return DIVIDE;}
{id}	 	{yylval = (int) installID(); return(ID);}
{number} 	{yylval = (int) installNum(); return(NUMBER);}
.		{}

%%

int installID(){
	sscanf(yytext, "%d", &yylval->value);
	return NUMBER;
}

int yyerror(const char* msg){
	fprintf(stderr, "Error:%s\n", msg);
	return 0;
}
