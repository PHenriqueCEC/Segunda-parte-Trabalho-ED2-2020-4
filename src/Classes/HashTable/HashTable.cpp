#include "HashTable.h"

HashTable::HashTable()
{//Instancia básica, com 500 posições na tabela
    this->size = 500;
    this->table.resize(size);
    this->collisions = 0;
}

HashTable::HashTable(unsigned long long _size)
{//Instancia da Tabela Hash com tamanho pelo usuário
    this->size = _size;
    this->table.resize(size);
    this->collisions = 0;
}

void HashTable::insert(CovidInfo *_CI)
{
    unsigned long long a = 0;

    for (unsigned long long i = 0; i < size; i++)
    {
        unsigned long long hashedKey = polynomialRollingHash(*_CI, a); //Calcula o valor hasheado associado a chave

        if (table[hashedKey].city == "")
        {//Se o índice está vazio, insere o valor, e encerra a função
            table[hashedKey] = *_CI;
            this->generatedHashs.push_back(hashedKey);
            break;
        }
        else
        {//Caso o contrário, incremenda a e o número de colisões e volta ao início do loop para calcular um novo valor hash
            a++;
            collisions++;
        }
    }
}

CovidInfo *HashTable::search(float _cityCode, string _date)
{
    unsigned long long hashedKey = polynomialRollingHash(_cityCode, _date, 0);

    if (table[hashedKey].code == _cityCode and table[hashedKey].date == _date)
    { //Se a entrada procurada está no primeiro valor para onde foi hasheada, já é retornada
        return addressof(table[hashedKey]);
    }
    else
    { //Se não, ela é buscada pela tabela
        for (CovidInfo i : table)
        {
            if (i.code == _cityCode and i.date == _date)
            {
                return addressof(i);
            }
        }
    }
    return NULL;
}

vector<CovidInfo> HashTable::getCityInfoByKey(unsigned long long key)
{
    vector<CovidInfo> c(table); //Instancia copia da tabela hash
    vector<CovidInfo> r; //Instancia futuro retorno com as cidades requeridas
    bool foundIt = false; //Flag simboliza ter encontrado o bloco de valores

    c.shrink_to_fit(); //Compacta a cópia da tabela ao tamanho do número de valores realmente inseridos, evitando comparações desnecesárias
    sort(c.begin(), c.end()); //Ordena a cópia da tabela usandoa função sort e um overload do operador < criado para a classe CovidInfo

    //Verifica o nome da cidade para, através da ordenação em ordem alfabética feita anteriormente, diminuir o número de iterações começando a busca do início do vetor ou do final
    if((table[key].city[0] >= 'a' and table[key].city[0] <= 'm') or (table[key].city[0] >= 'A' and table[key].city[0] <= 'M'))
    {//Se a cidade desejada começa com as lestras de 'a' a 'm', a iterações ocorrem de 0 para frente
        for(unsigned long long i = 0; i < size; i++)
        {
            if(c[i].city == table[key].city)
            {
                r.push_back(c[i]);
                foundIt = true;
            }
            else if(c[i].city != table[key].city and foundIt)
                break;
        }
    }
    else if((table[key].city[0] >= 'n' and table[key].city[0] <= 'z') or (table[key].city[0] >= 'N' and table[key].city[0] <= 'Z'))
    {//Se a cidade desejada começa com as lestras de 'n' a 'z', a iterações ocorrem de size-1 para trás
        for(unsigned long long i = size-1; i >= 0; i--)
        {
            if(c[i].city == table[key].city)
            {
                r.push_back(c[i]);
                foundIt = true;
            }
            else if(c[i].city != table[key].city and foundIt)
                break;
        }
    }

    return r;
}

void HashTable::print(bool writeInFile)
{//Função de impressão no terminal ou gravação em um arquivo dado
    ofstream arq("saidaTestes.txt");
    cout << endl
         << "A saída sera salva no arquivo : saidaTestes.txt";
    for (CovidInfo i : table)
    {
        if (writeInFile)
        {
            arq << "--------------------------------------" << endl;
            i.printInFile(arq);
            arq << "--------------------------------------" << endl;
        }
        else
        {
            cout << "--------------------------------------" << endl;
            i.print();
            cout << "--------------------------------------" << endl;
        }
    }

    cout << endl
         << "A saída foi salva no arquivo  saidaTestes.txt";
}

vector<long long int> HashTable::getHashedKeys()
{
    return this->generatedHashs;
}

vector<long long int> HashTable::getNRandomElements(int numberOfElements)
{
    vector<bool> sortedIndexs;
    std::random_device device;
    std::mt19937 generator(device());
    //Coloco que os indices a ser gerados vão de 0 ao tamanho da minha hash
    std::uniform_int_distribution<int> distribution(0, this->size);
    vector<long long int> sortedElements;
    int drawn = 0;

    //Vetor auxiliar para eu controlar quais indices ja foram gerados
    vector<bool> usedIndexs;
    for (int i = 0; i < this->size; i++)
        usedIndexs.push_back(false);

    for (int i = 0; i < numberOfElements; i++)
    {
        //Garanto que o indice que gerei ainda não foi utilizado , para não ocorrerem duplicatas.
        drawn = distribution(generator);
        while (usedIndexs[drawn]){
            drawn = distribution(generator);
        }
        
        //Como a hash pode ter posições vazias, verifico se a posição gerada tem algum elemento
  
        if (table[drawn].city != "")
        {
            //Adiciono o índice sorteado no meu vetor, que é a propria chave hash
            sortedElements.push_back(drawn);
            //Adiciono o número sorteado no meu vetor de indices já sorteados
            usedIndexs[drawn] = true;
        }
    }

    //Desalocando vetor de bools auxiliar da memória
    usedIndexs.~vector();
    return sortedElements;
}

unsigned long long HashTable::polynomialRollingHash(CovidInfo _CI, unsigned long long _a)
{
    short p = 97; //Primo com número mais próximos do número de caracteres possíveis na string
    unsigned long long power_of_p = 1; //Inicialização 
    unsigned long long hash_val = 0; //Inicialização 
    string str = _CI.date + to_string(_CI.code); //Concatenação das duas keys
    int strSize = str.size(); //Tamanho total da string concatenada

    for (int i = 0; i < strSize; i++)
    { //Iterações do algoritmo PRH
        hash_val = ((hash_val + (str[i] - 'a' + 1) * power_of_p) + _a) % size;
        power_of_p = (power_of_p * p) % size;
    }

    return hash_val;
}

unsigned long long HashTable::polynomialRollingHash(float _cityCode, string _date, unsigned long long _a)
{
    short p = 97; //Primo com número mais próximos do número de caracteres possíveis na string
    unsigned long long power_of_p = 1; //Inicialização
    unsigned long long hash_val = 0; //Inicialização
    string str = _date + to_string(_cityCode); //Concatenação das duas keys
    int strSize = str.size(); //Tamanho total da string concatenada

    for (int i = 0; i < strSize; i++)
    { //Iterações do algoritmo PRH
        hash_val = ((hash_val + (str[i] - 'a' + 1) * power_of_p) + _a) % size;
        power_of_p = (power_of_p * p) % size;
    }

    return hash_val;
}

vector<CovidInfo> HashTable::getValues(){
    return this->table;
}


long int HashTable::getAllCasesInCity(int cityCode, int &comparisions,float &elapsedTime){
    clock_t startTime, finalTime;
    startTime = clock();

    //Contador de casos
    long int cases = 0;

    for(CovidInfo city : this->table){
        if(city.code == cityCode){
            cases+= city.cases; //Contando a quantidade total de casos encontrados
            comparisions++;
        }
    }
    finalTime = clock();
    cout << "Casos encontrados na cidade : "  <<  abs(cases) << endl;
    elapsedTime = (finalTime - startTime) / ((float)CLOCKS_PER_SEC);

    return cases;
}

int HashTable::getSize()
{//Tamanho da tabela
    return this->table.size();
}