#include "node.h"


node::node(node *leftnode, node *rightnode){
  this->left = leftnode;
  this->right = rightnode;
  inserted = false;
}

node::node(){
  this->left = NULL;
  this->right = NULL;
  label = sval = type = "";
  fval = 0.0;
  inserted = false;
}

node::node(node* copy){
  this->left = copy->left;
  this->right = copy->right;
  this->label = copy->label;
  this->fval = copy->fval;
  this->sval = copy->sval;
  this->type = copy->type;
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
