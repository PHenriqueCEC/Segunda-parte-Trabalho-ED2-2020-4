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
  int height;
  int balanceFactor;
  int value;
  AvlNode *nodeFather;
  AvlNode *left;
  AvlNode *right;

public:
  AvlNode(int v);
  AvlNode();
  ~AvlNode();
  int getValue();
  int getBalanceFactor();
  AvlNode *getLeft();
  AvlNode *getRight();
  AvlNode *getNodeFather();
  void setValue(int v);
  void setBalanceFactor(int factor);
  void setLeft(AvlNode *p);
  void setRight(AvlNode *p);
  void setNodeFather(AvlNode *p);
};

#endif