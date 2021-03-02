#include "./Quadtree.h"

QuadTree::QuadTree()
{
    this->root = new TreeNode();
    size = 0;
}
//X = Latitude
//Y = Longitude
string QuadTree::getQuadrant(CityInfo *inserted, CityInfo *toInsert)
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

void QuadTree::insert(TreeNode *root, CityInfo *toInsert)
{
    //Arvore inicialmente vazia
    TreeNode *initialNode = this->root;
    if (this->root->getRootValue()->isEmpty())
    {
        this->root->setRootValue(toInsert);
    }
    else
    {
        string quadrant = this->getQuadrant(this->root->getRootValue(), toInsert);
        TreeNode *auxNode = initialNode->getValueInQuadrant(quadrant);
        while (!auxNode->getRootValue()->isEmpty())
        {
            quadrant = this->getQuadrant(auxNode->getRootValue(), toInsert);
            auxNode = auxNode->getValueInQuadrant(quadrant);
        }
        auxNode->setRootValue(toInsert);
        this->size++;
    }
}

bool QuadTree::find(CityInfo *value)
{
    TreeNode *aux = this->root;

    while (!aux->getRootValue()->isEmpty())
    {
        //Vejo a qual quadrante o elemento deveria pertencer
        string quadrant = this->getQuadrant(aux->getRootValue(), value);
        aux = aux->getValueInQuadrant(quadrant);
        if (aux->getRootValue()->city_name == value->city_name)
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
        cout << node->getRootValue()->city_name << " ,";
        auxPrint(node->getNE());
        auxPrint(node->getNW());
        auxPrint(node->getSE());
        auxPrint(node->getSW());
    }
}

void QuadTree::print()
{
    this->auxPrint(this->root);
    cout << endl;
}
