#include<iostream>
#include "./Classes/FileHandler/FileHandler.h"
#include "./Classes/TestingModule/TestingModule.h"
#include "./Classes/HashTable/HashTable.h"
#include<string>
#include<vector>

using namespace std;

int main(int argc, char **argv){
    string diretorio;
    if(argv[1])
     diretorio = argv[1];   
    else 
     diretorio = "./";
    
    TestingModule testing(diretorio);
    testing.testingModuleMenu();

   
   cout << endl;
}