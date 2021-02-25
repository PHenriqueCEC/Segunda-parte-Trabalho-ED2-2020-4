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

public:
    TreeNode();
    ~TreeNode();
    void SetRootValue(CityInfo *rootValue);
    void SetSE(CityInfo *SE);
    void SetSW(CityInfo *SW);
    void SetNE(CityInfo *NE);
    void SetNW(CityInfo *NEW);
    TreeNode* GetSE();
    TreeNode* GetSW();
    TreeNode* GetNE();
    TreeNode* GetNW();
    CityInfo* GetRootValue();
    TreeNode* GetValueInQuadrant(string quadrant);
    void PrintTree();
    void InsertInQuadrant(string quadrant , CityInfo* value);
};

#endif