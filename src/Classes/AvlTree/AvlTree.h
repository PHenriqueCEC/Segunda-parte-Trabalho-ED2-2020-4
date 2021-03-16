#ifndef AVLTREE_H_INCLUDED
#define AVLTREE_H_INCLUDED
#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "../AvlNode/AvlNode.h"
#include "../HashTable/HashTable.h"
using namespace std;

class AvlTree
{
private:
  AvlNode *root;         //Nó raiz da árvore
  int comparisonsInsert; //Contador de comparações de valores para inserção
  int comparisonsSearch; //Contador de comparações de valores para busca

public:
  AvlTree();
  ~AvlTree();
  AvlNode *simpleRotationLeft(AvlNode *node);
  AvlNode *simpleRotationRight(AvlNode *node);
  AvlNode *doubleRotationLeft(AvlNode *node);
  AvlNode *doubleRotationRight(AvlNode *node);
  AvlNode *verifyBalance(AvlNode *p);
  AvlNode *insert(AvlNode *p, int value);
  void doInsert(int value);
  int height(AvlNode *p);
  void preOrder();
  int higherElement(int a, int b);
  int getHeight(AvlNode *p);
  int getComparisons();
  int getInsertComparisons();
  int getSearchComparisons();
  int getBalance(AvlNode *p);
  bool search(int value);
  void print2DUtil(AvlNode *p, int space);
  void print2D();
  void printTree(AvlNode *root, string indent, bool last, bool isWriteInFile, ofstream &file);
  void doPrint(bool isWriteInFile);
  void freeNode(AvlNode *p);
  AvlNode *getRoot();

  //Obter códigos de cidades unicas numa determinada Árvore AVL
  vector<int> doGetUniqueCitys(HashTable *hash);
  void getUniqueCitys(AvlNode *node, HashTable *hash, vector<int> &uniqueCitys , int &comparisions);
};

#endif