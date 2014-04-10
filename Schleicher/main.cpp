#include <iostream>
#include <fstream>
#include <vector>
#include "/home/max/ownCloud/h-da/CB/GoCompiler/Schleicher/include/expression.h"


using namespace std;


void readFromTxt(vector<string> &lines){
    string line;
    ifstream input;
    input.open("../test");
    if (input.is_open()) {
        while (input.good()) {
            getline(input, line);
            if(line.find("//") != -1)
                line = line.substr(0, line.find("//"));
            lines.push_back(line);
        }
        input.close();
    } else
        cout << "Datei nicht gefunden!" << endl;

}       //Zeilenweises einlesen der Datei die zu ueberpruefen ist



void out(vector<string> lines){
    for(unsigned int i = 0; i < lines.size(); i++){
        cout << lines[i] << endl;
    }
}
string ignorSpaces(string str){
    for(int i = 0; i < str.length(); i++){
        if(str[i] == ' '){
            str.erase(i, 1);
        }
    }
    return str;
}

string extractExpression(string text, vector<string> &var){
    text = ignorSpaces(text);
    int place = text.find(":=");
    if(place != -1){
        var.push_back(text.substr(0, place));
        text = text.erase(0, place + 2);
    }
    return text;
}


int main()
{
    vector<string> var;
    vector<string> zeile;
    readFromTxt(zeile);
    for(int i = 0; i < zeile.size(); i++){
        zeile[i] = extractExpression(zeile[i], var);
        expression ex(zeile[i]);
        cout << endl;
    }
    cout << var[0] << endl;
    /*
    string test = "2+2l";
    expression ex(test);
    */
    return 0;
}
