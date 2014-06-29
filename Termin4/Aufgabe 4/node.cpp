#include "node.h"
using namespace llvm;
using namespace std;

node::node(node *leftnode, node *rightnode){
  this->left = leftnode;
  this->right = rightnode;
  inserted = false;
  type = "void";
}

node::node(){
  this->left = NULL;
  this->right = NULL;
  label = sval = type = "";
  fval = 0.0;
  inserted = false;
  type = "void";
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

Value *node::Codegen(Module *TheModule, IRBuilder<> *Builder, std::map<std::string, Value*> &NamedValues){
  bool exists = false;
  string tmp;
  Value *L;
  Value *R;
  if(left != NULL){
    L = left->Codegen(TheModule, Builder, NamedValues);
    //L = left->Codegen();
  }
  if(right != NULL){
    //R = left->Codegen();
    R = right->Codegen(TheModule, Builder, NamedValues);
  }
  size_t found = label.find("Ident: ");
  if(found != string::npos){
	tmp = label.replace(0,((string)("Ident: ")).length(), "");
	if(NamedValues[tmp] != NULL)
	  return NamedValues[tmp];
	else
	  exists = true;
  }

    //std::cout << "Beginne mit den Funktionen" << std::endl;
    if(type == "+") return Builder->CreateFAdd(L, R, "add");
    else if(type == "-") return Builder->CreateFSub(L, R, "sub");
    else if(type == "*") return Builder->CreateFMul(L, R, "mul");
    else if(type == "/") return Builder->CreateFDiv(L, R, "div");

    else if(type == "float" ^ type == "double"){ if(exists)
					NamedValues[tmp] = ConstantFP::get(getGlobalContext(), APFloat(fval));
				 return ConstantFP::get(getGlobalContext(), APFloat(fval));
    }else if(type == "int"){	if(exists)
					NamedValues[tmp] = ConstantInt::get(getGlobalContext(), APInt(32, ival));
				 return ConstantInt::get(getGlobalContext(), APInt(32, ival));
    }else if(type == "char"){ if(exists)
					NamedValues[tmp] = ConstantInt::get(getGlobalContext(), APInt(8, (int)(cval)));
				 return ConstantInt::get(getGlobalContext(), APInt(8, (int)(cval)));
    }else if(type == "string") { if(exists)
		      NamedValues[tmp] = ConstantDataArray::getString(getGlobalContext(), StringRef(sval), true);
		     return ConstantDataArray::getString(getGlobalContext(), StringRef(sval), true);
	//std::cout << "String" << std::endl;
    }else if(type == "function"){
		      //std::cout << "Function Value" << std::endl;
		    	std::vector<Value*> param = split(sval);
			if(param.size() != 0)
				return Builder->CreateCall(TheModule->getFunction(label), param, label);
		  return Builder->CreateCall(TheModule->getFunction(label), label);
    }
      return NULL;

}

std::vector<Value*> node::split(string arr){
	std::vector<Value*> ret;
	stringstream sstr;
	arr.erase(arr.find_last_not_of(" )")+1);
  int pos = arr.find(",");
  while(pos != string::npos){
    //ret.push_back(getValueFor(arr.substr(0, pos)));
    arr = arr.substr(pos+1);
    pos = arr.find(",");
  }
  //ret.push_back(getValueFor(arr));
  cout << "ARR: " << arr << endl;
	/*
	* TO DO: erzeuge eine vector<Value*> aus den übergabeparametern beim funktionscall
	* entweder kann man diese direkt in den NamedValues suchen
	* oder muss die konstanten werte in Value* erzeugen
	*/
	return ret;
}


Value* node::getValueFor(string val){
  if(val.find("\"") != string::npos){
    return NULL;
  }
  else if(val.find("'") != string::npos){
    return NULL;
  }
  return NULL;
}
