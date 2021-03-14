#include<iostream>
#include "./Classes/FileHandler/FileHandler.h"
#include "./Classes/TestingModule/TestingModule.h"
#include "./Classes/HashTable/HashTable.h"
#include<string>

using namespace std;

int main(int argc, char **argv){
    string diretorio;
    if(argv[1])
     diretorio = argv[1];
    /*
    TestingModule testing;
    testing.menu();
    */
   FileHandler fileHandler;
   HashTable *table = new HashTable(14000000);
   table = fileHandler.insertCovidInfoInHashTable("",1000000);
   table->getNRandomElements(100000);
}