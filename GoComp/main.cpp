#include <iostream>
#include <fstream>
#include <vector>
#include "include/Expression.h"
#include "include/Parser.h"
#include "include/Lexer.h"
#include <stdio.h>

using namespace std;

int yyparse(SExpression **expression, yyscan_t scanner);
int yyerror(const char *msg);

SExpression *getAST(const char *expr)
{
    SExpression *expression;
    yyscan_t scanner;
    YY_BUFFER_STATE state;

    if (yylex_init(&scanner)) {
        // couldn't initialize
        yyerror("Could not Initialize");
        return NULL;
    }

    state = yy_scan_string(expr, scanner);

    if (yyparse(&expression, scanner)) {
        // error parsing
        yyerror(expr);
        return NULL;
    }

    yy_delete_buffer(state, scanner);

    yylex_destroy(scanner);

    return expression;
}

int evaluate(SExpression *e)
{
    switch (e->type) {
        case eVALUE:
            return e->value;
        case eMULTIPLY:
            return evaluate(e->left) * evaluate(e->right);
        case eDEVIDE:
            return evaluate(e->left) / evaluate(e->right);
        case ePLUS:
            return evaluate(e->left) + evaluate(e->right);
        case eMINUS:
            return evaluate(e->left) - evaluate(e->right);
        default:
            // shouldn't be here
            return 0;
    }
}

void readFromTxt(vector<string> &lines) {
	string line;
	ifstream input;
	input.open("../test");
	if (input.is_open()) {
		while (input.good()) {
			getline(input, line);
			if(line.find("//") != string::npos){
				line = line.substr(0, line.find("//"));
            }
			lines.push_back(line);
		}
		input.close();
	} else{
		cout << "Datei nicht gefunden!" << endl;
    }
}       //Zeilenweises einlesen der Datei die zu ueberpruefen ist

void out(vector<string> lines) {
	for(unsigned int i = 0; i < lines.size(); i++) {
		cout << lines[i] << endl;
	}
}

string ignoreSpaces(string str) {
	for(unsigned int i = 0; i < str.length(); i++) {
		if(str[i] == ' ') {
			str.erase(i, 1);
		}
	}
	return str;
}

string extractExpression(string text, vector<string> &var) {
	text = ignoreSpaces(text);
	size_t place = text.find(":=");
	if(place != string::npos) {
		var.push_back(text.substr(0, place));
		text = text.erase(0, place + 2);
	}
	return text;
}


int main() {
    cout << "Start" << endl;
	vector<string> var;
	vector<string> zeile;
	readFromTxt(zeile);
	SExpression *e;
	for(unsigned int i = 0; i < zeile.size(); i++) {
		zeile[i] = extractExpression(zeile[i], var);
		e = getAST(((char*)zeile[i].c_str()));
		if(e != NULL)
            cout << zeile[i] << " = " << evaluate(e) << endl;
	}
	//cout << var[0] << endl;
	return 0;
}
