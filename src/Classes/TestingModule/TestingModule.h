#ifndef TESTINGMODULE_H_INCLUDED
#define TESTINGMODULE_H_INCLUDED
#include"../FileHandler/FileHandler.h"
#include"../QuadTree/Quadtree.h"
#include"../CityInfo/CityInfo.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class TestingModule
{
private:
    

public:
    TestingModule();
    ~TestingModule();
    void menu();
    void insertInQuadTree(vector<CityInfo*> &data);
    void selectDataStructureToInsert(int choice);
  
};

#endif