#ifndef TESTINGMODULE_H_INCLUDED
#define TESTINGMODULE_H_INCLUDED
#include"../FileHandler/FileHandler.h"
#include"../AvlTree/AvlTree.h"
#include"../QuadTree/Quadtree.h"
#include"../CityInfo/CityInfo.h"
#include"../ArvoreB/ArvoreB.h"
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
    void insertInBTree(vector<int> values);
    void insertInQuadTree(vector<CityInfo*> &data);
    void insertInAvlTree(vector<int> values);
    void selectDataStructureToInsert(int choice);
  
};

#endif