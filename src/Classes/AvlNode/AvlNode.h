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
  int value; //Valor que será inserido no nó
  int height; //Altura do nó 
  AvlNode *left; //Ponteiro para nó filho a esquerda
  AvlNode *right; //Ponteiro para nó filho a direita

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