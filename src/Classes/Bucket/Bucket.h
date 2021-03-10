#ifndef BUCKET_H_INCLUDED
#define BUCKET_H_INCLUDED
#include <iostream>
#include <list>
#include <string>
#include <algorithm>

#include "../CovidInfo/CovidInfo.h"

using namespace std;

class Bucket
{
    private:
        int M;
        string bucketKey;
        int bucketKeyLength;
        vector <CovidInfo> values;

        long long polynomialRollingHash(CovidInfo &_CI);
        string convertDecToSTRBin(long long _dec);

    public:
        Bucket();
        Bucket(int _M);
        Bucket(int _M, string _bucketKey);

        void setBucketLength(int _M);
        void setBucketKey(string _bucketKey);

        int getBucketLength();
        string getBucketKey();
        vector <CovidInfo> getValues();

        bool addValue(CovidInfo _CV);
        
        void removeValue(string _hashedValue);

        CovidInfo popValue(string _hashedValue);

        void print();
};
#endif

