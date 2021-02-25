#include "./Quadtree.h"

QuadTree::QuadTree()
{
    this->root = new TreeNode();
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
    }
}

bool QuadTree::Find(CityInfo *value)
{
    TreeNode *aux = this->root;

    while (!aux->GetRootValue()->isEmpty())
    {
        //Vejo a qual quadrante o elemento deveria pertencer
        string quadrant = this->GetQuadrant(this->root->GetRootValue(), value);
        aux = aux->GetValueInQuadrant(quadrant);
        if (aux->GetRootValue()->city_name == value->city_name)
            return true;
    }
    return false;
}

void QuadTree::Print()
{
    TreeNode *aux = new TreeNode();

    aux = this->root;
    this->root->PrintTree();
    aux = aux->GetNW();
    while (aux != nullptr)
    {
        aux->PrintTree();
        aux = aux->GetNW();
    }
    /*
    cout << "----------------------------------------------------------------------" << endl;
    aux = this->root;
    cout << "Nó de referência  : " << aux->GetRootValue()->city_name << endl;
    bool is = aux->GetRootValue()->isEmpty();
    cout << "SW " << endl;

    while (aux != nullptr)
    {
        cout << aux->GetRootValue()->city_name << endl;
        aux = aux->GetSW();
    }
    aux = this->root;
    cout << "SE " << endl;        cout << "Quadrante " << quadrant << endl;

    aux = aux->GetSE();
    while (aux != nullptr)
    {
        cout << aux->GetRootValue()->city_name << endl;
        aux = aux->GetSE();
    }        cout << "Quadrante " << quadrant << endl;

    cout << endl;
    aux = this->root;
    cout << "NE " << endl;
    aux = aux->GetNE();
    while (aux != nullptr)
    {
        cout << aux->GetRootValue()->city_name << endl;
        aux = aux->GetNE();
    }
    cout << endl;
    /*
    cout << "Tem ao SW : " << this->root->GetSW()->GetRootValue()->city_name << endl;
    cout << "Tem ao SE : " << this->root->GetSE()->GetRootValue() << endl;
    cout << "Tem ao NE : " << this->root->GetNE()->GetRootValue() << endl;
    cout << "Tem ao NW : " << this->root->GetNW()->GetRootValue() << endl;
    */
}
