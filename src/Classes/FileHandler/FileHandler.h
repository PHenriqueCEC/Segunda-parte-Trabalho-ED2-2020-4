#ifndef FILEHANDLER_H_INCLUDED
#define FILEHANDLER_H_INCLUDED
#include"../CityInfo/CityInfo.h"
#include"../QuadTree/Quadtree.h"
#include"../CovidInfo/CovidInfo.h"
#include"../HashTable/HashTable.h"
#include<iostream>
#include<fstream>
#include<vector>
#include<random>
#include<functional>
#include<ctime>



using namespace std;
using std::cout;

class FileHandler
{
private:
  string directory;
  vector<CityInfo*> citysList;
public:

  FileHandler();
  FileHandler(string directory);
  ~FileHandler();
  //Função de processamento do csv
  QuadTree* insertCityListInQuadTree(string filename , int n);
  void processCityInfoList(string filename);
  HashTable* insertCovidInfoInHashTable(string filename,int numberOfRegisters,float &time);
  vector<CityInfo*> getNRandomCityInfo(int n);
  
};

#endif