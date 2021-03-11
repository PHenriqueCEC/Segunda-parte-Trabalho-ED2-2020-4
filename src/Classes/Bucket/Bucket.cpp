#include "Bucket.h"

Bucket::Bucket()
{

}

Bucket::Bucket(int _M)
{
    this->M = _M;
}

Bucket::Bucket(int _M, string _bucketKey)
{
    this->M = _M;
    this->bucketKey = _bucketKey;
}

void Bucket::setBucketLength(int _M)
{
    this->M = _M;
}

void Bucket::setBucketKey(string _bucketKey)
{
    this->bucketKey = _bucketKey;
    this->bucketKeyLength = this->bucketKey.size();
}

int Bucket::getBucketLength()
{
    return this->M;
}

string Bucket::getBucketKey()
{
    return this->bucketKey;
}

vector <CovidInfo> Bucket::getValues()
{
    return this->values;
}

bool Bucket::addValue(CovidInfo _CI)
{
    if(values.size() < M)
    {
        this->values.push_back(_CI);
        return true;
    }

    return false;
}

void Bucket::removeValue(string _hashedValue)
{
    for(auto i = values.begin(); i != values.end(); i++)
    {
        if(convertDecToSTRBin(polynomialRollingHash(*i)) == _hashedValue)
        {
            values.erase(i);
            break;
        }
    }
    values.shrink_to_fit();
}

CovidInfo Bucket::popValue(string _hashedValue)
{
    for(auto i = values.begin(); i != values.end(); i++)
    {
        if(convertDecToSTRBin(polynomialRollingHash(*i)) == _hashedValue)
        {
            CovidInfo *ci = addressof(*i);
            values.erase(i);
            return *ci;
        }
    }
    values.shrink_to_fit();
}

void Bucket::print()
{
    for(CovidInfo i:values)
    {
        i.print();
        cout << "-----------------------------------" << endl;
    }
    cout << endl << ":::::::::::::::::::::::::::::::::::::::::::" << endl << endl << endl;
}

long long Bucket::polynomialRollingHash(CovidInfo &_CI)
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

string Bucket::convertDecToSTRBin(long long _dec)
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

    while(i < bucketKeyLength)
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
