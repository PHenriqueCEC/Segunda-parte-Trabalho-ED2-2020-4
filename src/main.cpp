#include<iostream>
#include "./Classes/FileHandler/FileHandler.h"
#include "./Classes/TestingModule/TestingModule.h"

using std::cout;
using std::endl;

int main(int argc, char **argv){
    //string diretorio = argv[1];
    FileHandler fileHandler;
    //fileHandler.processCityInfo("teste.csv");
    //fileHandler.processCovidInfo("teste");
    TestingModule testing;
    testing.menu();

   
}