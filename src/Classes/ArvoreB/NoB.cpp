#include "./NoB.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <ctime>


NoB::NoB(int _max)
{
    max = _max;
    min = max / 2;
    n = 0;
    folha = true;
    pai = nullptr;

    filhos = new NoB *[max];     //cria filhos com o numero maximo m
    chave = new CityInfo *[max]; //Cria chave de ordem m - 1

    for (int i = 0; i < max; i++) //inicializa os filhos com nullptr
        filhos[i] = nullptr;      //Pq nullptr NAO funciona?

    for (int i = 0; i < max - 1; i++) //cria chaves com o numero maximo m - 1
        chave[i] = nullptr;
}

NoB::~NoB()
{
    delete[] chave;
    delete[] filhos;
}

bool NoB::getFolha()
{
    return folha;
}

void NoB::setFolha(bool _folha)
{
    folha = _folha;
}

CityInfo *NoB::getChave(int i)
{
    return chave[i];
}

void NoB::atualizarChave(int i, CityInfo *info)
{
    chave[i] = info;
}

int NoB::getN()
{
    return n;
}

void NoB::setN(int _n)
{
    n = _n;
}

NoB *NoB::getPai()
{
    return pai;
}

void NoB::setPai(NoB *p)
{
    pai = p;
}

NoB* NoB::getFilho(int i)
 {
     return filhos[i];
 }

void NoB:: setFilho(int i, NoB* val)
{
    filhos[i] = val; 
}

/*CityInfo* NoB::GetAnt(int i)
{

}

CityInfo* NoB::SetProx(int i)
{

}*/

void NoB::inserirNo(CityInfo *info, int *numComparacoes)
{
    int i = n - 1; //Indice com o elemento mais a direita

    if (folha == true)
    {
        while (i >= 0 && chave[i] > info) //Encontra a posicao da nova chave a ser inserida
        {
            chave[i + 1] = chave[i];
            i--;
            *numComparacoes += 1;
        }

        chave[i + 1] = chave[i];
        n += 1;
    }

    else
    {
        while (i >= 0 && chave[i] > info) //Procura o filho que terá a nova chave
        {
            i--;
            *numComparacoes += 1;
        }

        if (filhos[i + 1]->getN() == max - 1)
        {
            overflow(i + 1, filhos[i + 1]); //Se o filho está cheio

            if (chave[i + 1] < info)
                i++;
        }

        filhos[i + 1]->inserirNo(info, numComparacoes);
    }
}

void NoB::overflow(int i, NoB *p) //Executa a cisao do no
{
    //Cria um novo no que armazena min - 1 chaves de p
    int min = max / 2;
    NoB *aux = new NoB(min);
    aux->setN(min - 1);

    for (int j = 0; j < min - 1; i++) //Copia as chaves
    {
        aux->chave[j] = p->chave[j + min];
    }

    if (p->getFolha() == false)
    {
        for (int j = 0; j < min; j++) //Copia os filhos
        {
            aux->filhos[j] = p->filhos[j + min];
        }
    }

    p->setN(min - 1); //Reduz o numero de chaves

    for (int j = n; j >= i + 1; j--) //Cria espaço para o novo filho
    {
        filhos[j + 1] = filhos[j];
    }

    filhos[i + 1] = aux; //Junta o novo filho com o nó

    for (int j = n - 1; j >= i; j--) //Encontra a posição da nova chave e move as chaves maiores para a direita
    {
        chave[j + 1] = chave[j];
    }

    chave[i] = p->chave[min - 1];

    n += 1; //Incrementa contador de chaves para esse nó

}

NoB* NoB::buscarNo(CityInfo* info, NoB* p, int* numComparacoes)
{
    *numComparacoes += 1;

    int i = 0;
    while (i < n && info > chave[i])
    {
        i++;
    }
    
    if ( i < n && chave[i] == info )
    {
        return p;
    }
    
    if (folha == true)
    {
        return nullptr;
    }
      
    return filhos[i]->buscarNo(info, filhos[i], numComparacoes);

}