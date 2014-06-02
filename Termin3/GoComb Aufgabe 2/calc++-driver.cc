#include "calc++-driver.hh"
#include "calc++-parser.hh"

int calcxx_driver::nodeCount = 0;

calcxx_driver::calcxx_driver ()
  : trace_scanning (false), trace_parsing (false), tmpID(""), testMode(false)
{
  o << "digraph gograph{\n";
  
  
  variables["one"] = 1.0;
  variables["two"] = 2.0;
}

calcxx_driver::~calcxx_driver ()
{
  o << "\n}";
  o.close();
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
  o<< getNewID() << "[label=\"" << name << " = " << value << "\"];\n";
}

std::string calcxx_driver::addGraph(std::string label){
  std::string newID = getNewID();
  o<< newID << "[label=\"" << label << "\"];\n";
  return newID;
}

std::string calcxx_driver::addGraph(float label){
  std::string newID = getNewID();
  o<< newID << "[label=\"" << std::to_string(label) << "\"];\n";
  return newID;
}

void calcxx_driver::connect(std::string n1, std::string n2){
  o << n1 << " -> " << n2 << ";\n";
}

std::string calcxx_driver::getNewID(){
  std::string newID = "node" + std::to_string(nodeCount);
  nodeCount++;
  return newID;
}

std::string calcxx_driver::getTmpID(){
  return tmpID;
}

void calcxx_driver::setTmpID(std::string id){
  tmpID = id;
}

void calcxx_driver::setTestMode(bool test){
  testMode = test;
}

bool calcxx_driver::getTestMode(){
  return testMode;
}

void calcxx_driver::print(std::string text){
  std::cout << text;
}

void calcxx_driver::printLine(std::string text){
  print(text);
  std::cout << std::endl;
}

std::string calcxx_driver::to_string(float num){
  std::string text = std::to_string(num);
  unsigned pos = text.find(".");
  return std::string::substr(text);
}
