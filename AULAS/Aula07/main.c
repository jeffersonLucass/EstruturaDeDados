#include <stdio.h>
#include <stdlib.h>

#include "lista.h";

int main(){

    Lista *L = criarLista(10);   //Criando lista de 10 elementos.

    printf("%d\n",sizeof(L));
    printf("%d\n",sizeof(L->Array));

    free(L ->Array);
    free(L);

}