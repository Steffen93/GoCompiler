#include "function.h"

function::function():name(""), returnType("void"), nodes(vector<node*>()), returnExp(NULL), parameters(map<string,string>()){}

function::function(string _name, string _returnType):name(_name), returnExp(NULL), returnType(_returnType){
  nodes = vector<node*>();
  /*node* curr;
  int pos = paramList.find(",");
  string type = "void";
  string currPair = "";
  while(pos != string::npos){
    currPair = paramList.substr(0, pos);
    splitTypeFromName(currPair, type);
    curr = new node();
    cout << "Label: " << currPair << endl;
    curr->label = currPair;
    cout << "Type: " << type << endl;
    curr->type = type;
    nodes.push_back(curr);
    parameters[paramList.substr(0, pos)] = type;
    paramList = paramList.substr(pos+1);
    pos = paramList.find(",");
  }
  splitTypeFromName(paramList, type);
  curr = new node();
  curr->label = paramList;
  curr->type = type;
  nodes.push_back(curr);
  parameters[paramList] = type;*/
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

  for(int i = 0; i < nodes.size(); i++){
    Builder->CreateRet(nodes.at(i)->Codegen(TheModule, Builder, Values));	//übergabe der kopierten Map
  }
  F->dump();
}

node* function::getNode(string label){
  for(int i = 0; i < nodes.size(); i++){
      if(nodes.at(i)->label == label){
        return nodes.at(i);
      }
  }
  return NULL;
}
