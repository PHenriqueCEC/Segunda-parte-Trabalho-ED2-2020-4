#include "HashTable.h"

HashTable::HashTable()
{
    this->size = 500;
    this->table.resize(size);
    this->collisions = 0;
}

HashTable::HashTable(unsigned long long _size)
{
    this->size = _size;
    this->table.resize(size);
    this->collisions = 0;
}

void HashTable::insert(CovidInfo *_CI)
{
    unsigned long long a = 0;

    for (unsigned long long i = 0; i < size; i++)
    {
        unsigned long long hashedKey = polynomialRollingHash(*_CI, a);

        if (table[hashedKey].city == "")
        {
            table[hashedKey] = *_CI;
            this->generatedHashs.push_back(hashedKey);
            break;
        }
        else
        {
            a++;
            collisions++;
        }
    }
}

CovidInfo *HashTable::search(float _cityCode, string _date)
{
    unsigned long long hashedKey = polynomialRollingHash(_cityCode, _date, 0);

    if (table[hashedKey].code == _cityCode and table[hashedKey].date == _date)
    {
        return addressof(table[hashedKey]);
    }
    else
    {
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

void HashTable::print(bool writeInFile)
{
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
            cout << "-------------------FileHandler(string directory);-------------------" << endl;
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
    //sortedIndexs.reserve(this->size);
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
    short p = 97;
    unsigned long long power_of_p = 1;
    unsigned long long hash_val = 0;
    string str = _CI.date + to_string(_CI.code);
    int strSize = str.size();

    for (int i = 0; i < strSize; i++)
    {
        hash_val = ((hash_val + (str[i] - 'a' + 1) * power_of_p) + _a) % size;
        power_of_p = (power_of_p * p) % size;
    }

    return hash_val;
}

unsigned long long HashTable::polynomialRollingHash(float _cityCode, string _date, unsigned long long _a)
{
    short p = 97;
    unsigned long long power_of_p = 1;
    unsigned long long hash_val = 0;
    string str = _date + to_string(_cityCode);
    int strSize = str.size();

    for (int i = 0; i < strSize; i++)
    {
        hash_val = ((hash_val + (str[i] - 'a' + 1) * power_of_p) + _a) % size;
        power_of_p = (power_of_p * p) % size;
    }

    return hash_val;
}

int HashTable::getSize()
{
    return this->table.size();
}