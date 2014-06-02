#ifndef node_H
#define node_H
#include <string>

using namespace std;

class node{
public:
  //node(string val);
  node(node *left, node *right);
  node();
  virtual ~node();
  
  node *left;
  node *right;
  
  string name;
  string sval;
  float fval;
  
};
#endif