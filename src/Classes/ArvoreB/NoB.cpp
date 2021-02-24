#include "./NoB.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

NoB::NoB(int _m)
{
    m = _m; //tamanho
    n = 0;
    folha = true;
    pai = nullptr;

    filhos = new NoB(m); //cria filhos com o numero maximo m
    //chaves = new NoB(m - 1); Cria chave de ordem m - 1

    for(int i = 0; i < m; i++) //inicializa os filhos com nullptr
        filhos[i] = NULL; //Pq nullptr NAO funciona?
    
    //for(int i = 0; i < m - 1; i++) //cria chaves com o numero maximo m - 1
        //chaves[i] = nullptr;

}

NoB::~NoB()
{
    //delete [] chaves;
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

/*CovidInfo* NoB::GetChave(int i)
{
    return chave[i];
}*/

/*void NoB::SetChave(int i, CovidInfo* val)
{
    chave[i] = val
}*/

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
}*/

/*CovidInfo* NoB::GetAnt(int i)
{

}

CovidInfo* NoB::SetProx(int i)
{

}*/

