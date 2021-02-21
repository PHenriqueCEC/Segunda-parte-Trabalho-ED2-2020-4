echo "Começando a compilação do projeto"

cd ./Classes && g++ ./CityInfo/CityInfo.cpp ./QuadTree/QuadTree.cpp ./QuadTree/TreeNode.cpp ./FileHandler/FileHandler.cpp ../main.cpp -o ../main
if [ $? -eq 0 ];then 
   echo "compilado com sucesso!"
else
   echo "nao compilado"
fi