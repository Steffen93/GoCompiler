#ifndef CALCXX_DRIVER_HH
# define CALCXX_DRIVER_HH
// Use thse Header Files with LLVM 3.2 AND/OR 3.3
#include "llvm/Config/llvm-config.h"
#include "llvm/Analysis/Verifier.h"

#if LLVM_VERSION_MAJOR != 3
#error Only LLVM 3.2 and 3.3 are supported

#elif LLVM_VERSION_MINOR == 2
// Use these Header Files with LLVM 3.2
#include "llvm/DerivedTypes.h"
#include "llvm/IRBuilder.h"
#include "llvm/LLVMContext.h"
#include "llvm/Module.h"

#elif   LLVM_VERSION_MINOR == 3
// Use these Header Files with LLVM 3.3
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"

#else
#error Only LLVM 3.2 and 3.3 are supported
#endif
# include <string>
# include <map>
# include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include "node.h"
#include "calc++-parser.hh"
#include "ifelse.h"

// Tell Flex the lexer's prototype ...
# define YY_DECL \
  yy::calcxx_parser::symbol_type yylex (calcxx_driver& driver)
// ... and declare it for the parser's sake.
YY_DECL;

using namespace std;
using namespace llvm;

// Conducting the whole scanning and parsing of Calc++.
class calcxx_driver
{
public:
  calcxx_driver ();
  virtual ~calcxx_driver ();
  map<string, node*> svar;
  map<string, node*> variables;
  map<string, string> nodes;
  map<string, function*> functions;
  string node1, node2;
  node* val1, *val2;

  vector <node*> result;
  function* tmpfunction;

  vector<ifelse*> ifelses;
  ifelse* tmpifelse;

  node* filterFunc(string name);
//llvm Zeug

  static Module *TheModule;
  static IRBuilder<> *Builder;
  static map<string, Value*> NamedValues;

  void makeCode();

  // Handling the scanner.
  void scan_begin ();
  void scan_end ();
  bool trace_scanning;

  // Run the parser on file F.
  // Return 0 on success.
  float parse (const string& f);
  // The name of the file being parsed.
  // Used later to pass the file name to the location tracker.
  string file;
  // Whether parser traces should be generated.
  bool trace_parsing;
  string lastID;

  //Graph erstellen
  string getNewID();
  void setTmpID (string id);
  string getTmpID();
  void connect(string n1, string n2);
  string addGraph(string label);
  //string addGraph(float label);

  void addGraph(string name, float value);

  //float getVariable(string);
  string to_string(float);
  void print(string);
  void printLine(string);
  void setTestMode(bool);
  bool getTestMode();

  // Error handling.
  void error (const yy::location& l, const string& m);
  void error (const string& m);

  ofstream o; //not for long!
private:
  bool testMode;
  static int nodeCount;

  ofstream tS;
  string tmpID;
};
#endif // ! CALCXX_DRIVER_HH
