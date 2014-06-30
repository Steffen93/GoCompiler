#include"ifelse.h"

ifelse::ifelse(){}

ifelse::ifelse(node* _condition): variables(map<string, node*>()), nodes(vector<node*>()){
  CONDITION = _condition;
}

Value* ifelse::Codegen(Module *TheModule, IRBuilder<> *Builder, std::map<std::string, Value*> &NamedValues){
  if(CONDITION->left == NULL || CONDITION->right == NULL){
    cout << "NULL in CODEGEN" << endl;
  }
  Value* L = CONDITION->left->Codegen(TheModule, Builder, NamedValues);
  Value* R = CONDITION->right->Codegen(TheModule, Builder, NamedValues);
  if (CONDITION->type == "<"){
    L = Builder->CreateFCmpULT(L,R,"cmptmp");
  }
  else if(CONDITION->type == ">"){

  }
  else if(CONDITION->type == "!="){

  }
  else if(CONDITION->type == "=="){
    
  }
  Value* CondV = Builder->CreateUIToFP(L, Type::getFloatTy(getGlobalContext()), "booltmp");
  CondV = Builder->CreateFCmpONE(CondV, ConstantFP::get(getGlobalContext(), APFloat(0.0)), "ifcond");
  Function* TheFunction = Builder->GetInsertBlock()->getParent();
  BasicBlock *ThenBB = BasicBlock::Create(getGlobalContext(), "then", TheFunction);
  BasicBlock *ElseBB = BasicBlock::Create(getGlobalContext(), "else");
  BasicBlock *MergeBB = BasicBlock::Create(getGlobalContext(), "ifcont");

  Builder->CreateCondBr(CondV, ThenBB, ElseBB);
  Builder->SetInsertPoint(ThenBB);
  Value* ThenV = THEN->Codegen(TheModule, Builder, NamedValues);
  Builder->CreateBr(MergeBB);
  ThenBB = Builder->GetInsertBlock();
  TheFunction->getBasicBlockList().push_back(ElseBB);
  Builder->SetInsertPoint(ElseBB);
  Value* ElseV = ELSE->Codegen(TheModule, Builder, NamedValues);
  Builder->CreateBr(MergeBB);
  ElseBB = Builder->GetInsertBlock();
  TheFunction->getBasicBlockList().push_back(MergeBB);
  Builder->SetInsertPoint(MergeBB);
  PHINode *PN = Builder->CreatePHI(Type::getDoubleTy(getGlobalContext()), 2, "iftmp");
  PN->addIncoming(ThenV, ThenBB);
  PN->addIncoming(ElseV, ElseBB);
  return PN;
}
