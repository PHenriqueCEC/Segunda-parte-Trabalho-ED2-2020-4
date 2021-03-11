#ifndef ARVOREB_H_INCLUDED
#define ARVOREB_H_INCLUDED
#include "./NoB.h"
#include "./Classes/CityInfo/CityInfo.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

class ArvoreB
{
    public:
        ArvoreB();
        ~ArvoreB();

        CityInfo* buscar(CityInfo* info);  
        void inserir(CityInfo* p); 
        void remover(NoB *p);
        void cisao(CityInfo* info, NoB* p);
        NoB* remocao(CityInfo* info);  
        NoB* insercao(CityInfo* info); 
        NoB* getRaiz();
        void setRaiz(NoB *raiz);
        int getMin();
        int getMax();
        void imprimir();
        void escritaEmArquivo();

        //int get_t();
        //void set_t(int T);
    private:
        int numTrocas;
        int numComparacoes;
        NoB *raiz;
        int max;
};

#endif