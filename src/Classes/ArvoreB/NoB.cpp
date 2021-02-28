#include "./NoB.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

NoB::NoB(int _max)
{
    max = _max; 
    min = max / 2;
    n = 0;
    folha = true;
    pai = nullptr;

    filhos = new NoB*[max]; //cria filhos com o numero maximo m
    chave = new CityInfo*[max]; //Cria chave de ordem m - 1

    for(int i = 0; i < max; i++) //inicializa os filhos com nullptr
        filhos[i] = nullptr; //Pq nullptr NAO funciona?
    
    for(int i = 0; i < max - 1; i++) //cria chaves com o numero maximo m - 1
        chave[i] = nullptr;

}

NoB::~NoB()
{
    delete [] chave;
    delete [] filhos;
}

bool NoB::GetFolha()
{
    return folha;
}

void NoB::SetFolha(bool _folha)
{
    folha = _folha;
}

CityInfo* NoB::GetChave(int i)
{
    return chave[i];
}

void NoB::AtualizarChave(int i, CityInfo* info)
{
    chave[i] = info;
}

int NoB::GetN()
{
    return n;
}

void NoB:: SetN(int _n)
{
    n = _n;
}

NoB* NoB::GetPai()
{
    return pai;
}

void NoB::SetPai(NoB *p)
{
    pai = p;
}

 /*NoB* NoB::GetFilhos(int i)
 {
     return filhos[i];
 }

void NoB:: SetFilhos(int i, NoB* val)
{
    filhos[i] = val; 
}

CityInfo* NoB::GetAnt(int i)
{

}

CityInfo* NoB::SetProx(int i)
{

}*/


