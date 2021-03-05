echo "Começando a compilação do projeto"

cd ./Classes && g++ ./CityInfo/CityInfo.cpp ./QuadTree/QuadTree.cpp ./QuadTree/TreeNode.cpp ./FileHandler/FileHandler.cpp ./Coordinate/Coordinate.cpp ./Classes/ArvoreB/ArvoreB.cpp ./Classes/NoB/NoB.cpp ../main.cpp -o ../main

if [ $? -eq 0 ];then 
   echo "Compilado com sucesso! :)"
else
   echo "Nao compilado :("
fi