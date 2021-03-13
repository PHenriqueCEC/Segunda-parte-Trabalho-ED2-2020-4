#include"./TestingModule.h"

TestingModule::TestingModule(){

}

TestingModule::~TestingModule(){

}


void TestingModule::insertInQuadTree(vector<CityInfo*> &data){
    QuadTree *quadtree = new QuadTree();
    for(CityInfo *city : data){
        quadtree->insert(quadtree->root,city);
    }

    if(quadtree->getSize() < 20)
        quadtree->print();
    else
        quadtree->writeTreeInTxtFile("saidaTestes.txt");

    delete quadtree;
}

void TestingModule::insertInBTree(vector<int> values){
    ArvoreB *arvore = new ArvoreB(20);
     for(int value : values){
         cout << "Value :  " << value << endl;
         arvore->inserir(value);
     }
     arvore->imprimir();
}


void TestingModule::selectDataStructureToInsert(int choice){
    FileHandler fileHandler;
    int numberOfRegisters;
    cout << "Digite o número de registros : " << endl;
    cin >> numberOfRegisters;
    //Obtenção dos n registros
    

    switch(choice){
        case 1 : {
            fileHandler.processCityInfoList("brazil_cities_coordinates.csv");
            vector<CityInfo*> randomCitys = fileHandler.getNRandomCityInfo(numberOfRegisters);
            insertInQuadTree(randomCitys);
            break;
        }
        
        case 2 : {
            vector<int> aux;
            for(int i = 0; i < 100 ; i++){
                cout << "i " << i <<endl;
                aux.push_back(i);
            }
            insertInBTree(aux);
            break;
        }
        
    }
} 

void TestingModule::menu(){
    int choice;
    while(choice != 0){
    cout << "----------💻️ Trabalho Estrutura de Dados Parte 2 💻️------------" << endl;
    cout << "Digite [1] para inserir registro na Quad Tree " << endl;
    cout << "Digite [2] para inserir registro na Árvore Avl " << endl;
    cout << "Digite [3] para inserir registro na Árvore B " << endl;
    cout << "Digite [0] para encerrar o programa" << endl;
    cout << "---------------------------------------------------------------" << endl;
    cin >> choice;

    //Parte para a inserção na estrutura selecionada
    this->selectDataStructureToInsert(choice);
    }

}


