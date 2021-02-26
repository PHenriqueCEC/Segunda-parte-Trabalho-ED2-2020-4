#ifndef QUADTREE_H_INCLUDED
#define QUADTREE_H_INCLUDED
#include "./TreeNode.h"
#include <iostream>
#include <string>

using namespace std;

class QuadTree
{
private:
public:
    TreeNode *root;
    QuadTree();
    ~QuadTree();
    string GetQuadrant(CityInfo *inserted, CityInfo *toInsert);
    void Insert(TreeNode *root, CityInfo *toInsert);
    void Print();
    bool Find(CityInfo *value);
};

#endif