#ifndef ARVOREB_H_INCLUDED
#define ARVOREB_H_INCLUDED
#include "./NoB.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

class ArvoreB
{
    private:
        int numTrocas;
        int numComparacoes;
        NoB *raiz;

    public:
       ArvoreB();
       void Buscar(); // CovidInfo* Buscar(CoviInfo* info, NoB *p);
       void Inserir(); //colocar como parametro o "tipo" covid *CovidInfo p
       void Remover(NoB* p);
       void Cisao(); //*CovidInfo info, NoB* (algum ponteiro)
       NoB* Remocao(); //CovidInfo* info
       NoB* Insercao(); //CovidInfo* info 
       NoB* GetRaiz(); 
       void SetRaiz(NoB* raiz);
       void imprimirRaiz();

        //int get_t();
        //void set_t(int T);
  
};

#endif