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

}



void out(vector<string> lines){
    for(int i = 0; i < lines.size(); i++){
        cout << lines[i] << endl;
    }
}

int main()
{
    /*
    vector<string> zeile;
    readFromTxt(zeile);
    out(zeile);
    */
    string test = "1+2*3/4";
    expression ex(test);



    return 0;
}
