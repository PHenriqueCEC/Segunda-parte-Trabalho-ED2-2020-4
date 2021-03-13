#include "../AvlNode/AvlNode.h"
#include "./AvlTree.h"
#include <iostream>
#include <string>
#include <random>
using namespace std;
#define COUNT 10

// Construtor
AvlTree::AvlTree()

{
  // Inicializamos a raíz com null.
  this->root = nullptr;
  this->comparisons = 0;
}

// Destrutor
AvlTree::~AvlTree()
{
  delete root;
  this->root = nullptr;
}
int AvlTree::height(AvlNode *p)
{
  if (p == NULL)
  {
    return 0;
  }
  else
  {
    return p->getHeight();
  }
}
//Irá verificar qual lado tem maior altura, e irá retornar ou lado esquerdo ou lado direito.
int AvlTree::getHeight(AvlNode *p)
{
  int leftHeight = 0;
  int rightHeight = 0;

  if (p->getLeft())
  {
    leftHeight = getHeight(p->getLeft());
  }

  if (p->getRight())
  {
    rightHeight = getHeight(p->getRight());
  }

  return higherElement(rightHeight, leftHeight) + 1;
}

//Função que verifica qual maior elemento, será usado para verificar qual é lado tem maior altura.
int AvlTree::higherElement(int a, int b)
{
  if (a > b)
  {
    return a;
  }
  else
  {
    return b;
  }
}

//Função para obter o número de comparações feitas
int AvlTree::getComparisons()
{
  return this->comparisons;
}

//Função que irá buscar um valor na arvore
bool AvlTree::search(int value)
{

  AvlNode *p = this->root;

  while (p != nullptr)
  {
    if (p->getValue() == value)
    {
      return true;
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

  return false;
}

int AvlTree::getBalance(AvlNode *p)
{
  if (p == NULL)
  {
    return 0;
  }
  return height(p->getLeft()) - height(p->getRight());
}

void AvlTree::doInsert(int value)
{
  root = insert(root, value);
}
AvlNode *AvlTree::insert(AvlNode *p, int value)
{
  if (p == NULL)
  {
    AvlNode *r = new AvlNode(value);
    return r;
  }

  if (value < p->getValue())
  {
    p->setLeft(insert(p->getLeft(), value));
  }
  else if (value > p->getValue())
  {
    p->setRight(insert(p->getRight(), value));
  }
  else
  {
    return p;
  }

  p->setHeight(1 + higherElement(height(p->getLeft()), height(p->getRight())));

  int balanceFactor = getBalance(p);
  if (balanceFactor > 1)
  {
    if (value < p->getLeft()->getValue())
    {
      return simpleRotationRight(p);
    }
    else if (value > p->getLeft()->getValue())
    {
      return doubleRotationRight(p);
    }
  }
  if (balanceFactor < -1)
  {
    if (value > p->getRight()->getValue())
    {
      return simpleRotationLeft(p);
    }
    else if (value < p->getRight()->getValue())
    {
      return doubleRotationLeft(p);
    }
  }
  return p;
}

//Right right rotation
AvlNode *AvlTree::simpleRotationLeft(AvlNode *p)
{
  //Efetua a rotação para esquerda
  AvlNode *q = p->getRight();
  p->setRight(q->getLeft());
  q->setLeft(p);

  p->setHeight(higherElement(height(p->getLeft()), height(p->getRight())) + 1);
  q->setHeight(higherElement(height(q->getLeft()), height(q->getRight())) + 1);

  return q;
}
//Left left rotation
AvlNode *AvlTree::simpleRotationRight(AvlNode *p)
{
  AvlNode *q = p->getLeft();
  p->setLeft(q->getRight());
  q->setRight(p);

  p->setHeight(higherElement(height(p->getLeft()), height(p->getRight())) + 1);
  q->setHeight(higherElement(height(q->getLeft()), height(q->getRight())) + 1);

  return q;
}

//Right left rotation
AvlNode *AvlTree::doubleRotationLeft(AvlNode *p)
{
  p->setRight(simpleRotationRight(p->getRight()));
  return simpleRotationLeft(p);
}

//Left right rotation
AvlNode *AvlTree::doubleRotationRight(AvlNode *p)
{
  p->setLeft(simpleRotationLeft(p->getLeft()));
  return simpleRotationRight(p);
}

AvlNode *AvlTree::getRoot()
{
  return this->root;
}

// Function to print binary tree in 2D
// It does reverse inorder traversal
void AvlTree::print2DUtil(AvlNode *p, int space)
{
  // Base case
  if (p == NULL)
    return;

  // Increase distance between levels
  space += COUNT;

  // Process right child first
  print2DUtil(p->getRight(), space);

  // Print current node after space
  // count
  cout << endl;
  for (int i = COUNT; i < space; i++)
    cout << " ";
  cout << p->getValue() << "\n";

  // Process left child
  print2DUtil(p->getLeft(), space);
}

// Wrapper over print2DUtil()
void AvlTree::print2D()
{
  // Pass initial space count as 0
  AvlNode *p = this->root;
  print2DUtil(p, 0);
}

void AvlTree::printTree(AvlNode *root, string indent, bool last, bool isWriteInFile, ofstream &file)
{
  if (root != nullptr)
  {
    if (!isWriteInFile)
    {
      cout << indent;
      if (last)
      {
        cout << "R----";
        indent += "   ";
      }
      else
      {
        cout << "L----";
        indent += "|  ";
      }
      cout << root->getValue() << endl;
      printTree(root->getLeft(), indent, false , false , file);
      printTree(root->getRight(), indent, true , false , file);
    }

    if (isWriteInFile)
    {
      file << indent;
      if (last)
      {
        file << "R----";
        indent += "   ";
      }
      else
      {
        file << "L----";
        indent += "|  ";
      }
      file << root->getValue() << endl;
      printTree(root->getLeft(), indent, false ,true , file);
      printTree(root->getRight(), indent, true , true , file);
    }
  }
}
void AvlTree::doPrint(bool isWriteInFile)
{
  ofstream arq("saidaTestes.txt");
  printTree(root, "", true ,isWriteInFile,arq);
}