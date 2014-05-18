#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <cmath>

#ifndef EXPRESSION_H
#define EXPRESSION_H

using namespace std;

//template<class T>
class expression {
	public:
		//expression();
		expression();
		expression(string ex);
		virtual ~expression();


		size_t findNextOperator(string text, int &len);

		int operatorenID(string op);

		void fillOperanden(vector<string> &sOperand);

		double getValue();

	protected:
	private:
		/*
		Modelierung auf Umgekehrt polnische Notation aus mehreren Gründen:
		    einfacher weil roperand nicht mehr Wert ODER Expression
		    Klammern total einfach => wenn '(' nach '*' oder '/' zeichen auf den Operator stapel
		        sonst direkt verrechnen der Zahlen
		Value entspricht dem werd der gegebenen Zeile => wird später durch die Variable vor '=' ersetzt oder setzt diese
		*/
		string trennKlammern(const string ex);

		//string ignoreSpaces(string str);
		double stringToDouble(string s);

		void ini(string ex);
		void calculate();

		vector<double>operanden;
		vector<int> operatoren;     //+ => 0; - => 1; * => 2; / => 3;
		int klammerCounter;
		double value;                    //Ergebnis der Expressin (Zeile);

		string op;      //operator

		static const double PI = 3.141592653;
		static const double e =  2.718281828;

};

#endif // EXPRESSIONH
