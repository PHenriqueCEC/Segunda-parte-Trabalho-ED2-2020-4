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
    numTrocas = 0;
    numComparacoes = 0;
}

ArvoreB::~ArvoreB()
{
    //remover(raiz);
}

NoB* ArvoreB::Buscar(CityInfo* info, NoB *p)
{
    if(raiz == nullptr)
    {
        return false;
    }

    else
    {
        int i = 0;
        //procura a primeira chave maior ou igual a k
        while (i < p->GetN() && info > chave[i])
        {
            i++; //Precisa de id
        }
        
        //retorna esse no caso a chave foi encontrada
        if(chave[i] == info)
        {
            return chave[i];
        }

        //Se a chave nao foi encontrada e este eh um no folha
        if(folha)
        {
            return nullptr;
        }

        return Buscar(info, p);
    }


}

void ArvoreB::Inserir(CityInfo* info)
{
    if(raiz == nullptr) //Arvore vazia
    {
        NoB* p = new NoB(max / 2); //Memoria alocada para a raiz
        raiz = p;
        raiz->SetN(1); //Atualiza valor de n
        raiz->AtualizarChave(0, info); //Atualiza chave
    }

    else
    {
        if(raiz->GetN() == max - 1)
        {
            NoB* aux = new NoB(max / 2); //Memoria alocada para o novo no

            cisao(info, raiz); //Faz a cisão 
        }

        else
        {
            raiz->inserirNo(info); //Caso a raiz nao esteja cheia
        }
        
    }
}

void ArvoreB::Remover(NoB *p)
{

}

void ArvoreB::cisao(CityInfo* info, NoB* c)
{

}