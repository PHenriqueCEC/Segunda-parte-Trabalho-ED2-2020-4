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

//Ja está certo
AvlNode *AvlTree::simpleRotationLeft(AvlNode *p)
{
  AvlNode *q = p->left;
  p->left = q->right;
  q->right = p;
  return q;
}

//Ja está certo
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

AvlNode *AvlTree::insert(AvlNode *node, string value)
{

  if (node == nullptr)
  {
    node = new AvlNode;
    node->data = value; //o que é esse data?
    node->left = nullptr;
    node->right = nullptr;
    return node;
  }
  else if (value < node->data)
  {
    node->left = insert(node->left, value);
    node = balance(node);
  }
  else if (value >= node->data)
  {
    node->right = insert(node->right, value);
    node = balance(node);
  }
  return node;
}

int AvlTree::height(AvlNode *node)
{
  int h = 0;
  if (node != nullptr)
  {
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    int maxHeight = max(leftHeight, rightHeight);
    h = maxHeight + 1;
  }
  return h;
}

int AvlTree::difference(AvlNode *node)
{
  int leftHeight = height(node->left);
  int rightHeight = height(node->right);
  int balanceFactor = leftHeight - rightHeight;
  return balanceFactor;
}

AvlNode *AvlTree::balance(AvlNode *node)
{
  int balanceFactor = difference(node);
  if (balanceFactor > 1)
  {
    if (difference(node->left) > 0)
    {
      node = simpleRotationLeft(node);
    }
    else
    {
      node = doubleRotationRight(node);
    }
  }
  else if (balanceFactor < -1)
  {
    if (difference(node->right) > 0)
    {
      node = doubleRotationLeft(node);
    }
    else
    {
      node = simpleRotationRight(node);
    }
  }
  return node;
}