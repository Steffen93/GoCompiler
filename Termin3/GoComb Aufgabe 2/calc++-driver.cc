#include "calc++-driver.hh"
#include "calc++-parser.hh"

calcxx_driver::calcxx_driver ()
  : trace_scanning (false), trace_parsing (false)
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
  o<< name << "[label=\"" << name << " = " << value << "\"];\n";
}

