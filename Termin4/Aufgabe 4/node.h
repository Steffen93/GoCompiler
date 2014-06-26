#ifndef node_H
#define node_H
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

#include <string>
#include <fstream>
#include <iostream>
#include <stdint.h>

using namespace llvm;

class node{
public:
  //node(string val);
  node(node *leftnode, node *rightnode);
  node();
  node(node* copy);
  virtual ~node();
  Value *Codegen(Module *TheModule, IRBuilder<> *Builder, std::map<std::string, Value*> &NamedValues);
  //Value *Codegen();
  void makeGraph(std::ofstream &o);

  //static Module* TheModule;
  //static IRBuilder<> Builder;
  //static std::map<std::string, Value*> NamedValues;
  node *left;
  node *right;
  bool inserted;
  std::string label;
  std::string type;
  std::string sval;
  float fval;
  int ival;
  char cval;

};
#endif
