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
  int data;
  int height;
  string key;
  string value;
  unsigned short balance;

public:
  AvlNode(string key, string value);
  ~AvlNode();
  AvlNode *left;
  AvlNode *right;
};

#endif