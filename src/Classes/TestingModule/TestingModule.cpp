#include "./TestingModule.h"

TestingModule::TestingModule(string directory)
{
    this->directory = directory;
}

TestingModule::~TestingModule()
{
}

void TestingModule::insertInQuadTree(int numberOfRegisters)
{
    clock_t startTime, finalTime;
    startTime = clock();
    FileHandler fileHandler(this->directory);
    QuadTree *quadtree = fileHandler.insertCityListInQuadTree(numberOfRegisters);

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
        arvore->inserir(value);
    }
    arvore->selecionarSaida();
}

void TestingModule::insertInAvlTree(vector<long long int> values)
{
    AvlTree *avlTree = new AvlTree();
    for (int value : values)
    {
        avlTree->doInsert(value);
    }
    avlTree->doPrint(values.size() > 20);
}

void TestingModule::insertInHashTable(int numberOfRegisters)
{
    FileHandler fileHandler(this->directory);
    float time;
    HashTable *hash = fileHandler.insertCovidInfoInHashTable(numberOfRegisters, time);
    hash->print(numberOfRegisters > 20);
}

void TestingModule::selectDataStructureToInsert(int choice)
{
    FileHandler fileHandler(this->directory);
    int numberOfRegisters;
    if (choice != 5)
    {
        cout << "Digite o número de registros : " << endl;
        cin >> numberOfRegisters;
    }
    float time;
    switch (choice)
    {
    case 1:
    {
        this->insertInQuadTree(numberOfRegisters);
        break;
    }

    case 2:
    {
        HashTable *table = fileHandler.insertCovidInfoInHashTable(numberOfRegisters, time);
        vector<long long int> hashedKeys = table->getHashedKeys();
        insertInBTree(hashedKeys);
        break;
    }

    case 3:
    {
        HashTable *table = fileHandler.insertCovidInfoInHashTable(numberOfRegisters, time);
        vector<long long int> hashedKeys = table->getHashedKeys();
        insertInAvlTree(hashedKeys);
        break;
    }

    case 4:
    {
        this->insertInHashTable(numberOfRegisters);
        break;
    }
    case 5:
    {
        cout << "Os resultados serão salvos no arquivo SaidaEstatistica.txt" << endl;
        cout << "Digite o valor de M " << endl;
        int M;
        cin >> M;
        this->generateStatistics(M);
    }
    }
}

void TestingModule::generateStatistics(int M)
{
    //Valores n para os testes
    // M de 100000 , M de 50000k e tal
    clock_t startTime, finalTime;
    int numberOfTests[5] = {10000, 50000, 100000, 500000, 1000000};
    FileHandler fileHandler(directory);
    //Insere os 1000000 de  registros na tabela hash e retorna um ponteiro
    //para a tabela criada
    ofstream arq("SaidaEstatistica.txt");
    arq << "Modulo de Estatísticas M = " << M << endl;
    cout << "-------------------------------------------------" << endl;
    float time;
    HashTable *hashTable = fileHandler.insertCovidInfoInHashTable(1000000, time);

    arq << "Tempo para inserçaõ de 1000000 na tabela hash : " << time << endl;

    int comparacoes;

    float averageTimeArvB = 0;
    float averageTimeBLarge = 0;
    float averageTimeArvAvl = 0;

    long int comparisionArvB = 0;
    long int comparisionArvBLarge = 0;
    long int comparisionAvl = 0;

    startTime = clock();

    //Para cada valor de N obter M conjuntos e obter o tempo médio
    for (int n : numberOfTests)
    {

        averageTimeArvAvl = 0;
        averageTimeArvB = 0;
        averageTimeBLarge = 0;

        for (int i = 0; i < M; i++)
        {
            //Tempo de geração dos n numeros aleatórios
            startTime = clock();
            vector<long long int> hashs = hashTable->getNRandomElements(n);
            finalTime = clock();

            averageTimeArvAvl += finalTime - startTime;
            averageTimeArvB += finalTime - startTime;
            averageTimeBLarge += finalTime - startTime;

            //-----------------------------------------------------------*/
            ArvoreB *arvBLarge = new ArvoreB(200);
            ArvoreB *arvB = new ArvoreB(20);
            AvlTree *avl = new AvlTree();

            //Inserção das n hashs na arvB e arvAvl
            for (long long int hash : hashs)
            {
                //Insiro as hashs na arvB e Avl
                startTime = clock();
                arvB->inserir(hash);
                finalTime = clock();
                averageTimeArvB += finalTime - startTime;

                startTime = clock();
                arvBLarge->inserir(hash);
                finalTime = clock();
                averageTimeBLarge += finalTime - startTime;

                startTime = clock();
                avl->doInsert(hash);
                finalTime = clock();
                averageTimeArvAvl += finalTime - startTime;
            }
            comparisionArvB += arvB->numComparacoesInsercao;
            comparisionAvl += avl->getInsertComparisons();
            comparisionArvBLarge += arvBLarge->numComparacoesInsercao;

            finalTime = clock();
            cout << i + 1 << "º  de " << n << endl;
        }
        arq << "Tempo Médio Inserção de : " << n << " registros " << M << " vezes "
            << " Na Árvore Avl : " << (averageTimeArvAvl / M) / ((float)CLOCKS_PER_SEC) << " segundos" << endl
            << "Comparações Médias : " << comparisionAvl << endl
            << endl;

        arq << "Tempo Médio Inserção de : " << n << " registros " << M << " vezes "
            << " Na Árvore B com d = 20 : " << (averageTimeArvB / M) / ((float)CLOCKS_PER_SEC) << " segundos" << endl
            << "Comparações Médias : " << comparisionArvB << endl
            << endl;

        arq << "Tempo Médio Inserção de : " << n << " registros " << M << " vezes "
            << " Na Árvore B com d = 200 : " << (averageTimeBLarge / M) / ((float)CLOCKS_PER_SEC) << " segundos" << endl
            << "Comparações Médias : " << comparisionArvBLarge << endl
            << endl;

        arq << "-------------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------------------------------------------------------" << endl;
    }

    /*
        vector<int> teste = avl->doGetUniqueCitys(hashTable);
        for (int cityCode : teste)
        {
            cout << "Casos Acrelândia : " << hashTable->getAllCasesInCity(cityCode, comparacoes, tempo) << endl;
            cout << "Tempo : " << tempo << endl;
            cout << "Comparações  : " << comparacoes << endl;
        }
        */

    //Chamo o destrututor para limpar a memória
    /*
    cout << "---------------------------------";
    cout << "Digite o tipo de busca" << endl;
    cout << "Digite [1] para busca S1" << endl;
    cout << "Digite [2] para busca S2" << endl;
    cout << "----------------------------------";
    finalTime = clock();
    cout << "Tempo de Processamento : " << (finalTime - startTime) / ((float)CLOCKS_PER_SEC) << " segundos" << endl;
    */
}

void TestingModule::testingModuleMenu()
{
    int choice = 1;
    while (choice >= 1 && choice <= 2)
    {
        choice = 0;
        cout << endl
             << "------------------------------------Trabalho Estrutura de Dados Parte 2------------------------------------" << endl;
        cout << "Digite [1] para ir ao modulo de testes " << endl;
        cout << "Digite [2] para ir para o modulo de estatísticas" << endl;
        cout << "Digite qualquer outro valor para encerrar o programa" << endl;
        cout << "------------------------------------------------------------------------------------------------------------" << endl;
        cin >> choice;

        if (choice == 1)
        {
            while (choice >= 1 && choice <= 4)
            {
                cout << endl << "------------Trabalho Estrutura de Dados Parte 2--------------" << endl;
                cout << "Digite [1] para inserir registros na Quad Tree " << endl;
                cout << "Digite [2] para inserir registros na Arvore B " << endl;
                cout << "Digite [3] para inserir registros na Arvore Avl " << endl;
                cout << "Digite [4] para inserir registros na Tabela Hash" << endl;
                cout << "Digite [5] sair do programa" << endl;
                cout << "---------------------------------------------------------------" << endl;
                cin >> choice;
                if(choice != 5)
                    this->selectDataStructureToInsert(choice);
                else 
                    break;
            }
        }
        else if (choice == 2)
        {
            //Vai chamar o modulo de estatisticas
            this->selectDataStructureToInsert(5);
        }
        //Parte para a inserção na estrutura selecionada
    }
}
