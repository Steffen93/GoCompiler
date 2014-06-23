#include "node.h"
using namespace llvm;
using namespace std;

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

Value *node::Codegen(Module *TheModule, IRBuilder<> Builder, std::map<std::string, Value*> &NamedValues){
  bool exists = false;
  string tmp;
  Value *L;
  Value *R;
  if(left != NULL){
    L = left->Codegen(TheModule, Builder, NamedValues);
  }
  if(right != NULL)
    R = right->Codegen(TheModule, Builder, NamedValues);
  size_t found = label.find("Ident: ");
  if(found != string::npos){
	tmp = label.replace(0,((string)("Ident: ")).length(), "");
	if(NamedValues[tmp] != NULL)
	  return NamedValues[tmp];
	else
	  exists = true;
  }
    //std::cout << "Beginne mit den Funktionen" << std::endl;
    if(type == "+") return Builder.CreateFAdd(L, R, "add");
    else if(type == "-") return Builder.CreateFSub(L, R, "sub");
    else if(type == "*") return Builder.CreateFMul(L, R, "mul");
    else if(type == "/") return Builder.CreateFDiv(L, R, "div");
    
    else if(type == "float"){ if(exists)
					NamedValues[tmp] = ConstantFP::get(getGlobalContext(), APFloat(fval));
				  return ConstantFP::get(getGlobalContext(), APFloat(fval));
    }else if(type == "int"){	if(exists)
					NamedValues[tmp] = ConstantInt::get(getGlobalContext(), APInt(32, ival));
				return ConstantInt::get(getGlobalContext(), APInt(32, ival));
    }else if(type == "char"){ if(exists)
					NamedValues[tmp] = ConstantInt::get(getGlobalContext(), APInt(8, (int)(cval))); 
				 return ConstantInt::get(getGlobalContext(), APInt(8, (int)(cval))); 
    }else if(type == "string") std::cout << "String" << std::endl;
    
      return NULL;
    
}
