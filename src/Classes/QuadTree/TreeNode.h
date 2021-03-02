#ifndef TREENODE_H_INCLUDED
#define TREENODE_H_INCLUDED
#include "../CityInfo/CityInfo.h"
#include <iostream>
#include <string>

using namespace std;

class TreeNode
{
private:

    CityInfo *rootValue;
    TreeNode *SE;
    TreeNode *SW;
    TreeNode *NE;
    TreeNode *NW;

    int size = 0;

public:
    TreeNode();
    ~TreeNode();
    void setRootValue(CityInfo *rootValue);
    void setSE(CityInfo *SE);
    void setSW(CityInfo *SW);
    void setNE(CityInfo *NE);
    void setNW(CityInfo *NEW);
    TreeNode* getSE();
    TreeNode* getSW();
    TreeNode* getNE();
    TreeNode* getNW();
    CityInfo* getRootValue();
    TreeNode* getValueInQuadrant(string quadrant);
    /*void printTree();
    void auxPrintTree(TreeNode *tree);*/
    void insertInQuadrant(string quadrant , CityInfo* value);
};

#endif