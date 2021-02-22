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
       void Buscar();
       void Inserir();
       void Remover();
  
};

#endif