#ifndef TESTINGMODULE_H_INCLUDED
#define TESTINGMODULE_H_INCLUDED
#include"../FileHandler/FileHandler.h"
#include"../AvlTree/AvlTree.h"
#include"../QuadTree/Quadtree.h"
#include"../CityInfo/CityInfo.h"
#include"../ArvoreB/ArvoreB.h"
#include<ctime>
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class TestingModule
{
private:
    

public:
    TestingModule();
    ~TestingModule();
    //Funções da parte 4
    void testingModuleMenu();
    void insertInBTree(vector<long long int> values);
    void insertInQuadTree(int numberOfRegisters);
    void insertInAvlTree(vector<long long int> values);
    void insertInHashTable(int numberOfRegisters);
    void selectDataStructureToInsert(int choice);
    //Funções da parte 5
    void statisticModuleMenu();
    void generateStatistics(int M , int bTreeNodeSize);

};

#endif