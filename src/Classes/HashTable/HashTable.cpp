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

void HashTable::insert(CovidInfo* _CI)
{
    unsigned long long a = 0;

    for(unsigned long long i = 0; i < size; i++)
    {
        unsigned long long hashedKey = polynomialRollingHash(*_CI, a);

        if(table[hashedKey].city == "")
        {
            table[hashedKey] = *_CI;
            break;
        }
        else
        {
            a++;
            collisions++;
        }
        
    }
}

CovidInfo* HashTable::search(float _cityCode, string _date) 
{
    unsigned long long hashedKey = polynomialRollingHash(_cityCode, _date, 0);
    
    if(table[hashedKey].code == _cityCode and table[hashedKey].date == _date)
    {
        return addressof(table[hashedKey]);
    }
    else
    {
        for(CovidInfo i:table)
        {
            if(i.code == _cityCode and i.date == _date)
            {
                return addressof(i);
            }
        }
    }
    return NULL;
}

void HashTable::print()
{
    for(CovidInfo i:table)
    {
        cout << "--------------------------------------" << endl;
        i.print();
        cout << "--------------------------------------" << endl;
    }
}

unsigned long long HashTable::polynomialRollingHash(CovidInfo _CI, unsigned long long _a)
{
    short p = 97;
    unsigned long long power_of_p = 1;
    unsigned long long hash_val = 0;
    string str = _CI.date + to_string(_CI.code);
    int strSize = str.size();
    
    for (int i = 0; i < strSize ; i++)
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
    
    for (int i = 0; i < strSize ; i++)
    {
        hash_val = ((hash_val + (str[i] - 'a' + 1) * power_of_p) + _a) % size;
        power_of_p = (power_of_p * p) % size;
    }

    return hash_val;
}