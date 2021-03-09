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
  this->comparisons = 0;
  this->balanced = true;
}

// Destrutor
AvlTree::~AvlTree()

{
  delete root;
  this->root = NULL;
}

int AvlTree::getComparisons()
{
  return this->comparisons;
}
bool AvlTree::getBalance()
{
  return this->balanced;
}
int AvlTree::auxGetHeight(AvlNode *p)
{

  if (p == NULL)
    return -1;
  else
  {
    int he = auxGetHeight(p->getLeft());
    int hd = auxGetHeight(p->getRight());

    if (he < hd)
      return hd + 1;
    else
      return he + 1;
  }
}

int AvlTree::getHeight()
{
  return this->auxGetHeight(this->root);
}

AvlNode *AvlTree::search(int value)
{

  AvlNode *p = this->root;

  while (p != NULL)
  {

    if (p->getValue() == value)
    {

      return p;
    }

    if (value > p->getValue())
    {
      p = p->getRight();
    }
    else
    {
      p = p->getLeft();
    }
  }
  return NULL;
}

void AvlTree::updateBalanceFactor(AvlNode *p)
{
  int balanceFactor;
  if (!p->getRight() && !p->getLeft())
    balanceFactor = 0;
  else if (p->getRight() != NULL && p->getLeft() != NULL)
    balanceFactor = p->getRight()->getBalanceFactor() - p->getLeft()->getBalanceFactor();
  else if (p->getRight() != NULL)
    balanceFactor = 1;
  else
    balanceFactor = -1;
  p->setBalanceFactor(balanceFactor);
}

void AvlTree::verifyBalance(AvlNode *p)
{
  while (p != NULL)
  {
    updateBalanceFactor(p);
    if (p->getBalanceFactor() == 2 && (p->getRight()->getBalanceFactor() == +1 || p->getRight()->getBalanceFactor() == 0))
      simpleRotationLeft(p);
    if (p->getBalanceFactor() == -2 && (p->getRight()->getBalanceFactor() == -1 || p->getRight()->getBalanceFactor() == 0))
      simpleRotationRight(p);
    if (p->getBalanceFactor() == 2 && p->getRight()->getBalanceFactor() == -1)
      doubleRotationLeft(p);
    if (p->getBalanceFactor() == -2 && p->getRight()->getBalanceFactor() == +1)
      doubleRotationRight(p);

    p = p->getNodeFather();
  }
}

void AvlTree::insert(int value)
{
  AvlNode *p = new AvlNode(value);

  if (this->root == NULL)
  {
    this->root = p;
  }
  else
  {
    AvlNode *q = this->root;
    AvlNode *aux;

    while (q != NULL)
    {
      aux = q;

      if (q->getValue() == value)
      {
        this->comparisons++;
        return;
      }

      if (value > p->getValue())
        q = q->getRight();
      else
        q = q->getLeft();
      this->comparisons++;
    }

    if (value > aux->getValue())
    {
      aux->setRight(p);
    }

    else
    {
      aux->setLeft(p);
    }

    p->setNodeFather(aux);

    if (balanced)
    {
      verifyBalance(p);
    }
  }
}
//Ja está certo
void AvlTree::simpleRotationLeft(AvlNode *p)
{
  AvlNode *q = p->getLeft();
  p->setLeft(q->getRight());
  q->setRight(p);
}

//Ja está certo
void AvlTree::simpleRotationRight(AvlNode *p)
{
  AvlNode *q = p->getRight();
  p->setRight(q->getLeft());
  q->setLeft(p);
}
//Já está certo
void AvlTree::doubleRotationLeft(AvlNode *p)
{
  simpleRotationRight(p->getRight());
  simpleRotationLeft(p);
}
//Já está certo
void AvlTree::doubleRotationRight(AvlNode *p)
{
  simpleRotationLeft(p->getLeft());
  simpleRotationRight(p);
}
