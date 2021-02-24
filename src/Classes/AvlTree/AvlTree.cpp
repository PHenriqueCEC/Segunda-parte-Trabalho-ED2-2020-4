#include "../AvlNode/AvlNode.h"
#include "../AvlNode/AvlNode.cpp"
#include "./AvlTree.h"
#include <iostream>
#include <string>
#include <random>
using namespace std;

// Construtor
AvlTree::AvlTree()

{
  // Inicializamos a raíz com null.
  this->root = NULL;
}

// Destrutor
AvlTree::~AvlTree()

{
  delete root;
  this->root = NULL;
}

AvlNode *AvlTree::simpleRotationLeft(AvlNode *p)
{
  AvlNode *q = p->left;
  p->left = q->right;
  q->right = p;
  return q;
}

AvlNode *AvlTree::simpleRotationRight(AvlNode *p)
{
  AvlNode *q = p->right;
  p->right = q->left;
  q->left = p;
  return q;
}

AvlNode *AvlTree::doubleRotationLeft(AvlNode *p)
{
  simpleRotationRight(p);
  simpleRotationLeft(p);
}

AvlNode *AvlTree::doubleRotationRight(AvlNode *p)
{
  simpleRotationLeft(p);
  simpleRotationRight(p);
}