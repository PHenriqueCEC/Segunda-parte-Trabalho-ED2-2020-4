#include "./AvlNode.h"
#include <iostream>
#include <string>
#include <random>
using namespace std;

AvlNode::AvlNode(string key, string value)

{

  this->key = key;

  this->value = value;

  this->left = nullptr;

  this->right = nullptr;

  //this->balance = EQUAL;
}

// Destrutor

AvlNode::~AvlNode()

{
  delete this->left;
  delete this->right;
}
