#ifndef FILEHANDLER_H_INCLUDED
#define FILEHANDLER_H_INCLUDED
#include"../CityInfo/CityInfo.h"
#include"../QuadTree/Quadtree.h"
#include<iostream>
#include<fstream>
#include<vector>
#include <random>
#include <functional>


using namespace std;

class FileHandler
{
private:
  vector<CityInfo*> citysList;
public:

  FileHandler();
  ~FileHandler();
  //Função de processamento do csv
  void processCityInfo(string filename);
  void processCityInfoList(string filename);
  vector<CityInfo*> getNRandomCityInfo(int n);
  
};

#endif