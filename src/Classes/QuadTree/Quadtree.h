#ifndef QUADTREE_H_INCLUDED
#define QUADTREE_H_INCLUDED
#include "./TreeNode.h"
#include <iostream>
#include <string>

using namespace std;

class QuadTree
{
private:
    int size;
public:
    TreeNode *root;
    QuadTree();
    ~QuadTree();
    string getQuadrant(CityInfo *inserted, CityInfo *toInsert);
    void insert(TreeNode *root, CityInfo *toInsert);
    void auxPrint(TreeNode *node);
    void print();
    bool find(CityInfo *value);
    bool auxFind(TreeNode *tree);
    int getSize();
    void setSize(int size);
};

#endif