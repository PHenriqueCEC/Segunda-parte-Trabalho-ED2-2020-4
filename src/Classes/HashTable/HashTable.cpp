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

vector<CovidInfo> HashTable::getCityInfoByKey(unsigned long long key)
{
    vector<CovidInfo> c(table);
    vector<CovidInfo> r;
    bool foundIt = false;

    c.shrink_to_fit();
    sort(c.begin(), c.end());

    if((table[key].city[0] >= 'a' and table[key].city[0] <= 'm') or (table[key].city[0] >= 'A' and table[key].city[0] <= 'M'))
    {
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
    {
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
{
    ofstream arq("saidaTestes.txt");
    cout << "A saída sera salva no arquivo : saidaTestes.txt";
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

     cout << endl << "A saída foi salva no arquivo  saidaTestes.txt";
}

vector<long long int> HashTable::getHashedKeys()
{
    return this->generatedHashs;
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