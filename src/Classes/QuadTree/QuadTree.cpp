#include "./Quadtree.h"

QuadTree::QuadTree()
{
    this->root = NULL;
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

void QuadTree::Insert(TreeNode *root,CityInfo* toInsert){
    //Arvore inicialmente vazia
    if(root == NULL){
        root->SetRootValue(toInsert);
    }else{
        string quadrant = this->GetQuadrant(this->root->GetRootValue(),toInsert);
        CityInfo *quadrantPointer = root->GetValueInQuadrant(quadrant);
        quadrantPointer = toInsert;
    }
}

void QuadTree::Print(){
    cout << "Nó de referência  : " << this->root->GetRootValue()->city_name << endl;
    cout << "Tem ao SW : " << this->root->GetSW()->city_name << endl;
    cout << "Tem ao SE : " << this->root->GetSE()->city_name << endl;
    cout << "Tem ao NE : " << this->root->GetNE()->city_name << endl;
    cout << "Tem ao NW : " << this->root->GetNW()->city_name << endl;
}