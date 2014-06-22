#include "node.h"
using namespace llvm;

node::node(node *leftnode, node *rightnode){
  this->left = leftnode;
  this->right = rightnode;
  inserted = false;
}

node::node(){
  this->left = NULL;
  this->right = NULL;
  label = sval = type = "";
  fval = 0.0;
  inserted = false;
}

node::node(node* copy){
  this->left = copy->left;
  this->right = copy->right;
  this->label = copy->label;
  this->fval = copy->fval;
  this->sval = copy->sval;
  this->ival = copy->ival;
  this->cval = copy->cval;
  this->type = copy->type;
  inserted = false;
}

node::~node(){
  if(left != NULL)
    left->~node();
  if(right != NULL)
    right->~node();
}

void node::makeGraph(ofstream &o){
  if(inserted == false){
    if(label != "")
      o<< "node" << (intptr_t)this << "[label=\"" << label << "\"];\n";
    else
      return;
    if(left != NULL){
      left->makeGraph(o);
      o << "node" << (intptr_t)left  << " -> " << "node" << (intptr_t)this<< "\n";
    }
    if(right != NULL){
      right->makeGraph(o);
      o << "node" << (intptr_t)right << " -> " << "node" << (intptr_t)this << "\n";
    }
    inserted = true;
  }
}

Value *node::Codegen(Module *TheModule, static IRBuilder<> Builder, std::map<std::string, Value*> &NamedValues){
  bool exists = false;
  string tmp;
  if(left != NULL)
    Value *L = left->Codegen(TheModule, Builder, NamedValues);
  if(right != NULL)
	Value *R = right->Codegen(TheModule, Builder, NamedValues);
  size_t found = label.find("Ident: ");
  if(found != string::npos){
	tmp = label.replace(0,"Ident: ".length(), "");
	if(NamedValues[tmp] != NULL;)
	  return NamedValues[tmp];
	else
	  exists = true;
  }
    
  switch(type){
    case "+": return Builder.CreateFAdd(L, R, "add");
    case "-": return Builder.CreateFSub(L, R, "sub");
    case "*": return Builder.CreateFMul(L, R, "mul");
    case "/": return Builder.CreateFDiv(l, R, "div");
    
    case "float": if(exists)
					NamedValues[tmp] = ConstantFP::get(getGlobalContext(), APFloat(fval));
				  return ConstantFP::get(getGlobalContext(), APFloat(fval));
    case "int":	if(exists)
					NamedValues[tmp] = ConstantInt::get(getGlobalContext(), APInt(ival));
				return ConstantInt::get(getGlobalContext(), APInt(ival));
    case "char": if(exists)
					NamedValues[tmp] = ConstantInt::get(getGlobalContext(), APInt((int)(cval)); 
				 return ConstantInt::get(getGlobalContext(), APInt((int)(cval)); 
    case "string": std::cout << "String" << std::endl;
    default:
      return ErrorV("invalid binary operator");
  }
}
