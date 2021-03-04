#ifndef AVLTREE_H_INCLUDED
#define AVLTREE_H_INCLUDED
#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "../AvlNode/AvlNode.h"
using namespace std;

class AvlTree
{
private:
  AvlTree *root;
  AvlNode *simpleRotationLeft(AvlNode *node);
  AvlNode *simpleRotationRight(AvlNode *node);
  AvlNode *doubleRotationLeft(AvlNode *node);
  AvlNode *doubleRotationRight(AvlNode *node);

public:
  AvlTree();
  ~AvlTree();
  bool search(string key, string value);
  AvlNode *insert(AvlNode *node, string value);
  AvlNode *balance(AvlNode *node);
  int height(AvlNode *node);
  int difference(AvlNode *node);
  void Print();
  void PrintNodeDetails();
};

#endif