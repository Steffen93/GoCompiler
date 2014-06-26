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
# include "calc++-parser.hh"

// Tell Flex the lexer's prototype ...
# define YY_DECL \
  yy::calcxx_parser::symbol_type yylex (calcxx_driver& driver)
// ... and declare it for the parser's sake.
YY_DECL;

// Conducting the whole scanning and parsing of Calc++.
class calcxx_driver
{
public:
  calcxx_driver ();
  virtual ~calcxx_driver ();
  std::map<std::string, node*> svar;
  std::map<std::string, node*> variables;
  std::map<std::string, std::string> nodes;
  std::string node1, node2;
  node* val1, *val2;

  std::vector <node*> result;

//llvm Zeug
  static Module *TheModule;
  static IRBuilder<> *Builder;
  static std::map<std::string, Value*> NamedValues;
  
  void makeCode();
  
  // Handling the scanner.
  void scan_begin ();
  void scan_end ();
  bool trace_scanning;

  // Run the parser on file F.
  // Return 0 on success.
  float parse (const std::string& f);
  // The name of the file being parsed.
  // Used later to pass the file name to the location tracker.
  std::string file;
  // Whether parser traces should be generated.
  bool trace_parsing;
  std::string lastID;

  //Graph erstellen
  std::string getNewID();
  void setTmpID (std::string id);
  std::string getTmpID();
  void connect(std::string n1, std::string n2);
  std::string addGraph(std::string label);
  //std::string addGraph(float label);

  void addGraph(std::string name, float value);
  
  //float getVariable(std::string);
  std::string to_string(float);
  void print(std::string);
  void printLine(std::string);
  void setTestMode(bool);
  bool getTestMode();
  
  // Error handling.
  void error (const yy::location& l, const std::string& m);
  void error (const std::string& m);
  
  std::ofstream o; //not for long!
private:
  bool testMode;
  static int nodeCount;
  
  std::ofstream tS;
  std::string tmpID;
};
#endif // ! CALCXX_DRIVER_HH
