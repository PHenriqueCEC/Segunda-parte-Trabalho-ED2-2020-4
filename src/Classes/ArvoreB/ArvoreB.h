#ifndef ARVOREB_H_INCLUDED
#define ARVOREB_H_INCLUDED
#include "./NoB.h"
#include "../CityInfo/CityInfo.h"
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
        ArvoreB(int _min);
        ~ArvoreB();

        int buscar(int info);  
        void inserir(int p); 
        void remover(NoB *p);
        void cisao(int info, NoB* p);
        NoB* remocao(int info);  
        NoB* insercao(int info); 
        NoB* getRaiz();
        void setRaiz(NoB *raiz);
        int getMin();
        int getMax();
        void imprimir(bool isWriteInFile);
        void escritaEmArquivo();

        //int get_t();
        //void set_t(int T);
    private:
        int numTrocas;
        int numComparacoes;
        NoB *raiz;
        int max;
        int min;
};

#endif