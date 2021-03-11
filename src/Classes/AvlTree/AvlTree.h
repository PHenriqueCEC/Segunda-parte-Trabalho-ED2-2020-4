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
  AvlNode *root;
  int comparisons;

public:
  AvlTree();
  ~AvlTree();
  AvlNode* simpleRotationLeft(AvlNode *node);
  AvlNode* simpleRotationRight(AvlNode *node);
  AvlNode* doubleRotationLeft(AvlNode *node);
  AvlNode* doubleRotationRight(AvlNode *node);
  AvlNode* verifyBalance(AvlNode *p);
  AvlNode* insert(AvlNode* p,int value);
  void doInsert(int value);
  int height(AvlNode *p);
  void preOrder();
  int higherElement(int a,int b);
  int getHeight(AvlNode *p);
  int getComparisons();
  int getBalance(AvlNode *p);
  bool search(int value);
  void print2DUtil(AvlNode *p, int space);
  void print2D();
  void printTree(AvlNode *root, string indent, bool last);
  void doPrint();
};

#endif