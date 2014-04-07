#include "../include/expression.h"

expression::~expression()
{
    //ctor
}
expression::expression()
{
    //ctor
}

expression::expression(string ex){
    ex = ignorSpaces(ex);
    string ohneklammer = trennKlammern(ex);
    //cout << ohneklammer <<  "|" << endl;
    int index;
    if(ohneklammer != ex){
        expression tmp(ohneklammer);
        stringstream sstr;
        sstr << tmp.getValue();
        string val = sstr.str();

        index = ex.find(ohneklammer) - 1;
        ex.replace(index, ohneklammer.length() + 2, val);
    }

    cout << ex;
    ini(ex);

}

double expression::getValue(){
    return value;
}

string expression::ignorSpaces(string str){
    for(int i = 0; i < str.length(); i++){
        if(str[i] == ' '){
            str.erase(i, 1);
        }
    }
    return str;
}

void expression::ini(string ex){
    vector<string> variablen;
    vector<string> operat;
    string var, op;


    int len;
    int next = findNextOperator(ex, len);

    if(next != -1){
        while(next != -1){
            variablen.push_back(ex.substr(0, next));
            operat.push_back(ex.substr(next, len));
            ex = ex.substr(next + len, ex.length());
            next = findNextOperator(ex, len);
        }
        variablen.push_back(ex.substr(0, ex.length()));

    }else{
        variablen.push_back(ex);
        cout << endl;
    }//End if
    //else bedeutet keine Formel oder nur Variablenzuweisung


    for(int i = 0; i < operat.size(); i++){
        operatoren.push_back(operatorenID(operat[i]));
    }
    fillOperanden(variablen);
    calculate();
}

string expression::trennKlammern(const string ex){
    int cnt = 0;
    int len = 0;
    string substring = ex;
    for(int i = 0; i < ex.length(); i++){
        if(ex[i] == '('){
            cnt++;
        }else if(ex[i] == ')'){
            cnt--;
            if (cnt == 0){
                len++;
                substring = ex.substr(ex.find('(') + 1, len - 2);
                if(cnt != 0)
                    substring = "";
                    return substring;
            }
        }

        if(cnt > 0)
            len++;
    }
    return substring;
}

void expression::fillOperanden(vector<string> &sOperand){
    int itmp;
    double dtmp;
    for(unsigned int i; i < sOperand.size(); i++){
        try{
            dtmp = stringToDouble(sOperand[i]);
            itmp = (int) dtmp;
            if(itmp == dtmp){
                operanden.push_back(itmp);
            }else{
                operanden.push_back(dtmp);
            }
        }catch(...){
            //cout << endl << sOperand[i] << " ist keine Zahl!" << endl;
        }
    }
}

double expression::stringToDouble(string s){
    bool strOK = true;
    if(s == "pi"){
        return 3.14159; //wusste nicht auswendig wie ich PI bekomme
    }else if(s == "e"){
        return 2.71828; //für e das gleiche
    }
    for(int i = 0; i < s.size(); i++){
        if(s[i] != '0' && s[i] != '1' && s[i] != '2' && s[i] != '3' && s[i] != '4' && s[i] != '5' && s[i] != '6' && s[i] != '7' && s[i] != '8' && s[i] != '9' && s[i] != '.' && s[i] != '\0')
        strOK = false;
    }
    if(strOK){
        stringstream sstr(s);
        double value;
        if(!(sstr >> value))
            strOK == strOK;
        else
            return value;
    }else{
        cout << s << " ist keine Zahl" << endl;
    }
}

int expression::operatorenID(string op){
        if(op == "+")
            return 0;
        else if(op == "-")
            return 1;
        else if(op == "*")
            return 2;
        else if(op == "/")
            return 3;
        else if (op == "<<")
            return 4;
        else if(op == ">>")
            return 5;
        else
            return -1;
}       //uebersetzung der strings "+", "-", etc in nummaerische IDs zur einfacheren verwendung spaeter (switch geht nur mit int)

void expression::calculate(){
    int a, b;
    value = operanden[0];
    if(!operatoren.empty() && operanden.size() > 1)
    for(int i = operatoren.size() - 1; i >= 0; i--){
        switch(operatoren[i]){
            case 0:
                operanden[i] += operanden[i + 1];
                operanden.pop_back();
                break;
            case 1:
                operanden[i] -= operanden[i + 1];
                operanden.pop_back();
                break;
            case 2:
                operanden[i] *= operanden[i + 1];
                operanden.pop_back();
                break;
            case 3:
                operanden[i] /= operanden[i + 1];
                operanden.pop_back();
                break;
            case 4:
                a = (int)operanden[i];
                b = (int) operanden[i + 1];
                operanden[i] = a << b;
                operanden.pop_back();
                break;
            case 5:
                a = (int)operanden[i];
                b = (int) operanden[i + 1];
                operanden.pop_back();
                operanden[i] = a >> b;
        }
    }
    value = operanden[0];
    cout << " = " << value << endl;
}   //verrechne die Operanden über der Operatoren.

int expression::findNextOperator(string text, int &len){


    int nextOp = 0;
    nextOp = text.find('+');
    len = 1;
    if (nextOp == -1 || (text.find('-') < nextOp && text.find('-') != -1))
        nextOp = text.find('-');
    if (nextOp == -1 || (text.find('*') < nextOp && text.find('*') != -1))
        nextOp = text.find('*');
    if (nextOp == -1 || (text.find('/') < nextOp && text.find('/') != -1))
        nextOp = text.find('/');
    if (nextOp == -1 || (text.find("<<") < nextOp && text.find("<<") != -1)){
        nextOp = text.find("<<");
        len = 2;
    }
    if (nextOp == -1 || (text.find(">>") < nextOp && text.find(">>") != -1)){
        nextOp = text.find(">>");
        len = 2;
    }

    return nextOp;
}       //finde den naechsten Operator nach dem getrennt werden soll
