
#ifndef COVIDINFO_H_INCLUDED
#define COVIDINFO_H_INCLUDED
#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>

using namespace std;

/*Classe para armazenar cada registro(linha) do CSV*/
class CovidInfo
{
private:
public:
  string date;
  string state;
  string city;
  float code;
  int cases;
  int deaths;
  int totalCases;
  //Função de processamento do csv
  CovidInfo();
  CovidInfo(string date, string state, string city, int code, int cases, int deaths);
  CovidInfo(string date, string state, string city, int code, int cases, int totalCases, int deaths);
  ~CovidInfo();

  void print();
  void printInFile(ofstream &file);

  bool operator < (const CovidInfo& c) const //Overload do operador < para servir a propositos de ordenação de vetores de objetos desta classe
  {
      return (city < c.city);
  }
};

#endif