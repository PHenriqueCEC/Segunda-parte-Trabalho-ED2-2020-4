#include "./Quadtree.h"

QuadTree::QuadTree()
{
    this->root = new TreeNode();
    size = 0;
}
//X = Latitude
//Y = Longitude
string QuadTree::GetQuadrant(CityInfo *inserted, CityInfo *toInsert)
{
    if (inserted->latitude < toInsert->latitude)
    {
        if (inserted->longitude < toInsert->longitude)
        {
            return "SW";
        }
        else
        {
            return "NW";
        }
    }
    else if (inserted->longitude < toInsert->longitude)
    {
        return "SE";
    }
    else
    {
        return "NE";
    }
}

void QuadTree::Insert(TreeNode *root, CityInfo *toInsert)
{
    //Arvore inicialmente vazia
    TreeNode *initialNode = this->root;
    if (this->root->GetRootValue()->isEmpty())
    {
        this->root->SetRootValue(toInsert);
    }
    else
    {
        string quadrant = this->GetQuadrant(this->root->GetRootValue(), toInsert);
        TreeNode *auxNode = initialNode->GetValueInQuadrant(quadrant);
        while (!auxNode->GetRootValue()->isEmpty())
        {
            quadrant = this->GetQuadrant(auxNode->GetRootValue(), toInsert);
            auxNode = auxNode->GetValueInQuadrant(quadrant);
        }
        auxNode->SetRootValue(toInsert);
        this->size++;
    }
}

bool QuadTree::find(CityInfo *value)
{
    TreeNode *aux = this->root;

    while (!aux->GetRootValue()->isEmpty())
    {
        //Vejo a qual quadrante o elemento deveria pertencer
        string quadrant = this->GetQuadrant(aux->GetRootValue(), value);
        aux = aux->GetValueInQuadrant(quadrant);
        if (aux->GetRootValue()->city_name == value->city_name)
            return true;
    }
    return false;
}

int QuadTree::getSize()
{
    return this->size;
}

void QuadTree::auxPrint(TreeNode *node){
    if(node != nullptr){
        cout << node->GetRootValue()->city_name << " ,";
        auxPrint(node->GetNE());
        auxPrint(node->GetNW());
        auxPrint(node->GetSE());
        auxPrint(node->GetSW());
    }
}

void QuadTree::print()
{
    this->auxPrint(this->root);
    cout << endl;
}
