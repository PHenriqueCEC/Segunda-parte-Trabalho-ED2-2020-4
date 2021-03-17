#ifndef HASHTABLE_H_INCLUDED
#define HASHTABLE_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include<random>
#include<functional>
#include <algorithm>
#include <cmath>   

#include "../CovidInfo/CovidInfo.h"

using namespace std;

class HashTable
{
    private:
        unsigned long long size; //Tamanho da tabela hash
        unsigned long long collisions; //Número de colisões


       vector<long long int> generatedHashs; //Valores hash gerados
        unsigned long long polynomialRollingHash(CovidInfo CI, unsigned long long _a); //Função PRH de hash
        unsigned long long polynomialRollingHash(float _cityCode, string _date, unsigned long long _a); //Função PRH de hash

    public:

        HashTable(); //Construtor simples
        HashTable(unsigned long long _size); //Construtor alocando um tamanho dado

        vector<CovidInfo> table; //Tabela hash - vetor de instancias da classe CovidInfo
        void insert(CovidInfo* _CI); //Função de inserção na tabela

        CovidInfo* search(float _cityCode, string _date); //Função de procura, retorna o valor procurado através de um dado código e data
        vector<CovidInfo> getCityInfoByKey(unsigned long long key); //Retorna o todas um vetor com todas as informações de uma cidade dado uma chave hasheada

        void print(bool writeInFile); //Função de impressão no terminal ou gravação em um arquivo dado
        
        long int getAllCasesInCity(int cityCode , int &comparisions,float &elapsedTime); //Retorna a quantidade total de casos por cidade

        //Amostragem do valores inseridos; retorna vetor com a quantidade de entradas específicadas no parâmetro
        vector<long long int> getNHashedKeys(int numberOfKeys); 
        vector<long long int> getHashedKeys();
        vector<long long int> getNRandomElements(int numberOfElements);
        //:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

        vector<CovidInfo> getValues(); //Retorna o próprio vetor da tabela hash
        int getSize(); //Retorna o tamanho da tabela, sem cortar lacunas
};
#endif

