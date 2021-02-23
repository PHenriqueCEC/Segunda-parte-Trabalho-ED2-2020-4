#include"./CityInfo.h"

CityInfo::CityInfo(int state_code,string city_code,string city_name,float latitude,float longitude,bool isCapital){
    this->state_code = state_code;
    this->city_name  = city_name;
    this->city_code = city_code;
    this->latitude = latitude;
    this->longitude = longitude;
    this->isCapital = isCapital;
}

bool CityInfo::CompareCoordinates(float latitude,float longitude){
    return (this->latitude == latitude && this->longitude == longitude);
}