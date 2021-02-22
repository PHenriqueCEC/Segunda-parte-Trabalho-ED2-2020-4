echo "Começando a compilação do projeto"

g++ main.cpp -o main ./Classes/ArvoreB/ArvoreB.cpp
if [ $? -eq 0 ];then 
   echo "Compilado com sucesso! :)"
else
   echo "Nao compilado :("
fi