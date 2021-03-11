#include "./AvlNode.h"
#include <iostream>
#include <string>
#include <random>
using namespace std;

AvlNode::AvlNode(int value)

{
  this->value = value;
  this->left = nullptr;
  this->right = nullptr;
  this->height= 1;
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


int AvlNode::getValue()
{
  return this->value;
}

int AvlNode::getHeight()
{
  return this->height;
}

void AvlNode::setValue(int v)
{
  this->value = v;
}

void AvlNode::setLeft(AvlNode *p)
{
  this->left = p;
}

void AvlNode::setRight(AvlNode *p)
{
  this->right = p;
}

void AvlNode::setHeight(int value)
{
  this->height = value;
}