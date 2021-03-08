#include "./AvlNode.h"

AvlNode::AvlNode(int value)

{
  this->nodeFather = nullptr;
  this->value = value;
  this->left = nullptr;
  this->right = nullptr;
  this->balanceFactor = 0;
}

// Destrutor

AvlNode::~AvlNode()

{
}

AvlNode *AvlNode::getLeft()
{
  return this->left;
}

AvlNode *AvlNode::getRight()
{
  return this->right;
}

AvlNode *AvlNode::getNodeFather()
{
  return this->nodeFather;
}

int AvlNode::getValue()
{
  return this->value;
}

int AvlNode::getBalanceFactor()
{
  return this->balanceFactor;
}

void AvlNode::setValue(int v)
{
  this->value = v;
}

void AvlNode::setBalanceFactor(int factor)
{
  this->balanceFactor = factor;
}

void AvlNode::setLeft(AvlNode *p)
{
  this->left = p;
}

void AvlNode::setRight(AvlNode *p)
{
  this->right = p;
}

void AvlNode::setNodeFather(AvlNode *p)
{
  this->nodeFather = p;
}
