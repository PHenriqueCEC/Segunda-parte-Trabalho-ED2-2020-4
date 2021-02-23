#include<iostream>
#include "./Classes/FileHandler/FileHandler.h"
using namespace std;

int main(int argc, char **argv){
    //string diretorio = argv[1];
    FileHandler fileHandler;
    fileHandler.processCityInfo("teste.csv");
   
}