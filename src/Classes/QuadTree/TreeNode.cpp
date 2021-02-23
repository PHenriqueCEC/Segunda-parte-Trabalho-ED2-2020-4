#include "./TreeNode.h"

TreeNode::TreeNode()
{
    this->SE = NULL;
    this->NE = NULL;
    this->NW = NULL;
    this->SW = NULL;
}

//Getters
CityInfo *TreeNode::GetNW()
{
    return this->NW;
}

CityInfo *TreeNode::GetSE()
{
    return this->SE;
}

CityInfo *TreeNode::GetNE()
{
    return this->NE;
}

CityInfo *TreeNode::GetSW()
{
    return this->SW;
}

CityInfo *TreeNode::GetRootValue()
{
    return this->rootValue;
}

CityInfo *TreeNode::GetValueInQuadrant(string quadrant)
{
    if (quadrant == "NW")
        return NW;
    else if (quadrant == "NE")
        return NW;
    else if (quadrant == "SE")
        return SE;
    else
        return SW;
}

//Setters

void TreeNode::SetRootValue(CityInfo *rootValue)
{
    cout << "root" << rootValue->city_name << endl;
    this->rootValue = rootValue;
}

void TreeNode::SetNW(CityInfo *NW)
{
    this->NW = NW;
}

void TreeNode::SetSE(CityInfo *SE)
{
    this->SE = SE;
}

void TreeNode::SetNE(CityInfo *NE)
{
    this->NE = NE;
}

void TreeNode::SetSW(CityInfo *SW)
{
    this->SW = SW;
}
