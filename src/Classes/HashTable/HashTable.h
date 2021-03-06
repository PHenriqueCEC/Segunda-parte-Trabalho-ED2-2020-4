#ifndef HASHTABLE_H_INCLUDED
#define HASHTABLE_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <utility> 
#include <algorithm>
#include <cmath>

#include "../Bucket/Bucket.h"
#include "../CovidInfo/CovidInfo.h"

using namespace std;

class HashTable
{
    private:
        int M; 
        int B;
        typedef pair<string, Bucket*> row;
        typedef vector<row> rowArray;
        rowArray rows;

        long long polynomialRollingHash(CovidInfo CI);
        long long polynomialRollingHash(float _cityCode, string _date);

        string getFirstBDigits(string _info);
        string convertDecToSTRBin(long long _dec);

        void divideBucket(row *r);
        void duplicateHashTable();

    public:
        HashTable();
        HashTable(int _M, int _B);

        void setM(int _M);
        void setB(int _B);

        int getM();
        int getB();

        void insert(CovidInfo _CI);

        CovidInfo search(float _cityCode, string _date);
        
        void remove(float _cityCode, string _date);

        void print();
};
#endif