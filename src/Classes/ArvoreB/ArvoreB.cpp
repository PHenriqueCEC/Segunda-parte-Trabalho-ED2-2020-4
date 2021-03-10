#include "./ArvoreB.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

ArvoreB::ArvoreB()
{
    raiz = nullptr;
    numComparacoes = 0;
}

ArvoreB::~ArvoreB()
{
    remover(raiz);
}

CityInfo *ArvoreB::buscar(CityInfo *info)
{
    if (raiz == nullptr)
    {
        return false;
    }

    NoB *p = raiz->buscarNo(info, raiz, &numComparacoes);

    int i = 0;
    //procura a primeira chave maior ou igual a k
    while (i < p->getN() && info > p->getChave(i))
    {
        i++; //Precisa de id
    }

    if(i < p->getN() && p->getChave(i) == info)
    {
        return p->getChave(i);
    }
    return nullptr;

}

void ArvoreB::inserir(CityInfo *info)
{
    if (raiz == nullptr) //Arvore vazia
    {
        NoB *p = new NoB(max / 2); //Memoria alocada para a raiz
        raiz = p;
        raiz->setN(1);                 //Atualiza valor de n
        raiz->atualizarChave(0, info); //Atualiza chave
    }

    else
    {
        if (raiz->getN() == max - 1)
        {
            NoB *aux = new NoB(max / 2); //Memoria alocada para o novo no

            cisao(info, raiz); //Faz a cisão
        }

        else
        {
            raiz->inserirNo(info, &numComparacoes); //Caso a raiz nao esteja cheia
        }
    }
}

void ArvoreB::remover(NoB *p)
{

    if (p == nullptr)
    {
        return;
    }

    if (p->getFolha() == true)
    {
        delete p;
    }

    else
    {
        for (int i = 0; i < p->getN(); i++)
        {
            remover(p->getFilho(i));
            p->setFilho(i, nullptr);
        }
        delete p;
    }
}

void ArvoreB::cisao(CityInfo *info, NoB *p)
{
    int min = max / 2;
    NoB* aux = new NoB(min);

  aux->setFolha(false);
  aux->setFilho(0, p);

  aux->overflow(0, p);
  
  int i = 0;

  if(aux->getChave(0) < info) ///Falta o id
    i++; 
  aux->getFilho(i)->inserirNo(info, &numComparacoes);
  raiz = aux;
}
