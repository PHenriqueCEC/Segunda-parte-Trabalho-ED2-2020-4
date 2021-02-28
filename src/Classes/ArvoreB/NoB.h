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
        bool GetFolha();
        void SetFolha(bool _folha);
        NoB* GetFilhos(int i);
        void SetFilhos(int i, NoB* val);
        int GetChaves(int i);
        void AtualizarChave(int i, CityInfo* info);
        NoB* GetPai();
        void SetPai(NoB *p);
        CityInfo* GetChave(int i);
        void SetChave(int i, CityInfo* val);
        int GetN();
        void SetN(int _n);


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