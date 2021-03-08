#ifndef QUADTREE_H_INCLUDED
#define QUADTREE_H_INCLUDED
#include "./TreeNode.h"
#include "../Coordinate/Coordinate.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Struct para armazenar os pontos para
//armazenar os pontos x1,x2,y1,y1 para
//obter cidades nesse range


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
    vector<string> getCitysInCoordinates(Coordinate *coordinates);
    void auxGetCitysInCoordinates(TreeNode *tree,Coordinate *coordinates,vector<string> &citysInRange);
    TreeNode* clean(TreeNode *node);
};

#endif