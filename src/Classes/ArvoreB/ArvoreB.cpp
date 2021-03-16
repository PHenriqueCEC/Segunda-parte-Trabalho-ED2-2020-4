#include "./ArvoreB.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <ctime>

using std::cin;
using std::cout;
using std::endl;

ArvoreB::ArvoreB(int _min)
{
    raiz = nullptr;
    numComparacoesInsercao = 0;
    numComparacoesBusca = 0;
    min = _min;
    max = min * 2;
}

ArvoreB::~ArvoreB()
{
    remover(raiz);
}

int ArvoreB::buscar(int info)
{

    NoB *p = raiz->buscarNo(info, raiz, &numComparacoesBusca);

    if (p == nullptr)
    {
        return NULL;
    }
    else
    {

        int i = 0;
        //procura a primeira chave maior ou igual a k
        while (i < p->getN() && info > p->getChave(i))
        {
            i++; 
        }

        if (i < p->getN() && p->getChave(i) == info)
        {
            return p->getChave(i);
        }
        return NULL;
    }
}

void ArvoreB::inserir(int info)
{
    if (raiz == nullptr) //Arvore vazia
    {
        NoB *p = new NoB(min); //Memoria alocada para a raiz
        raiz = p;
        raiz->setN(1);                 //Atualiza valor de n
        raiz->atualizarChave(0, info); //Atualiza chave
    }

    else
    {
        if (raiz->getN() == max - 1)
        {
            //NoB *aux = new NoB(max / 2); //Memoria alocada para o novo no

            cisao(info, raiz); //Faz a cisão
        }

        else
        {
            raiz->inserirNo(info, &numComparacoesInsercao); //Caso a raiz nao esteja cheia
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
        for (int i = 0; i <= p->getN(); i++)
        {
            remover(p->getFilho(i));
            p->setFilho(i, nullptr);
        }
        delete p;
    }
}

void ArvoreB::cisao(int info, NoB *p)
{
    
    NoB *aux = new NoB(min);

    aux->setFolha(false);
    aux->setFilho(0, p);

    aux->overflow(0, p);

    int i = 0;

    if (aux->getChave(0) < info) 
        i++;
    aux->getFilho(i)->inserirNo(info, &numComparacoesInsercao);
    raiz = aux;
}

void ArvoreB::escritaEmArquivo()
{
    ofstream arq("saidaTestes.txt");

    arq << "Num de comparacoes na inserção: " << numComparacoesInsercao << endl;
    arq << "Num de comparacoes na busca: " << numComparacoesBusca << endl;
    arq << "Num de chaves presente no no: " << raiz->getN() << endl;

    for (int i = 0; i < raiz->getN(); i++)
    {
        arq << " " << raiz->getChave(i); 
    }

    arq << endl;

    cout << "Arquivo de saída criado com sucesso! O nome do mesmo eh: saidaTestes.txt" << endl;
}

void ArvoreB::imprimir()
{
    cout << "Num de comparacoes na inserção: " << numComparacoesInsercao << endl;
    cout << "Num de comparacoes na busca: " << numComparacoesBusca << endl;
    cout << "Num de chaves presente no no: " << raiz->getN() << endl;
    cout << endl;
    cout << "Imprimindo Raiz:" << endl;
    
    for (int i = 0; i < raiz->getN(); i++)
    {
        cout << " " << raiz->getChave(i) << endl;
    }
    cout << endl;
         
}

void ArvoreB::selecionarSaida()
{
    int saida = -1;

    cout << "Digite um valor MENOR que [20] para saida em console;" << endl;
    cout << "Digite um valor MAIOR que [20] para saida em TXT;" << endl;

    cin >> saida;

    if (saida <= 20)
    {
        cout << "Saida em console selecionada!" << endl;
        imprimir();
    }
    else
    {
        cout << "Saida em arquivo TXT selecionada!" << endl;
        escritaEmArquivo();
    }
}

/*void ArvoreB::imprimir(bool isWriteInFile)
{
    ofstream arq("saidaTestes.txt");
    if(isWriteInFile){
        arq << "--------------------------------------------------------------------" << endl;
        arq << "Num de comparacoes na inserção : " << this->numComparacoes << endl;
        arq << "Num de comparacoes na busca : " << this->numComparacoes << endl;
        arq << "--------------------------------------------------------------------" << endl;
    }else{
        cout << "--------------------------------------------------------------------" << endl;
        cout << "Num de comparacoes na inserção : " << this->numComparacoes << endl;
        cout << "Num de comparacoes na busca : " << this->numComparacoes << endl;
        cout << "--------------------------------------------------------------------" << endl;
    }
    printTree(raiz, "", true ,isWriteInFile,arq);
    if(isWriteInFile){
        cout << "O arquivo de saida foi salvo no arquivo : saidaTestes.txt" << endl;
    }
}*/