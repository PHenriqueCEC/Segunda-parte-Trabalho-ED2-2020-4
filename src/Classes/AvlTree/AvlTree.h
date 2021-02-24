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
  void updateBalance();
  void insert(string key, string value, AvlNode *node, bool &changedH);
  bool remove(string key, AvlNode *node, bool &changedH);

public:
  AvlTree();
  ~AvlTree();
  void Insert(string key, string value);
  bool Search(string key, string value);
  void Print();
  void PrintNodeDetails();
};

#endif