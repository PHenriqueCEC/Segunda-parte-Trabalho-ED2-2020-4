#ifndef AVLNODE_H_INCLUDED
#define AVLNODE_H_INCLUDED
#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

class AvlNode
{
private:
  int value;
  int height;
  AvlNode *left;
  AvlNode *right;

public:
  AvlNode(int v);
  ~AvlNode();
  AvlNode *getLeft();
  AvlNode *getRight();
  int getValue(); 
  int getHeight();
  void setHeight(int v);
  void setValue(int v);
  void setLeft(AvlNode *p);
  void setRight(AvlNode *p);

};

#endif