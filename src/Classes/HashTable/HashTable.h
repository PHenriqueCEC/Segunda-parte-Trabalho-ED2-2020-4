#ifndef HASHTABLE_H_INCLUDED
#define HASHTABLE_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "../CovidInfo/CovidInfo.h"

using namespace std;

class HashTable
{
    private:
        unsigned long long size;
        unsigned long long collisions;

       vector<CovidInfo> table;
       vector<long long int> generatedHashs;
        unsigned long long polynomialRollingHash(CovidInfo CI, unsigned long long _a);
        unsigned long long polynomialRollingHash(float _cityCode, string _date, unsigned long long _a);

    public:
        HashTable();
        HashTable(unsigned long long _size);

        void insert(CovidInfo* _CI);

        CovidInfo* search(float _cityCode, string _date);
        vector<CovidInfo> getCityInfoByKey(unsigned long long key);

        void print(bool writeInFile);

        vector<long long int> getNHashedKeys(int numberOfKeys);    
        vector<long long int> getHashedKeys();
        int getSize();
};
#endif

