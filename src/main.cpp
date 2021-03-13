#include<iostream>
#include "./Classes/FileHandler/FileHandler.h"
#include "./Classes/TestingModule/TestingModule.h"
#include<string>

using namespace std;

int main(int argc, char **argv){
    string diretorio;
    if(argv[1])
     diretorio = argv[1];

    TestingModule testing;
    testing.menu();
}