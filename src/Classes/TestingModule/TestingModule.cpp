#include "./TestingModule.h"

TestingModule::TestingModule()
{
}

TestingModule::~TestingModule()
{
}

void TestingModule::insertInQuadTree(int numberOfRegisters)
{
    clock_t startTime, finalTime;
    startTime = clock();
    FileHandler fileHandler;
    QuadTree *quadtree = fileHandler.insertCityListInQuadTree("brazil_cities_coordinates.csv", numberOfRegisters);

    if (quadtree->getSize() < 20)
        quadtree->print();
    else
        quadtree->writeTreeInTxtFile("saidaTestes.txt");

    finalTime = clock();

    cout << "Tempo de Processamento : " << (finalTime - startTime) / ((float)CLOCKS_PER_SEC) << " segundos" << endl;

    delete quadtree;
}

void TestingModule::insertInBTree(vector<long long int> values)
{
    ArvoreB *arvore = new ArvoreB(20);
    for (int value : values)
    {
        cout << "Value :  " << value << endl;
        arvore->inserir(value);
    }
    arvore->selecionarSaida();
}

void TestingModule::insertInAvlTree(vector<long long int> values)
{
    AvlTree *avlTree = new AvlTree();
    for (int value : values)
    {
        cout << "Value :  " << value << endl;
        avlTree->doInsert(value);
    }
    avlTree->doPrint(values.size() > 20);
}

void TestingModule::insertInHashTable(int numberOfRegisters)
{
    FileHandler fileHandler;
    HashTable *hash = fileHandler.insertCovidInfoInHashTable("", numberOfRegisters);
    hash->print(numberOfRegisters > 20);
}

void TestingModule::selectDataStructureToInsert(int choice)
{
    FileHandler fileHandler; 
    int numberOfRegisters;
    
    cout << "Digite o número de registros : " << endl;
    cin >> numberOfRegisters;

    switch (choice)
    {
        case 1:
        {
            this->insertInQuadTree(numberOfRegisters);
            break;
        }

        case 2:
        {
            HashTable *table = fileHandler.insertCovidInfoInHashTable("", numberOfRegisters);
            vector<long long int> hashedKeys = table->getHashedKeys();
            insertInBTree(hashedKeys);
            break;
        }

        case 3:
        {
            HashTable *table = fileHandler.insertCovidInfoInHashTable("", numberOfRegisters);
            vector<long long int> hashedKeys = table->getHashedKeys();
            insertInAvlTree(hashedKeys);
            break;
        }

        case 4:
        {
            this->insertInHashTable(numberOfRegisters);
            break;
        }
    }
}

void TestingModule::menu()
{
    int choice;
    while(choice >= 1 && choice <= 4){
        cout << endl << "----------Trabalho Estrutura de Dados Parte 2------------" << endl;
        cout << "Digite [1] para inserir registros na Quad Tree " << endl;
        cout << "Digite [2] para inserir registros na Arvore B " << endl;
        cout << "Digite [3] para inserir registros na Arvore Avl " << endl;
        cout << "Digite [4] para inserir registros na Tabela Hash" << endl;
        cout << "Digite [0] para encerrar o programa" << endl;
        cout << "---------------------------------------------------------------" << endl;
        cin >> choice;

        if (choice == 0)
            break;
        else if (choice > 4 || choice < 0)
            cout << "Opcao invalida! Digite novamente" << endl;
        else
            //Parte para a inserção na estrutura selecionada
            this->selectDataStructureToInsert(choice);
    }
}
