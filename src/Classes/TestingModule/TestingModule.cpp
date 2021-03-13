#include"./TestingModule.h"

TestingModule::TestingModule(){

}

TestingModule::~TestingModule(){

}


void TestingModule::insertInQuadTree(int numberOfRegisters){
    clock_t startTime,finalTime;
    startTime = clock();
    FileHandler fileHandler;
    QuadTree *quadtree =  fileHandler.insertCityListInQuadTree("brazil_cities_coordinates.csv",numberOfRegisters); 

    if(quadtree->getSize() < 20)
        quadtree->print();
    else
        quadtree->writeTreeInTxtFile("saidaTestes.txt");

    finalTime = clock();

    cout << "Tempo de Processamento : " << (finalTime - startTime) / ((float)CLOCKS_PER_SEC) << " segundos" << endl;


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


void TestingModule::insertInAvlTree(vector<int> values){
    AvlTree *avlTree = new AvlTree();
     for(int value : values){
         cout << "Value :  " << value << endl;
         avlTree->doInsert(value);
     }
     avlTree->print2D();
}

void TestingModule::insertInHashTable(int numberOfRegisters){
    FileHandler fileHandler;
    HashTable *hash = new HashTable(1400000);
    hash = fileHandler.insertCovidInfoInHashTable("",numberOfRegisters);
    cout << "Size da hash : " << hash->getSize() << endl;
    
}




void TestingModule::selectDataStructureToInsert(int choice){
    FileHandler fileHandler;
    int numberOfRegisters;
    cout << "Digite o número de registros : " << endl;
    cin >> numberOfRegisters;    

    switch(choice){
        case 1 : {
            this->insertInQuadTree(numberOfRegisters);
            break;
        }
        
        case 2 : {
            vector<int> aux;
            for(int i = 0; i < numberOfRegisters ; i++){
                aux.push_back(i);
            }
            insertInBTree(aux);
            break;
        }

        case 3 : {
            vector<int> aux;
            for(int i = 0; i < numberOfRegisters ; i++){
                aux.push_back(i);
            }
            insertInAvlTree(aux);
            break;
        }

        case 4 : {
            this->insertInHashTable(numberOfRegisters);
        }
        
    }
} 

void TestingModule::menu(){
    int choice;
    while(choice != 0){
    cout << "----------Trabalho Estrutura de Dados Parte 2------------" << endl;
    cout << "Digite [1] para inserir registros na Quad Tree " << endl;
    cout << "Digite [2] para inserir registros na Arvore B " << endl;
    cout << "Digite [3] para inserir registros na Arvore Avl " << endl;
    cout << "Digite [4] para inserir registros na Tabela Hash" << endl;
    cout << "Digite [0] para encerrar o programa" << endl;
    cout << "---------------------------------------------------------------" << endl;
    cin >> choice;
    //Parte para a inserção na estrutura selecionada
    this->selectDataStructureToInsert(choice);
    }

}


