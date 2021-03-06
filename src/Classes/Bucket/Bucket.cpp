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

    list <Value>::iterator itV;
    for(itV = values.begin(); itV != values.end(); itV++)
    {
        if(itV->getKey().size() != this->bucketKeyLength)
        {
            itV->setKeyLength(this->bucketKeyLength);
        }
    }
}

int Bucket::getBucketLength()
{
    return this->M;
}

string Bucket::getBucketKey()
{
    return this->bucketKey;
}

list <Value> Bucket::getValues()
{
    return this->values;
}

bool Bucket::addValue(Value _value)
{
    if(values.size() < M)
    {
        this->values.push_back(_value);
        return true;
    }

    return false;
}

void Bucket::removeValue(Value _value)
{
    values.remove(_value);
}

Value Bucket::popValue(Value _value)
{
    list <Value>::iterator it;
    Value value;

    for (it = values.begin(); it != values.end(); ++it)
    {
        if(it->getKey() == _value.getKey())
        {
            value.setInfo(it->getInfo());
            value.setKey(it->getKey());
            values.erase(it);
            break;
        }
    }
    return value;
}

Value Bucket::popValue(string _key)
{
    list <Value>::iterator it;
    Value value;

    for (it = values.begin(); it != values.end(); ++it)
    {
        if(it->getKey() == _key)
        {
            value.setInfo(it->getInfo());
            value.setKey(it->getKey());
            values.erase(it);
            break;
        }
    }
    return value;
}

void Bucket::print()
{
    cout << "Bucket: " << bucketKey << endl;
    for (auto i = values.begin(); i != values.end(); i++)
    {
        i->print();   
    }
    cout << ":::::::::::::::::::" << endl;
}