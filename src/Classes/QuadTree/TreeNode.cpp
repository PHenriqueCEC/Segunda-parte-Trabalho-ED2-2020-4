#include "./TreeNode.h"

TreeNode::TreeNode()
{
    this->rootValue = new CityInfo();
    this->SE = NULL;
    this->NE = NULL;
    this->NW = NULL;
    this->SW = NULL;
}

//Getters
TreeNode *TreeNode::GetNW()
{
    return this->NW;
}

TreeNode *TreeNode::GetSE()
{
    return this->SE;
}

TreeNode *TreeNode::GetNE()
{
    return this->NE;
}

TreeNode *TreeNode::GetSW()
{
    return this->SW;
}

CityInfo *TreeNode::GetRootValue()
{
    return this->rootValue;
}

TreeNode *TreeNode::GetValueInQuadrant(string quadrant)
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
}

void TreeNode::SetNW(CityInfo *NW)
{
    this->NW->SetRootValue(NW);
}

void TreeNode::SetSE(CityInfo *SE)
{
    this->SE->SetRootValue(SE);
}

void TreeNode::SetNE(CityInfo *NE)
{
    this->NE->SetRootValue(NE);
}

void TreeNode::SetSW(CityInfo *SW)
{
    this->SW->SetRootValue(SW);
}

void TreeNode::InsertInQuadrant(string quadrant, CityInfo *value)
{
    if (quadrant == "SE")
    {
        this->SE = new TreeNode();
        this->SE->SetRootValue(value);
        return;
    }
    else if (quadrant == "SW")
    {
        this->SW = new TreeNode();
        this->SW->SetRootValue(value);
        return;
    }
    if (quadrant == "NE")
    {
        this->NE = new TreeNode();
        this->NE->SetRootValue(value);
        return;
    }
    if (quadrant == "NW")
    {
        this->NW = new TreeNode();
        this->NW->SetRootValue(value);
        return;
    }
}

TreeNode::~TreeNode()
{
}
