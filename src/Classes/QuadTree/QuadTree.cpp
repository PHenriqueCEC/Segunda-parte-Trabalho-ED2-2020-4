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

void QuadTree::auxPrint(TreeNode *node)
{
    if (node != nullptr)
    {
        cout << "--------------------------------------------------------" << endl;
        cout << "Cidade :  " << node->getRootValue()->city_name << endl;
        cout << "Latitude :  " << node->getRootValue()->latitude << endl;
        cout << "longitude :  " << node->getRootValue()->longitude << endl;
        cout << "Código :  " << node->getRootValue()->city_code << endl;
        cout << "--------------------------------------------------------" << endl;
        auxPrint(node->getNE());
        auxPrint(node->getNW());
        auxPrint(node->getSE());
        auxPrint(node->getSW());
    }
}

void QuadTree::writeTreeInTxtFile(string filename)
{
    ofstream arq("saidaTestes.txt");
    this->auxWriteTreeInTxtFile(this->root, arq);

    arq << endl;

    cout << "Arquivo de saída criado com sucesso, o nome do mesmo eh : saidaTestes.txt" << endl;
}

void QuadTree::auxWriteTreeInTxtFile(TreeNode *node, ofstream &arq)
{
    if (node != nullptr)
    {
        arq << "--------------------------------------------------------" << endl;
        arq << "Cidade :  " << node->getRootValue()->city_name << endl;
        arq << "Latitude :  " << node->getRootValue()->latitude << endl;
        arq << "longitude :  " << node->getRootValue()->longitude << endl;
        arq << "Código :  " << node->getRootValue()->city_code << endl;
        arq << "--------------------------------------------------------" << endl;

        auxWriteTreeInTxtFile(node->getNE(), arq);
        auxWriteTreeInTxtFile(node->getNW(), arq);
        auxWriteTreeInTxtFile(node->getSE(), arq);
        auxWriteTreeInTxtFile(node->getSW(), arq);
    }
}

void QuadTree::print()
{
    this->auxPrint(this->root);
    cout << endl;
}

vector<string> QuadTree::getCitysInCoordinates(Coordinate *coordinates)
{
    vector<string> citysInRange;
    auxGetCitysInCoordinates(this->root, coordinates, citysInRange);

    return citysInRange;
}

void QuadTree::auxGetCitysInCoordinates(TreeNode *node, Coordinate *coordinates, vector<string> &citysInRange)
{
    if (node != nullptr)
    {
        //Verifico se existe uma cidade no valor raiz do nó, e se ela esta no intervalo a ser comparado
        if (!node->getRootValue()->isEmpty())
        {
            float currentLatitude = node->getRootValue()->latitude;
            float currentLongitude = node->getRootValue()->longitude;

            if ((currentLatitude > coordinates->x1 && currentLatitude < coordinates->x2) &&
                (currentLongitude > coordinates->y1 && currentLongitude < coordinates->y2))
            {
                //Salvo o código da cidade no meu vetor de citys In Range
                citysInRange.push_back(node->getRootValue()->city_code);
            }

            auxGetCitysInCoordinates(node->getNE(), coordinates, citysInRange);
            auxGetCitysInCoordinates(node->getSE(), coordinates, citysInRange);
            auxGetCitysInCoordinates(node->getNW(), coordinates, citysInRange);
            auxGetCitysInCoordinates(node->getSW(), coordinates, citysInRange);
        }
    }
}

TreeNode *QuadTree::clean(TreeNode *node)
{
    if (node != NULL && !node->getRootValue()->isEmpty())
    {
        node->setNE(clean(node->getValueInQuadrant("NE")));
        node->setNW(clean(node->getValueInQuadrant("NW")));
        node->setSE(clean(node->getValueInQuadrant("SE")));
        node->setSW(clean(node->getValueInQuadrant("SW")));
        delete node;
        node = NULL;
    }

    return NULL;
}

QuadTree::~QuadTree()
{
    this->root = this->clean(this->root);
}
