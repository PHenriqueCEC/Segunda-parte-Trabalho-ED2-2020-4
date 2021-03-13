#include "../AvlNode/AvlNode.h"
#include "./AvlTree.h"
#include <iostream>
#include <string>
#include <random>
using namespace std;
#define COUNT 10

///////////////////////
//////CONSTRUTOR//////
/////////////////////

AvlTree::AvlTree()

{
  // Inicializamos a raíz com null e as comparações com 0.
  this->root = nullptr;
  this->comparisonsInsert = 0;
  this->comparisonsSearch = 0;
}


///////////////////////
//////DESTRUTOR///////
/////////////////////

AvlTree::~AvlTree()
{
  if(this->root == NULL)
  {
    return;
  }
  this->freeNode(root); //Irá liberar cada nó
  free(this->root); //Irá liberar a raiz
}
void AvlTree::freeNode(AvlNode *p)
{
  if(p == NULL)
  {
    return;
  }
  freeNode(p->getLeft());
  freeNode(p->getRight());
  free(p);
  p = NULL;
}

///////////////////////
//////AUXILARES///////
/////////////////////

//Função get para obter o número de comparações feitas na inserção
int AvlTree::getInsertComparisons()
{
  return this->comparisonsInsert;
}

//Função get para obter o número de comparações feitas na busca
int AvlTree::getSearchComparisons()
{
  return this->comparisonsSearch;
}

///////////////////////
////BALANCEAMENTO/////
/////////////////////

//Função que servirá para retornar a altura de um nó especifico
int AvlTree::height(AvlNode *p)
{
  //Caso o nó p seja nulo, retornaremos -1, porque um nó nulo tem altura igual a -1
  //Um single node tem altura igual a 0
  if(p == NULL)
  {
    return -1;
  }
  else
  {
    //E um nó com filhos terá altura igual a altura do maior lado de subarvores(esquerdo ou direito) + 1 (que é o proprio nó);
    return p->getHeight();
  }
}

//Função que irá verificar qual lado tem maior altura, e irá retornar ou lado esquerdo ou lado direito.
int AvlTree::getHeight(AvlNode *p){
  //Inicializo a altura da subarvore esquerda e da subarvore direita com 0;
  int leftHeight = 0;
  int rightHeight = 0;

  //Irá verificar se o nó a esquerda de p é nulo
  if  (p->getLeft())
  {
    //Caso não seja nulo, a altura esquerda irá chamar de forma recurssiva a função getHeight, com o filho à esquerda.
    leftHeight = getHeight(p->getLeft());
  }

  //Irá verificar se o nó a direita de p é nulo
	if (p->getRight())
  {
    //Caso não seja nulo, a altura direita irá chamar de forma recurssiva a função getHeight, com o filho à direita
    rightHeight = getHeight(p->getRight());
  }

	//Por fim retornaremos a maior altura dentre a altura do lado esquerdo e direito, esse retorno servirá tanto para 
  //incrementar os valores de rightHeight e leftHeight das chamadas anteriores, quanto para o retorno final com os
  //valores finais de rightHeight e leftHeight que é o que queremos pois iremos obter qual lado tem a maior altura. 
	return higherElement(rightHeight, leftHeight) + 1;
}

//Função que irá verificar qual maior elemento entre a e b, será usado para verificar qual é lado tem maior altura.
//Fiz desse jeito e vi algumas outras implementações utilizando esse mesmo modelo pois modularizará melhor o nosso código.
int AvlTree::higherElement(int a, int b){ 
  //if, else básico, se a é maior que b retorna a, se b é maior que a retorna b
  if(a > b)
  {
    return a;
  }
  else
  {
    return b;
  }
}

///////////////////////
/////////BUSCA////////
/////////////////////

//Função que irá buscar um valor na arvore e irá retornar false se não achar e true se achar
bool AvlTree::search(int value)
{
  //A função de busca é a mesma utilizada para a árvore binária de busca
  //visto que a árvore AVL é uma árvore binária de busca, porém balanceada.
  AvlNode *p = this->root;

  //O funcionamento é bem simples, a partir do nó raiz, iremos andando pelos nós filhos
  //levando em conta o valor recebido para busca, que irá decidir qual lado, esquerdo ou direito,
  //devemos ir até acharmos o valor desejado.
  while (p != nullptr)
  {
    if (p->getValue() == value)
    {
      //Caso o valor seja encontrado, será retornado true.
      this->comparisonsSearch++;
      return true;
    }

    if (value > p->getValue())
    {
      this->comparisonsSearch++;
      p = p->getRight();
    }
    else
    {
      p = p->getLeft();
    }
  }

  //Caso o valor não seja encontrado, será retornado false.
  return false;
}

//Função que irá retornar o fator de balanceamento de um nó
int AvlTree::getBalance(AvlNode *p)
{
  //Caso o nó seja nulo irá retornar -1
  if (p == NULL)
  {
    return -1;
  }
  //Caso contrário, iremos retornar a diferença entre a altura do nó filho a esquerda e do nó filho a direita.
  //Essa diferença entre altura do nó a esquerda e altura do nó a direita nada mais é que o fator de balanceamento do nó pai.
  return height(p->getLeft()) - height(p->getRight());
}

///////////////////////
////////INSERÇÃO//////
/////////////////////

//Função auxiliar para facilitar a inserção
void AvlTree::doInsert(int value)
{
  this->root = insert(this->root, value);
}

//Função que irá inserir nós na árvore
//A inserção foi feita de forma a não permitir a inserção de um valor já inserido.
AvlNode* AvlTree::insert(AvlNode *p, int value)
{
  if (p == NULL)
  {
    //Caso p seja nulo será criado e retornado um novo nó, com o valor recebido
    AvlNode *r = new AvlNode(value);
    return r;
  }

  //Mesma coisa da inserção da árvore binaria de busca, levamos o valor em consideração
  //e iremos para o lado (esquerdo ou direito), no qual o valor se adequa.
  //Filhos a direita são valores maiores que o nó pai, e filhos a esquerda são valores menores.
  if (value < p->getValue())
  {
    //Caso o valor seja menor, o nó irá para direita
    this->comparisonsInsert++;
    p->setLeft(insert(p->getLeft(), value));
  }
  else if (value > p->getValue())
  {
    //Caso o valor seja maior, o nó irá para direita
    this->comparisonsInsert++;
    p->setRight(insert(p->getRight(), value));
  } 
  else
  {
    //Caso o valor seja igual retornaremos o proprio nó
    return p;
  }

  //Atualiza o fator de balanceamento dos nós
  p->setHeight( 1 + higherElement(height(p->getLeft()),height(p->getRight())));

  //Agora é feito o balanceamento
  int balanceFactor = getBalance(p); // obtemos o fator de balanceamento do nó

  //Iremos verificar qual lado está mais "pesado".
  //E verificaremos também se será necessario uma rotação dupla ou simples, levando os valores dos nós em consideração.
  //Caso o lado direito seja o mais pesado o fator de balanceamento é positivo.
  if (balanceFactor > 1) { 
    if (value < p->getLeft()->getValue()) {
      this->comparisonsInsert++;
      return simpleRotationRight(p);
    } else if (value > p->getLeft()->getValue()) {
      this->comparisonsInsert++;
      return doubleRotationRight(p);
    }
  }
  //Caso o lado esquerdo seja o mais pesado o fator de balanceamento é negativo.
  if (balanceFactor < -1) {
    if (value > p->getRight()->getValue()) {
      this->comparisonsInsert++;
      return simpleRotationLeft(p);
    } else if (value < p->getRight()->getValue()) {
      this->comparisonsInsert++;
      return doubleRotationLeft(p);
    }
  }

  return p;
}


///////////////////////
///////ROTAÇÕES///////
/////////////////////

//Rotação simples direita-direita
AvlNode* AvlTree::simpleRotationLeft(AvlNode *p)
{
  //Efetua a rotação simples direita-direita
  //Referência: Slides do caniato
  AvlNode *q = p->getRight();
  p->setRight(q->getLeft());
  q->setLeft(p);

  //Reajusta alturas dos nós, pois a rotação poderá alterar suas respectivas alturas.
  p->setHeight(higherElement(height(p->getLeft()), height(p->getRight())) + 1);
  q->setHeight(higherElement(height(q->getLeft()), height(q->getRight())) + 1);

  return q;
}

//Rotação simples esquerda-esquerda
AvlNode* AvlTree::simpleRotationRight(AvlNode *p)
{
  //Efetua a rotação simples esquerda-esquerda
  //Referência: Slides do caniato
  AvlNode *q = p->getLeft();
  p->setLeft(q->getRight());
  q->setRight(p);

  //Reajusta alturas dos nós, pois a rotação poderá alterar suas respectivas alturas.
  p->setHeight(higherElement(height(p->getLeft()), height(p->getRight())) + 1);
  q->setHeight(higherElement(height(q->getLeft()), height(q->getRight())) + 1);
  
  return q;
}

//Rotação dupla direita-esquerda
AvlNode* AvlTree::doubleRotationLeft(AvlNode *p)
{
  //Efetua a rotação dupla direita-esquerda, primeiro realiza rotação para direita depois para esquerda
  //Referência: Slides do caniato
  p->setRight(simpleRotationRight(p->getRight()));
  return simpleRotationLeft(p);
}

//Rotação dupla esquerda-direita
AvlNode* AvlTree::doubleRotationRight(AvlNode *p)
{
  //Efetua a rotação dupla esquerda-direita, primeiro realiza rotação para esquerda depois para direita
  //Referência: Slides do caniato
  p->setLeft(simpleRotationLeft(p->getLeft()));
  return simpleRotationRight(p);
}


AvlNode *AvlTree::getRoot()
{
  return this->root;
}

void AvlTree::printTree(AvlNode *root, string indent, bool last, bool isWriteInFile, ofstream &file)
{
  if (root != nullptr)
  {
    if (!isWriteInFile)
    {
      cout << indent;
      if (last)
      {
        cout << "R----";
        indent += "   ";
      }
      else
      {
        cout << "L----";
        indent += "|  ";
      }
      cout << root->getValue() << endl;
      printTree(root->getLeft(), indent, false , false , file);
      printTree(root->getRight(), indent, true , false , file);
    }

    if (isWriteInFile)
    {
      file << indent;
      if (last)
      {
        file << "R----";
        indent += "   ";
      }
      else
      {
        file << "L----";
        indent += "|  ";
      }
      file << root->getValue() << endl;
      printTree(root->getLeft(), indent, false ,true , file);
      printTree(root->getRight(), indent, true , true , file);
    }
  }
}
void AvlTree::doPrint(bool isWriteInFile)
{
  ofstream arq("saidaTestes.txt");
  if(isWriteInFile){
    arq << "--------------------------------------------------------------------" << endl;
    arq << "Num de comparacoes na inserção : " << this->comparisonsInsert << endl;
    arq << "Num de comparacoes na busca : " << this->comparisonsSearch << endl;
    arq << "--------------------------------------------------------------------" << endl;
  }else{
    cout << "--------------------------------------------------------------------" << endl;
    cout << "Num de comparacoes na inserção : " << this->comparisonsInsert << endl;
    cout << "Num de comparacoes na busca : " << this->comparisonsSearch << endl;
    cout << "--------------------------------------------------------------------" << endl;
  }
  printTree(root, "", true ,isWriteInFile,arq);

  if(isWriteInFile){
    cout << "O arquivo de saida foi salvo no arquivo : saidaTestes.txt" << endl;
  }
}