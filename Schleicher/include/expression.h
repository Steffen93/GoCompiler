#include <vector>
#include <string>
#include <iostream>

#ifndef EXPRESSION_H
#define EXPRESSION_H

using namespace std;

//template<class T>
class expression
{
    public:
        //expression();

        expression(string ex);
        virtual ~expression();


        int findNextOperator(string text);

    protected:
    private:
        /*
        Modelierung auf Umgekehrt polnische Notation aus mehreren Gründen:
            einfacher weil roperand nicht mehr Wert ODER Expression
            Klammern total einfach => wenn '(' nach '*' oder '/' zeichen auf den Operator stapel
                sonst direkt verrechnen der Zahlen
        Value entspricht dem werd der gegebenen Zeile => wird später durch die Variable vor '=' ersetzt oder setzt diese
        */
        vector<int>operanden;
        vector<int> operatoren;     //+ => 0; - => 1; * => 2; / => 3;
        int klammerCounter;
        int value;                    //Ergebnis der Expressin (Zeile);

        string op;      //operator

};

#endif // EXPRESSIONH
