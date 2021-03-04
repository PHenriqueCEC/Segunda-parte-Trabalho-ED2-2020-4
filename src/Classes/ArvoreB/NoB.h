#ifndef NOB_H_INCLUDED
#define NOB_H_INCLUDED
#include "./Classes/CityInfo/CityInfo.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

class NoB
{

    public:
        NoB(int _max);
        ~NoB();
        bool getFolha();
        void setFolha(bool _folha);
        NoB* getFilhos(int i);
        void setFilhos(int i, NoB* val);
        int getChaves(int i);
        void atualizarChave(int i, CityInfo* info);
        NoB* getPai();
        void setPai(NoB *p);
        CityInfo* getChave(int i);
        void setChave(int i, CityInfo* val);
        int getN();
        void setN(int _n);
        void inserirNo(CityInfo* info);
        void overflow(int i, NoB *p);


        //CityInfo* GetAnt(int i);
        //CityInfo* SetProx(int i);

    private:
        int max; //tamanho maximo
        int min; //tamanho minimo
        CityInfo **chave; //vetor de chaves de um tipo qualquer(informações contida no nó)
        NoB **filhos; //vetor de ponteiros para os m filhos
        int n;       //numero de chaves presente no no
        bool folha;  //indica se o filho eh folha ou nao
        NoB *pai;
};

#endif