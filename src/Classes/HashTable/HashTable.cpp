#include "HashTable.h"

HashTable::HashTable()
{
    this->M = 4;
    this->B = 2;

    int dESize = pow(2, this->B);

    for(int i = 0; i < dESize; i++)
    {
        Bucket b(this->M, convertDecToSTRBin(i));
        row newRow(convertDecToSTRBin(i), addressof(b)); 
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
        Bucket b(this->M, convertDecToSTRBin(i));
        row newRow(convertDecToSTRBin(i), addressof(b)); 
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

void HashTable::insert(CovidInfo _CI) //PARA MODIFICAR
{
    string hashedKey = convertDecToSTRBin(polynomialRollingHash(_CI));
    string firstB_Key = getFirstBDigits(hashedKey);

    for(row i:rows)
    {
        if(i.first == firstB_Key)
        {
            if(i.first != i.second->getBucketKey())
            {
                divideBucket(addressof(i));
                i.second->addValue(_CI);
            }
            else if(!i.second->addValue(_CI))
            {
                duplicateHashTable();
                for(row i:rows)
                {
                    if(i.first == firstB_Key)
                    {
                        if(i.first != i.second->getBucketKey())
                        {
                            divideBucket(addressof(i));
                            i.second->addValue(_CI);
                        }
                    }
                }
            }
        }
    }
}

CovidInfo HashTable::search(float _cityCode, string _date) 
{
    string hashedKey = convertDecToSTRBin(polynomialRollingHash(_cityCode, _date));
    string firstB_Key = getFirstBDigits(hashedKey);

    for(row i:rows)
    {
        if(i.first == firstB_Key)
        {
            for(CovidInfo j:i.second->getValues())
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

    for(row i:rows)
    {
        if(i.first == firstB_Key)
        {
            i.second->removeValue(hashedKey);
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
    Bucket b(this->M, r->first);

    for(CovidInfo j:r->second->getValues())
    {
        string h = convertDecToSTRBin(polynomialRollingHash(j));
        if(getFirstBDigits(h) != r->second->getBucketKey())
        {
            b.addValue(r->second->popValue(h));
        }
    }

    r->second = addressof(b);
}

void HashTable::duplicateHashTable()
{
    B*=2;
    rowArray newRows(B);

    for(int i = 0; i < B; i++)
    {
        if(i % 2 == 0)
        {
            row r(getFirstBDigits(convertDecToSTRBin(i)), rows[i].second);
            newRows.push_back(r);
        }
        else
        {
            row r(getFirstBDigits(convertDecToSTRBin(i)), rows[i-1].second);
            newRows.push_back(r);
        }
    }

    rows = newRows;
}