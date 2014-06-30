#ifndef IFELSE_H
#define IFELSE_H

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

#include <iostream>
#include <string>
#include <map>
#include "node.h"

using namespace std;
using namespace llvm;

class ifelse{
public:
  ifelse();
  ifelse(node*);
  Value* Codegen(Module*, IRBuilder<>*, std::map<std::string, Value*>&);
  node* CONDITION;
  node* THEN;
  node* ELSE;
  map<string, node*> variables;
  vector<node*> nodes;
  node* getNode(string);
};

#endif /*IFELSE_H*/
