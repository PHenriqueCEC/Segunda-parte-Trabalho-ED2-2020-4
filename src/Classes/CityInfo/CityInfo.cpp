#include"./CityInfo.h"

CityInfo::CityInfo(int state_code,string city_code,float latitude,float longitude,bool isCapital){
    this->state_code = state_code;
    this->city_code = city_code;
    this->latitude = latitude;
    this->longitude = longitude;
    this->isCapital = isCapital;
}