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
  AvlNode *left;
  AvlNode *right;
  int data;
  int height;
  string key;
  string value;
  unsigned short balance;

public:
  AvlNode(string key, string value);
  ~AvlNode();
};

#endif