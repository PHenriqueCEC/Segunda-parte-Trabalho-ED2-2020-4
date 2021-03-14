#include "./AvlNode.h"
#include <iostream>
#include <string>
#include <random>
using namespace std;

///////////////////////
//////CONSTRUTOR//////
///////////////////// 

AvlNode::AvlNode(int value)

{
  //Nó é iniciado com um valor value
  this->value = value;
  //Nó é iniciado com ponteiros para os nós filhos como NULL
  this->left = nullptr;
  this->right = nullptr;
  //Nó é iniciado com altura 0, altura de single node é 0
  this->height= 0;
}

///////////////////////
//////DESTRUTOR///////
/////////////////////

AvlNode::~AvlNode()

{
}


///////////////////////
//////AUXILARES///////
/////////////////////

//Função get para obter o ponteiro para o nó a esquerda
AvlNode *AvlNode::getLeft()
{
  return this->left;
}

//Função get para obter o ponteiro para o nó a direita
AvlNode *AvlNode::getRight()
{
  return this->right;
}

//Função get para obter o valor armazenado em um nó
int AvlNode::getValue()
{
  return this->value;
}

//Função get para obter a altura do nó
int AvlNode::getHeight()
{
  return this->height;
}

//Função set para alterar o valor armazenado em um nó
void AvlNode::setValue(int v)
{
  this->value = v;
}

//Função set para alterar o ponteiro
void AvlNode::setLeft(AvlNode *p)
{
  this->left = p;
}

void AvlNode::setRight(AvlNode *p)
{
  this->right = p;
}

//Função set para alterar o valor da altura do nó
void AvlNode::setHeight(int value)
{
  this->height = value;
}