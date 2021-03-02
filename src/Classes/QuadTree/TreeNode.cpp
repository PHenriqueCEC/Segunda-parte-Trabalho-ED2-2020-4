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
TreeNode *TreeNode::getNW()
{
    return this->NW;
}

TreeNode *TreeNode::getSE()
{
    return this->SE;
}

TreeNode *TreeNode::getNE()
{
    return this->NE;
}

TreeNode *TreeNode::getSW()
{
    return this->SW;
}

CityInfo *TreeNode::getRootValue()
{
    return this->rootValue;
}

TreeNode *TreeNode::getValueInQuadrant(string quadrant)
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

void TreeNode::setRootValue(CityInfo *rootValue)
{
    this->rootValue = rootValue;
}

void TreeNode::setNW(TreeNode *NW)
{
    this->NW = NW;
}

void TreeNode::setSE(TreeNode *SE)
{
    this->SE = SE;
}

void TreeNode::setNE(TreeNode *NE)
{
    this->NE =NE;
}

void TreeNode::setSW(TreeNode *SW)
{
    this->SW = SW;
}

void TreeNode::insertInQuadrant(string quadrant, CityInfo *value)
{
    if (quadrant == "SE")
    {
        this->SE = new TreeNode();
        this->SE->setRootValue(value);
        return;
    }
    else if (quadrant == "SW")
    {
        this->SW = new TreeNode();
        this->SW->setRootValue(value);
        return;
    }
    if (quadrant == "NE")
    {
        this->NE = new TreeNode();
        this->NE->setRootValue(value);
        return;
    }
    if (quadrant == "NW")
    {
        this->NW = new TreeNode();
        this->NW->setRootValue(value);
        return;
    }
}
/*
void TreeNode::print()
{
    auxPrintTree(this->GetNW());
    auxPrintTree(this->GetSW());
    auxPrintTree(this->GetSE());
    auxPrintTree(this->GetNE());
}

void TreeNode::auxPrint(TreeNode *tree)
{
    cout << "--------------------------------------------------------------" << endl;
    if (tree)
    {
        cout << "Nó raiz  : " << tree->GetRootValue()->city_name << endl;
        if (tree->GetNE())
            cout << "Ao NE :" << tree->GetNE()->GetRootValue()->city_name << endl;
        if (tree->GetSE())
            cout << "Ao SE :" << tree->GetSE()->GetRootValue()->city_name << endl;
        if (tree->GetSW())
            cout << "Ao SW :" << tree->GetSW()->GetRootValue()->city_name << endl;
        if (tree->GetNW())
            cout << "Ao NW " << tree->GetNW()->GetRootValue()->city_name << endl;
    }
}

*/
TreeNode::~TreeNode()
{
}
