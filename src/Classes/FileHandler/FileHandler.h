#ifndef FILEHANDLER_H_INCLUDED
#define FILEHANDLER_H_INCLUDED
#include"../CityInfo/CityInfo.h"
#include"../QuadTree/Quadtree.h"
#include<iostream>
#include <fstream>

using namespace std;

class FileHandler
{
private:

public:

  FileHandler();
  ~FileHandler();
  //Função de processamento do csv
  void processCityInfo(string filename);
  
};

#endif