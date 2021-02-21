#ifndef TREENODE_H_INCLUDED
#define TREENODE_H_INCLUDED
#include "../CityInfo/CityInfo.h"
#include <iostream>
#include <string>

using namespace std;

class TreeNode
{
private:
    CityInfo *SE;
    CityInfo *SW;
    CityInfo *NE;
    CityInfo *NW;

public:
    TreeNode();
    void setSE(CityInfo *SE);
    void setSW(CityInfo *SW);
    void setNE(CityInfo *NE);
    void setNW(CityInfo *NEW);
    // void getSE(CityInfo *SE);
    // void getSW(CityInfo *SW);
    // void getNE(CityInfo *NE);
    // void getNW(CityInfo *NEW);
    
    ~TreeNode();
};

#endif