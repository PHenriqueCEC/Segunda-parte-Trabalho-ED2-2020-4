#include "./TreeNode.h"

TreeNode::TreeNode()
{
    this->rootValue = new CityInfo();
    this->SE = new CityInfo();
    this->NE = new CityInfo();
    this->NW = new CityInfo();
    this->SW = new CityInfo();
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
    cout << "root" << this->rootValue->city_code << endl;
    this->rootValue = rootValue;
    cout << "Saiu" << endl;
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

TreeNode::~TreeNode()
{

}
