#include "function.h"

function::function():name(""), returnType("void"), nodes(vector<node*>()), returnExp(NULL), parameters(map<string,string>()){}

function::function(string _name, string _returnType):name(_name), returnExp(NULL), returnType(_returnType){
  nodes = vector<node*>();
}

void function::splitTypeFromName(string &name, string &type){
  int pos = name.find(" ");
  if(pos != string::npos){
    type = name.substr(pos+1);
    name = name.substr(0, pos);
  }
}

void function::Codegen(Module *TheModule, IRBuilder<> *Builder, std::map<std::string, Value*> &NamedValues){
  std::map<std::string, Value*> Values;		//Neue Map Damit die Nodes innerhalb der Funktion nicht in die NamedValues kommen
  Values.insert(NamedValues.begin(), NamedValues.end());
  vector<Type*> params = vector<Type*>();
  for(map<string,string>::iterator it = parameters.begin(); it != parameters.end(); ++it){
    params.push_back(getTypeFor(it->second));
  }
  FunctionType* FT = FunctionType::get(getTypeFor(returnType),
                                     params, false);
  Function* F = Function::Create(FT, Function::ExternalLinkage, name, TheModule);
  BasicBlock *BB = BasicBlock::Create(getGlobalContext(), "entry", F);
  Builder->SetInsertPoint(BB);

  //for(int i = 0; i < nodes.size(); i++){
  //  Builder->CreateRet(nodes.at(i)->Codegen(TheModule, Builder, Values));	//übergabe der kopierten Map
  //}
  for(map<string, node*>::iterator it = variables.begin(); it != variables.end(); ++it){
    Builder->CreateRet(it->second->Codegen(TheModule, Builder, Values));	//übergabe der kopierten Map
  }
  F->dump();
}

node* function::getNode(string label){
  string prefix = "Ident: ";
  label = label.substr(label.find(prefix)+prefix.length());
  //vom Label das Ident: abschneiden!
  if(variables.find(label) != variables.end()){
    return variables[label];
  }
  else{
    cout << "function::getNode(): Node '" << label <<"' not found!" << endl;
    printVariables();
    return NULL;
  }
}

void function::printVariables(){
  cout << "Variables dump:" << endl;
  int count = 0;
  for(map<string, node*>::iterator it = variables.begin(); it != variables.end(); ++it){
    count++;
    cout << "variables [" << it->first << "] = " << it->second->fval << endl;
  }
  cout << "Count: " << count << endl;
  cout << endl;
}
