#ifndef CITYINFO_H_INCLUDED
#define CITYINFO_H_INCLUDED
#include<iostream>
#include<string>

using namespace std;

class CityInfo
{
  private:
    int state_code;
    string city_code;
    float latitude,longitude;
    bool isCapital;

  public:
    CityInfo(int state_code,string city_code,float latitude,float longitude,bool isCapital);
    CityInfo();
    ~CityInfo();

};

#endif