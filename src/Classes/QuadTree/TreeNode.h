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
    CityInfo *SE;
    CityInfo *SW;
    CityInfo *NE;
    CityInfo *NW;

public:
    TreeNode();
    void SetRootValue(CityInfo *rootValue);
    void SetSE(CityInfo *SE);
    void SetSW(CityInfo *SW);
    void SetNE(CityInfo *NE);
    void SetNW(CityInfo *NEW);
    CityInfo* GetSE();
    CityInfo* GetSW();
    CityInfo* GetNE();
    CityInfo* GetNW();
    CityInfo* GetRootValue();
    CityInfo* GetValueInQuadrant(string quadrant);
    ~TreeNode();
};

#endif