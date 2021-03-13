#include "./FileHandler.h"
#include "../Coordinate/Coordinate.h"


FileHandler::FileHandler()
{
}

FileHandler::~FileHandler()
{
}

//Pega todos os registros do csv de coordenadas da cidade
//e salva em um vetor local da classe
void FileHandler::processCityInfoList(string filename){
  int line = 0;
  ifstream arq("brazil_cities_coordinates.csv");
  string state_code, city_code, city_name, latitutde, longitude, isCapital;
  if (arq.is_open())
  {
    //Vai ate o final do arquivo separando cada elemento do csv por ,
    while (!arq.eof()) 
    {

      getline(arq, state_code, ',');
      getline(arq, city_code, ',');
      getline(arq, city_name, ',');
      getline(arq, latitutde, ',');
      getline(arq, longitude, ',');
      getline(arq, isCapital);

      //Pula a primeira linha do arquivo , pois é o header informativo o que cada coluna significa
      if (line >= 1)
      {
        //@Todo inserção dos dados obtidos na quadtree;
        CityInfo *info = new CityInfo(stoi(state_code), city_code, city_name, stof(latitutde), stof(longitude), isCapital == "TRUE");
        this->citysList.push_back(info);
      }
      line++;
    }
    arq.close();
  }
  else
  {

    cout << "Nao foi possivel abrir o arquivo" << endl;
  }
}

HashTable* FileHandler::insertCovidInfoInHashTable(string filename,int numberOfRegisters)
{
  int i = 0;
  //Pré aloco o n de registros
  HashTable *hashTable = new HashTable(numberOfRegisters +  (numberOfRegisters * 0.5));
  string date, state, city, code, dailyCases, totalCases, deaths, line;
  //Abre o csv pré-processado
  ifstream arq("brazil_covid19_cities_processado.csv");
  int linesProcessed = 0;
  vector<CovidInfo> file;
  clock_t startTime = 0, finalTime;
  if (arq.is_open())
  {
    startTime = clock();
    //Vai ate o final do arquivo separando cada elemento do csv por ,
    while (!arq.eof())
    {
      getline(arq, date, ',');
      getline(arq, state, ',');
      getline(arq, city, ',');
      getline(arq, code, ',');
      getline(arq, dailyCases, ',');
      getline(arq, totalCases, ',');
      getline(arq, deaths, ',');
      if(linesProcessed % 10000 == 0){
        cout << "Na iteração " << linesProcessed << "....." << endl;
      }
      //Pula a primeira linha do arquivo , pois é o header informativo o que cada coluna significa
      if (linesProcessed >= 1)
      {
        //Criado objeto covid info e feito as transformações para int necessarias
        CovidInfo line;
        line.date = date;
        line.state = state;
        line.city = city;
        line.code = stoi(code);
        line.totalCases = stoi(totalCases);
        hashTable->insert(addressof(line));
      }
      linesProcessed++;
      if(linesProcessed == numberOfRegisters){ 
        break;
      }
    }
    finalTime = clock();
    cout << "Tempo de Processamento : " << (finalTime - startTime) / ((float)CLOCKS_PER_SEC) << " segundos" << endl;
    return hashTable;
    //hashTable->print();
  }else{
    cout << "Não foi possível abrir o arquivo!" << endl;
    exit(1);
  }
  return new HashTable();  
}


vector<CityInfo*> FileHandler::getNRandomCityInfo(int n ){
  cout << "Pegando registros aleatórios  " << endl;
  std::random_device device;
  std::mt19937 generator(device());
  std::uniform_int_distribution<int> distribution(0,this->citysList.size() - 1);
  vector<CityInfo*> sortedInfos;
  int drawn = 0;

  //Vetor auxiliar para eu controlar quais indices ja foram gerados
  vector<bool> usedIndexs;
  for(int i = 0 ; i < this->citysList.size() ; i++)
  usedIndexs.push_back(false);

  for(int i = 0 ; i < n ; i++){
      //Garanto que o indice que gerei ainda não foi utilizado , para não ocorrerem duplicatas.
      while(usedIndexs[drawn])
         drawn = distribution(generator);
      
      sortedInfos.push_back(this->citysList.at(i));
      //Adiciono o número sorteado no meu vetor de indices já sorteados
      usedIndexs[drawn] = true;

  } 


 //Desalocando vetor de bools auxiliar da memória
  usedIndexs.~vector();
  return sortedInfos;
}

QuadTree*  FileHandler::insertCityListInQuadTree(string filename,int n)
{
  int line = 0;
  ifstream arq("brazil_cities_coordinates.csv");
  string state_code, city_code, city_name, latitutde, longitude, isCapital;
  if (arq.is_open())
  {
    cout << "Arq opened" << endl;
    QuadTree *tree = new QuadTree();
    //Vai ate o final do arquivo separando cada elemento do csv por ,
    while (!arq.eof())
    {

      getline(arq, state_code, ',');
      getline(arq, city_code, ',');
      getline(arq, city_name, ',');
      getline(arq, latitutde, ',');
      getline(arq, longitude, ',');
      getline(arq, isCapital);

      //Pula a primeira linha do arquivo , pois é o header informativo o que cada coluna significa
      if (line >= 1 && line < n)
      {
        //@Todo inserção dos dados obtidos na quadtree;
        CityInfo *info = new CityInfo(stoi(state_code), city_code, city_name, stof(latitutde), stof(longitude), isCapital == "TRUE");
        tree->insert(tree->root, info);
      }
      line++;
    }
    return tree;
    cout << "Inserção na quadTree ocorrida com sucesso!" << endl;
  }
  else
  {
    cout << "Nao foi possivel abrir o arquivo" << endl;
  }
  exit(1);
}




    /* Testes */
    /*
    tree->print();
    cout << " --------------------------" << endl;
    cout << "Tem salvador ? " << tree->find(new CityInfo(29,"2927408","Salvador", -12.9718,-38.5011,true)) << endl;
    Coordinate *teste = new Coordinate(-20,-40,-16,-1);
    vector<string> cidades;
    cidades = tree->getCitysInCoordinates(teste);
    cout << "Código das cidades no intervalo : ";
    for(string city : cidades){
      cout << city +  ",";
    }
    cout << endl;
    */