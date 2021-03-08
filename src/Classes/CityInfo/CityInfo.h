#ifndef CITYINFO_H_INCLUDED
#define CITYINFO_H_INCLUDED
#include <iostream>
#include <string>

using namespace std;

class CityInfo
{
private:
public:
  int state_code;
  string city_code;
  string city_name;
  //X = Latitude
  //Y = Longitude
  float latitude, longitude;
  bool isCapital;
  bool empty;
  CityInfo(int state_code,string city_code, string city_name, float latitude, float longitude, bool isCapital);
  CityInfo();
  ~CityInfo();
  void setIsEmpty(bool isEmpty);
  bool isEmpty();
  bool compareCoordinates(float latitude, float longitude);
};

#endif