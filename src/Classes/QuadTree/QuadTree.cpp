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
    cout << "No insert chego " << endl;
    //Arvore inicialmente vazia
    TreeNode *initialNode = this->root;
    if (this->root->GetRootValue()->isEmpty())
    {
        this->root->SetRootValue(toInsert);
    }
    else
    {
        string quadrant = this->GetQuadrant(this->root->GetRootValue(), toInsert);
        cout << "Quadrante " << quadrant << endl;
        TreeNode *auxNode = initialNode->GetValueInQuadrant(quadrant);
        while (!auxNode->GetRootValue()->isEmpty())
        {
            cout << "Node atual " << auxNode->GetRootValue()->city_name << endl;
            quadrant = this->GetQuadrant(auxNode->GetRootValue(), toInsert);
            auxNode = auxNode->GetValueInQuadrant(quadrant);
        }
        auxNode->SetRootValue(toInsert);
    }
}

void QuadTree::Print()
{
    TreeNode* aux = new TreeNode();
    cout << aux;
    cout << root;
    cout << "----------------------------------------------------------------------" << endl;
    cout << "Nó de referência  : " << this->root->GetRootValue()->city_name << endl;
    cout << "Ao Sudeste : ";
    while(!aux->GetRootValue()->isEmpty()){
        cout << aux->GetRootValue()->city_name << " ";
        aux = aux->GetNW();
    }
    cout << endl;
    /*
    cout << "Tem ao SW : " << this->root->GetSW()->GetRootValue()->city_name << endl;
    cout << "Tem ao SE : " << this->root->GetSE()->GetRootValue() << endl;
    cout << "Tem ao NE : " << this->root->GetNE()->GetRootValue() << endl;
    cout << "Tem ao NW : " << this->root->GetNW()->GetRootValue() << endl;
    */
}
