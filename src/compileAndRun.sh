echo "Começando a compilação do projeto"

g++ main.cpp -o main
if [ $? -eq 0 ];then 
   echo "compilado com sucesso!"
   ./main
else
   echo "nao compilado"
fi