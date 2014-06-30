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
  this->llvmValue = copy->llvmValue;
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
  	tmp = label.substr(string("Ident: ").length()+1);
  	if(NamedValues[tmp] != NULL)
  	  return NamedValues[tmp];
  	else
  	  exists = true;
  }

    //std::cout << "Beginne mit den Funktionen" << std::endl;
    if(left != NULL && right != NULL){
      if(type == "+") {
        cout << "Operator plus found!" << endl;
        llvmValue = Builder->CreateBinOp(Instruction::Add, L, R, "addResult");
        return llvmValue;
        //return Builder->CreateFAdd(L, R, "add");
      }
      else if(type == "-") {
        cout << "Operator minus found!" << endl;
        llvmValue = Builder->CreateBinOp(Instruction::Sub, L, R, "subResult");
        return llvmValue;
        //return Builder->CreateFSub(L, R, "sub");
      }
      else if(type == "*") {
        cout << "Operator mult found!" << endl;
        llvmValue = Builder->CreateBinOp(Instruction::Mul, L, R, "mulResult");
        return llvmValue;
        //return Builder->CreateFMul(L, R, "mul");
      }
      else if(type == "/") {
        cout << "Operator div found!" << endl;
        //llvmValue = Builder->CreateBinOp(Instruction::fDiv, left->llvmValue, right->llvmValue, "divResult");
        return Builder->CreateFDiv(L, R, "div");
      }
    }
    if(type == "float"){ if(exists)
				 NamedValues[tmp] = ConstantFP::get(getGlobalContext(), APFloat(fval));
         llvmValue = ConstantFP::get(getGlobalContext(), APFloat(fval));
				 return ConstantFP::get(getGlobalContext(), APFloat(fval));
    }else if(type == "int"){	if(exists)
					NamedValues[tmp] = ConstantInt::get(getGlobalContext(), APInt(32, ival));
         llvmValue = ConstantInt::get(getGlobalContext(), APInt(32, ival));
				 return ConstantInt::get(getGlobalContext(), APInt(32, ival));
    }else if(type == "char"){ if(exists)
					NamedValues[tmp] = ConstantInt::get(getGlobalContext(), APInt(8, (int)(cval)));
         llvmValue = ConstantInt::get(getGlobalContext(), APInt(8, (int)(cval)));
        return ConstantInt::get(getGlobalContext(), APInt(8, (int)(cval)));
    }else if(type == "string") { if(exists)
		      NamedValues[tmp] = ConstantDataArray::getString(getGlobalContext(), StringRef(sval), true);
          llvmValue = ConstantDataArray::getString(getGlobalContext(), StringRef(sval), true);
		     return ConstantDataArray::getString(getGlobalContext(), StringRef(sval), true);
	//std::cout << "String" << std::endl;
    }else if(type == "function"){
          cout << "Function call found!" << endl;
		    	std::vector<Value*> param = split(sval);
			if(param.size() != 0)
				return Builder->CreateCall(TheModule->getFunction(label), param, label);
		  return Builder->CreateCall(TheModule->getFunction(label), label);
    }
      return NULL;
}

std::vector<Value*> node::split(string arr){
	std::vector<Value*> ret;
	arr.erase(arr.find_last_not_of(" )")+1);
  int pos = arr.find(",");
  while(pos != string::npos){
    ret.push_back(getValueFor(arr.substr(0, pos)));
    arr = arr.substr(pos+1);
    pos = arr.find(",");
  }
  ret.push_back(getValueFor(arr));
  cout << "ARR: " << arr << endl;
	return ret;
}


Value* node::getValueFor(string val){
  stringstream sstr(val);
  int i;
  float f;
  if(val.find("\"") != string::npos){
    return NULL;
  }
  else if(val.find("'") != string::npos){
    return NULL;
  }
  if(val.find(".") != string::npos){
    sstr >> f;
    return ConstantFP::get(getGlobalContext(), APFloat(f));
  }else{
    sstr >> i;
    return ConstantInt::get(getGlobalContext(), APInt(32, ival));
  }
  return NULL;
}

bool node::compareTo(string token, node* other){
  if(token == "<"){
    if(type=="int" && other->type == "int"){
      return ival < other->ival;
    }
    if(type=="float" && other->type == "float"){
      return fval < other->fval;
    }
  }
  if(token == ">"){
    if(type=="int" && other->type == "int"){
      return ival > other->ival;
    }
    if(type=="float" && other->type == "float"){
      return fval > other->fval;
    }
  }
  if(token == "=="){
    if(type=="int" && other->type == "int"){
      return ival == other->ival;
    }
    if(type=="float" && other->type == "float"){
      return fval == other->fval;
    }
  }
  if(token == "!="){
    if(type=="int" && other->type == "int"){
      return ival != other->ival;
    }
    if(type=="float" && other->type == "float"){
      return fval != other->fval;
    }
  }
  return false;
}
