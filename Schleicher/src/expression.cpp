#include "../include/expression.h"

expression::~expression()
{
    //ctor
}

expression::expression(string ex){
    vector<string> variablen;
    vector<string> operat;
    int next = findNextOperator(ex);

    cout << "Einlesen" << endl;
    if(next != -1){
        while(next != -1){
            variablen.push_back(ex.substr(0, next));
            operat.push_back(ex.substr(next, 1));
            ex = ex.substr(next + 1, ex.length());
            next = findNextOperator(ex);
        }
        variablen.push_back(ex.substr(0, ex.length()));
        
        //hier die Test ausgaben ob alles erkannt wurde
        for (int i = 0; i < operat.size(); i++){
            cout << variablen[i] << endl;
            cout << operat[i] << endl;
        }
        cout << variablen[variablen.size()-1] << endl;
    }//End if
    //else bedeutet keine Formel oder nur Variablenzuweisung


}

int expression::findNextOperator(string text){
    int nextOp = 0;
    nextOp = text.find('+');
    if (nextOp == -1 || (text.find('-') < nextOp && text.find('-') != -1))
        nextOp = text.find('-');
    if (nextOp == -1 || (text.find('*') < nextOp && text.find('*') != -1))
        nextOp = text.find('*');
    if (nextOp == -1 || (text.find('/') < nextOp && text.find('/') != -1))
        nextOp = text.find('/');
    return nextOp;
}
