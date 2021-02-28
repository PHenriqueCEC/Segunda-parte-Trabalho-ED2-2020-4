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

        NoB* Buscar(CityInfo* info, NoB *p);  
        void Inserir(CityInfo* p); 
        void Remover(NoB *p);
        void Cisao(CityInfo* info, NoB* c);
        NoB *Remocao(CityInfo* info);  
        NoB *Insercao(CityInfo* info); 
        NoB *GetRaiz();
        void SetRaiz(NoB *raiz);
        void imprimirRaiz();

        //int get_t();
        //void set_t(int T);
    private:
        int numTrocas;
        int numComparacoes;
        NoB *raiz;
        int max;
};

#endif