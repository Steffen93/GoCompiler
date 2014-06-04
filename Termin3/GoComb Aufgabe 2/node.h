#ifndef node_H
#define node_H
#include <string>
#include <fstream>
#include <iostream>
#include <stdint.h>

using namespace std;

class node{
public:
  //node(string val);
  node(node *leftnode, node *rightnode);
  node();
  node(node* copy);
  virtual ~node();
  
  void makeGraph(ofstream &o);
  
  node *left;
  node *right;
  bool inserted;
  string label;
  string type;
  string sval;
  float fval;
  int ival;
  
};
#endif
