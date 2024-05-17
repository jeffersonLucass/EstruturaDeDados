#include <stdio.h>
#include <stdlib.h>

#include "lista.h";

Lista * criarLista(int Capacidade){
    Lista * L =(Lista *)  malloc(sizeof(Lista));
    if (L==NULL)
    {
      printf("Erro ao alocar memoria para a Lista!\n");
      exit(ERRO);
    }

    L ->Array = (Item *) malloc(Capacidade * sizeof(Item));
    if (L ->Array == NULL)
    {
        printf("Erro ao colocar memoria para para o vetor de itens.\n");
        free(L);
        exit(ERRO);
    }

    L-> Capacidade= Capacidade;
    L -> Tamanho=0;
     
    





}