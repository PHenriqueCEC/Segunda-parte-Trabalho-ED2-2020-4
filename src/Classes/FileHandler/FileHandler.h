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
  //Função de processamento do csv
  FileHandler();
  ~FileHandler();
  void processCityInfo(string filename);
  //Função para obter n registros aleatórios do arquivo processado
};

#endif