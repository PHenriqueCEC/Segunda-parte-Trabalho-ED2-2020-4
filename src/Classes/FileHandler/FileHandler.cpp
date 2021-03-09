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
    cout << "Arq opened" << endl;
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

vector<CityInfo*> FileHandler::getNRandomCityInfo(int n ){
  std::random_device device;
  std::mt19937 generator(device());
  std::uniform_int_distribution<int> distribution(0,this->citysList.size() - 1);
  vector<CityInfo*> sortedInfos;
  int drawn = 0;

  //Vetor auxiliar para eu controlar quais indices ja foram gerados
  vector<bool> usedIndexs;
  for(int i = 0 ; i < this->citysList.size() ; i++)
  usedIndexs.push_back(false);

  for(int i = 0 ; i < n - 1 ; i++){
      //Garanto que o indice que gerei ainda não foi utilizado , para não ocorrerem duplicatas.
      while(usedIndexs[drawn])
         drawn = distribution(generator);
      
      sortedInfos.push_back(this->citysList.at(i));
      //Adiciono o número sorteado no meu vetor de indices já sorteados
      usedIndexs[drawn] = true;

  } 

  usedIndexs.~vector();
  return sortedInfos;
}



/*Função para armazenar os registros do csv brazil_covid19_cities.csv em um Array da classe CovidInfo*/
//insertCityListInQuadTree (Mudar o nome)
void FileHandler::processCityInfo(string filename)
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
      if (line >= 1)
      {
        //@Todo inserção dos dados obtidos na quadtree;
        CityInfo *info = new CityInfo(stoi(state_code), city_code, city_name, stof(latitutde), stof(longitude), isCapital == "TRUE");
        tree->insert(tree->root, info);
      }
      line++;
    }
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
    delete tree;
    cout << "Arquivo processado com sucesso" << endl;
  }
  else
  {

    cout << "Nao foi possivel abrir o arquivo" << endl;
  }
}

