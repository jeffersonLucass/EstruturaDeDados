#ifndef LISTA
#define LISTA

#define ERRO 1


//Definindo o formato de cada elemento da lista

typedef struct 
{
    int Chave;

    //Poderiam ser considerados outros atributos ...
}Item;

//Definindo a estrutura da lista

typedef struct 
{
    int Capacidade;
    int Tamanho;
    Item *Array;
}Lista;

// Operações para manipular os elementos da lista

Lista * criarLista(int Capacidade);





#endif


