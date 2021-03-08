#include"./CityInfo.h"

CityInfo::CityInfo(int state_code,string city_code,string city_name,float latitude,float longitude,bool isCapital){
    this->state_code = state_code;
    this->city_name  = city_name;
    this->city_code = city_code;
    this->latitude = latitude;
    this->longitude = longitude;
    this->isCapital = isCapital;
    this->empty = false;
}

CityInfo::CityInfo(){
    this->empty = true;
}

bool CityInfo::compareCoordinates(float latitude,float longitude){
    return (this->latitude == latitude && this->longitude == longitude);
}

void CityInfo::setIsEmpty(bool isEmpty){
    this->empty = isEmpty;
}

bool CityInfo::isEmpty(){
    return this->empty;
}