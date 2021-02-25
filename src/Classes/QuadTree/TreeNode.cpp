#include "./TreeNode.h"

TreeNode::TreeNode()
{
    this->rootValue = new CityInfo();
    this->SE = nullptr;
    this->NE = nullptr;
    this->NW = nullptr;
    this->SW = nullptr;
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
    {
        if (NW == NULL)
        {
            NW = new TreeNode();
        }
        return NW;
    }

    else if (quadrant == "NE")
    {
        if (NE == NULL)
        {
            NE = new TreeNode();
        }
        return NE;
    }

    else if (quadrant == "SE")
    {
        if (SE == NULL)
        {
            SE = new TreeNode();
        }
        return SE;
    }

    if (SW == NULL)
        SW = new TreeNode();

    return SW;
}

//Setters

void TreeNode::SetRootValue(CityInfo *rootValue)
{
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

void TreeNode::PrintTree()
{
    cout << "--------------------------------------------------------------" << endl;
    cout << "Nó raiz  : " << this->GetRootValue()->city_name << endl;
    if (this->GetNE())
        cout << "Ao NE :" << this->GetNE()->GetRootValue()->city_name << endl;
    if (this->GetSE())
        cout << "Ao SE :" << this->GetSE()->GetRootValue()->city_name << endl;
    if (this->GetSW())
        cout << "Ao SW :" << this->GetSW()->GetRootValue()->city_name << endl;
    if (this->GetNW())
        cout << "Ao Nw :" << this->GetNW()->GetRootValue()->city_name << endl;
    cout << "--------------------------------------------------------------" << endl;
}

TreeNode::~TreeNode()
{
}
