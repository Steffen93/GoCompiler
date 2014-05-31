#include "calc++-driver.hh"
#include "calc++-parser.hh"

int calcxx_driver::nodeCount = 0;

calcxx_driver::calcxx_driver ()
  : trace_scanning (false), trace_parsing (false), tmpID("")
{
  std::ofstream f;
  o.open("dotgraph.dot");
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

std::string calcxx_driver::addGraph(float label){
  static int cnt = 0;
  static float tmp = 0;
  static std::string newID = "";
  if(node1 != "" && val1 == label){
    newID = node1;
    node1 = "";
    tmp = label;
    cnt++;
    lastID = newID;
    return newID;
  }else if(node2 != "" && val2 == label){
    newID = node2;
    node2 = "";
    tmp = label;
    cnt++;
    lastID = newID;
    return newID;
  }
  if(!(cnt % 3 == 0 && tmp == label)){
    newID = getNewID();
    o<< newID << "[label=\"" << std::to_string(label) << "\"];\n";
  }
  tmp = label;
  cnt++;
  lastID = newID;
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

float calcxx_driver::getVariable(std::string name){
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
