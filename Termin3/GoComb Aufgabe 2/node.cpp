#include "node.h"


node::node(node *left, node *right){
  this->left = left;
  this->right = right;
}

node::node(){
  
}

node::~node(){
  if(left != NULL)
    left->~node();
  if(right != NULL)
    right->~node();
}