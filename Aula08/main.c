#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

int main(){

  Lista *A = criarLista(10);

  printf("Teste 01:\n");
  printf("O tamanho da lista é %d. \n",A ->Tamanho);
  
  free(A->Array);
  free(A);


}