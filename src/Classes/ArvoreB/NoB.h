#ifndef NOB_H_INCLUDED
#define NOB_H_INCLUDED
#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

class NoB
{
    private:
        int m; //tamanho
        //T chave[m - 1]; //vetor de chaves de um tipo qualquer(informações contida no nó) //CovidInfo*
        NoB *filhos; //vetor de ponteiros para os m filhos
        int n;       //numero de chaves presente no no
        bool folha;  //indica se o filho eh folha ou nao
        NoB *pai;

    public:
        NoB(int _m);
        ~NoB();
        bool GetFolha();
        void SetFolha(bool _folha);
        NoB* GetFilhos(int i);
        void SetFilhos(int i, NoB* val);
        int GetChaves(int i);
        //void SetChaves(int i, CovidInfo* val);
        NoB* GetPai();
        void SetPai(NoB *p);
        //CovidInfo* GetChave(int i);
        //void SetChave(int i, CovidInfo* val);
        int GetN();
        void SetN(int _n);

        //CovidInfo* GetAnt(int i);
        //CovidInfo* SetProx(int i);
};

#endif