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