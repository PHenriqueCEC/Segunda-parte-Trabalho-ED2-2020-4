#include "./FileHandler.h"

FileHandler::FileHandler()
{
}

FileHandler::~FileHandler()
{
}

/*Função para armazenar os registros do csv brazil_covid19_cities.csv em um Array da classe CovidInfo*/
void FileHandler::processCityInfo(string filename)
{
  int line = 0;
  ifstream arq("brazil_cities_coordinates.csv");
  string state_code, city_code, city_name, latitutde, longitude, IsCapital;
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
      getline(arq, IsCapital);

      //Pula a primeira linha do arquivo , pois é o header informativo o que cada coluna significa
      if (line >= 1)
      {
        //@Todo inserção dos dados obtidos na quadtree;
        CityInfo *info = new CityInfo(stoi(state_code), city_code, city_name, stof(latitutde), stof(longitude), true);
        tree->Insert(tree->root, info);
      }
      line++;
    }
    tree->Print();
    cout << "Arquivo processado com sucesso" << endl;
  }
  else
  {

    cout << "Nao foi possivel abrir o arquivo" << endl;
  }
}