#include "calc++-driver.hh"
#include "calc++-parser.hh"

int calcxx_driver::nodeCount = 0;
Module *calcxx_driver::TheModule;
IRBuilder<> *calcxx_driver::Builder;
std::map<std::string, Value*> calcxx_driver::NamedValues;

calcxx_driver::calcxx_driver ()
  : trace_scanning (false), trace_parsing (false), tmpID(""), testMode(false)
{
  result = vector<node*>();
  o.open("dotgraph.dot");
  o << "digraph gograph{\n";
  tS.open("tests.txt");
}

calcxx_driver::~calcxx_driver ()
{
  std::cout << "Number of results: " << result.size() << std::endl;
//  root->makeGraph(o);
  LLVMContext &Context = getGlobalContext();
  // Make the module, which holds all the code.
  TheModule = new Module("GO", Context);
  Builder = new IRBuilder<>(getGlobalContext());
//Test stuff
  vector<Type*> Doubles(0, Type::getDoubleTy(getGlobalContext()));
  FunctionType* FT = FunctionType::get(Type::getDoubleTy(getGlobalContext()),
                                       vector<Type*>(), false);
  Function* F = Function::Create(FT, Function::ExternalLinkage, "test123", TheModule);
  BasicBlock *BB = BasicBlock::Create(getGlobalContext(), "entry", F);
  Builder->SetInsertPoint(BB);
//**Test stuff
  //gehe den baum durch und erzeuge den Zwischcode
  for(int i = 0; i < result.size(); i++){
  	if(result.at(i) != NULL){
  		Builder->CreateRet(result.at(i)->Codegen(this->TheModule, this->Builder, this->NamedValues));
  	}
  }

  //Gebe den Zwischencode aus
  TheModule->dump();

  //Immernoch den Graphen erzeugen
  for(int i = 0; i < result.size(); i++){
	if(result.at(i) != NULL){
		result.at(i)->makeGraph(o);
	}
  }
  o << "\n}";
  tS << std::endl;
  o.close();
  tS.close();
}

void calcxx_driver::makeCode(){
  LLVMContext &Context = getGlobalContext();
  // Make the module, which holds all the code.
  TheModule = new Module("GO", Context);

  //gehe den baum durch und erzeuge den Zwischcode
  for(int i = 0; i < result.size(); i++){
	if(result.at(i) != NULL){
		if(result.at(i)->type == "float"){
		  std::cout << "\nFloat\n" << std::endl;
		  FunctionType *FT = FunctionType::get(Type::getDoubleTy(getGlobalContext()), false);
		  Function *F = Function::Create(FT, Function::ExternalLinkage, "", TheModule);

		  BasicBlock *BB = BasicBlock::Create(getGlobalContext(), "entry", F);
		  Builder->SetInsertPoint(BB);
		  Builder->CreateRet(result.at(i)->Codegen(this->TheModule, this->Builder, this->NamedValues));
		  TheModule->dump();

		}else if(result.at(i)->type == "int"){
		  std::cout << "\nInteger\n" << std::endl;
		  FunctionType *FT = FunctionType::get(Type::getFloatTy(getGlobalContext()), false);
		  Function *F = Function::Create(FT, Function::ExternalLinkage, "", TheModule);

		  BasicBlock *BB = BasicBlock::Create(getGlobalContext(), "entry", F);
		  Builder->SetInsertPoint(BB);
		  Builder->CreateRet(result.at(i)->Codegen(this->TheModule, this->Builder, this->NamedValues));
		  TheModule->dump();
		}


	}
  }



}

float
calcxx_driver::parse (const std::string &f)
{
  file = f;
  scan_begin ();
  yy::calcxx_parser parser (*this);
  parser.set_debug_level (trace_parsing);
  float res = parser.parse ();
  scan_end ();
  return res;
}

void
calcxx_driver::error (const yy::location& l, const std::string& m)
{
  std::cerr << l << ": " << m << std::endl;
}

void
calcxx_driver::error (const std::string& m)
{
  std::cerr << m << std::endl;
}

void calcxx_driver::addGraph(std::string name, float value){
  std::string tmpID = getNewID();
  nodes[name] = tmpID;
  o<< tmpID << "[label=\"" << name << " = " << value << "\"];\n";
  connect(tmpID, lastID);
}

std::string calcxx_driver::addGraph(std::string label){
  std::string newID = getNewID();
  o<< newID << "[label=\"" << label << "\"];\n";
  return newID;
}

void calcxx_driver::connect(std::string n1, std::string n2){
  o << n1 << " -> " << n2 << ";\n";
}

std::string calcxx_driver::getNewID(){
  std::string newID = "node";//std::to_string(nodeCount);
  nodeCount++;
  return newID;
}

std::string calcxx_driver::getTmpID(){
  return tmpID;
}

void calcxx_driver::setTmpID(std::string id){
  tmpID = id;
}
/*
float calcxx_driver::getVariable(std::string name){
  if(variables.find(name) == variables.end()){
    error("Float: " + name + " nicht definiert!");
    exit(1);
  }
  if(node1 == ""){
    node1 = nodes[name];
    val1 = variables[name];
    return val1;
  }else{
    node2 = nodes[name];
    val2 = variables[name];
    return val2;
  }
}
*/
void calcxx_driver::setTestMode(bool test){
  testMode = test;
}

bool calcxx_driver::getTestMode(){
  return testMode;
}

void calcxx_driver::print(std::string text){
  std::cout << text;
  if(testMode){
	tS << text;
  }
}

void calcxx_driver::printLine(std::string text){
  print(text);
  std::cout << std::endl;
  if(testMode){
	tS << std::endl;
  }
}

std::string calcxx_driver::to_string(float num){
  stringstream stringvar;
  stringvar << num;
  std::string text = stringvar.str();
  unsigned pos = text.find(".");
  return text.substr(0, pos+3);
}
