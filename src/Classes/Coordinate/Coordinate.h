#ifndef COORDINATE_H_INCLUDED
#define COORDINATE_H_INCLUDED
#include <iostream>

using namespace std;

//Struct para armazenar os pontos para
//armazenar os pontos x1,x2,y1,y1 para
//obter cidades nesse range
class Coordinate
{
private:
    int size;

public:
    Coordinate(float x1,float y1,float x2,float y2);
    ~Coordinate();
    float x1,x2;
    float y1,y2;
};

#endif