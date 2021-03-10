#include "HashTable.h"

HashTable::HashTable()
{
    this->M = 4;
    this->B = 2;

    int dESize = pow(2, this->B);

    for(int i = 0; i < dESize; i++)
    {
        Bucket *b = new Bucket(this->M, convertDecToSTRBin(i));
        row *newRow = new row(convertDecToSTRBin(i), b); 
        rows.push_back(newRow);
    }
}

HashTable::HashTable(int _M, int _B)
{
    this->M = _M;
    this->B = _B;

    int dESize = pow(2, this->B);

    for(int i = 0; i < dESize; i++)
    {
        Bucket *b = new Bucket(this->M, convertDecToSTRBin(i));
        row *newRow = new row(convertDecToSTRBin(i), b); 
        rows.push_back(newRow);
    }
}

void HashTable::setM(int _M)
{
    this->M = _M;
}

void HashTable::setB(int _B)
{
    this->B = _B;
}

int HashTable::getM()
{
    return this->M;
}

int HashTable::getB()
{
    return this->B;
}

void HashTable::insert(CovidInfo _CI)
{
    string hashedKey = convertDecToSTRBin(polynomialRollingHash(_CI));
    string firstB_Key = getFirstBDigits(hashedKey);
    bool inserted = false;

    for(row* i:rows)
    {
        if(i->first == firstB_Key)
        {
            if(i->first != i->second->getBucketKey())
            {
                divideBucket(i);
                i->second->addValue(_CI);
                inserted = true;
            }
            else if(!i->second->addValue(_CI))
            {
                duplicateHashTable();
                inserted = true;
                break;
            }
        }
    }

    if(!inserted)
    {
        for(row* j:rows)
        {
            if(j->first == firstB_Key)
            {
                if(j->first != j->second->getBucketKey())
                {
                    divideBucket(j);
                    j->second->addValue(_CI);
                }
            }   
        }
    }
}

CovidInfo HashTable::search(float _cityCode, string _date) 
{
    string hashedKey = convertDecToSTRBin(polynomialRollingHash(_cityCode, _date));
    string firstB_Key = getFirstBDigits(hashedKey);

    for(row* i:rows)
    {
        if(i->first == firstB_Key)
        {
            for(CovidInfo j:i->second->getValues())
            {
                if(j.code == _cityCode and j.date == _date)
                {
                    return j;
                }
            }
        }
    }
}

void HashTable::remove(float _cityCode, string _date)
{
    string hashedKey = convertDecToSTRBin(polynomialRollingHash(_cityCode, _date));
    string firstB_Key = getFirstBDigits(hashedKey);

    for(row *i:rows)
    {
        if(i->first == firstB_Key)
        {
            i->second->removeValue(hashedKey);
        }
    }
}

void HashTable::print()
{
    
}

long long HashTable::polynomialRollingHash(CovidInfo _CI)
{
    // P and M
    int p = 97;
    int m = 1e9 + 9;
    long long power_of_p = 1;
    long long hash_val = 0;
    string str = _CI.date + to_string(_CI.code);
    int strSize = str.size();
    
    // Loop to calculate the hash value
    // by iterating over the elements of string
    for (int i = 0; i < strSize ; i++)
    {
        hash_val = (hash_val + (str[i] - 'a' + 1) * power_of_p) % m;
        power_of_p = (power_of_p * p) % m;
    }

    return hash_val;
}

long long HashTable::polynomialRollingHash(float _cityCode, string _date)
{
    // P and M
    int p = 97;
    int m = 1e9 + 9;
    long long power_of_p = 1;
    long long hash_val = 0;
    string str = _date + to_string(_cityCode);
    int strSize = str.size();
    
    // Loop to calculate the hash value
    // by iterating over the elements of string
    for (int i = 0; i < strSize ; i++)
    {
        hash_val = (hash_val + (str[i] - 'a' + 1) * power_of_p) % m;
        power_of_p = (power_of_p * p) % m;
    }

    return hash_val;
}

string HashTable::getFirstBDigits(string _info)
{
    return _info.substr(0, this->B);
}

string HashTable::convertDecToSTRBin(long long _dec)
{
    vector<short> binaryNum; 
    string STRBin;
  
    int i = 0; 
    
    while (_dec > 0)
    { 
        binaryNum.push_back(_dec%2); 
        _dec =_dec / 2; 
        i++; 
    }

    if(i == 0 and _dec == 0)
    {
        binaryNum.push_back(0);
        i++;
    }

    while(i < B)
    {
        binaryNum.push_back(0);
        i++;
    }

    reverse(binaryNum.begin(), binaryNum.end());

    for(int i = 0; i < binaryNum.size(); i++)
    {
        STRBin += to_string(binaryNum[i]);
    }
    
    return STRBin;
}

void HashTable::divideBucket(row *r)
{
    Bucket *b = new Bucket(this->M, r->first);

    for(CovidInfo j:r->second->getValues())
    {
        string h = convertDecToSTRBin(polynomialRollingHash(j));
        if(getFirstBDigits(h) != r->second->getBucketKey())
        {
            b->addValue(r->second->popValue(h));
        }
    }

    r->second = b;
}

void HashTable::duplicateHashTable()
{
    B*=2;
    int i = 0;
    int j = 0;

    while(i != B/2)
    {
        auto it = rows.begin();

        if(i == 0)
        {
            row *newRow = new row();
            newRow->second = addressof(**it)->second;
            rows.insert(it, newRow);
            i++;
            continue;
        }
        row *newRow = new row();
        newRow->second = addressof(**(it+(2*i)))->second;
        rows.insert(it+(2*i), newRow);
        i++;
    }

    for(auto it = rows.begin(); it != rows.end(); it++)
    {
        addressof(**it)->first = getFirstBDigits(convertDecToSTRBin(j));
        j++;
    }
}
