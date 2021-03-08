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
  bool balanced;
  int comparisons;

public:
  AvlTree();
  ~AvlTree();
  void simpleRotationLeft(AvlNode *node);
  void simpleRotationRight(AvlNode *node);
  void doubleRotationLeft(AvlNode *node);
  void doubleRotationRight(AvlNode *node);
  void insert(int value);
  void updateBalanceFactor(AvlNode *p);
  void verifyBalance(AvlNode *p);
  int getHeight();
  int auxGetHeight(AvlNode *p);
  int getComparisons();
  bool getBalance();
  AvlNode *search(int value);
};

#endif