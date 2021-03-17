#ifndef NOB_H_INCLUDED
#define NOB_H_INCLUDED
#include"../CityInfo/CityInfo.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>



class NoB
{

    public:
        NoB(int _min);
        ~NoB();
        bool getFolha();
        void setFolha(bool _folha);
        NoB* getFilho(int i);
        void setFilho(int i, NoB* val);
        void atualizarChave(int i, int info);
        int getChave(int i);
        void setChave(int i, int val);
        int getN();
        void setN(int _n);
        void inserirNo(int info, int *numComparacoesInsercao);
        void overflow(int i, NoB *p);
        NoB* buscarNo(int info, NoB* p, int* numComparacoesBusca);
        void imprimir();

    private:
        int max; //tamanho maximo
        int min; //tamanho minimo
        vector<int> chave; //vetor de chaves de um tipo qualquer(informações contida no nó)
        NoB **filhos; //vetor de ponteiros para os m filhos
        int n;       //numero de chaves presente no no
        bool folha;  //indica se o filho eh folha ou nao
        NoB *pai;
};

#endif