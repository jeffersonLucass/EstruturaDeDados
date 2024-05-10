#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE * fp;
    int Numero;
    char Palavra[50];

    fp = fopen("dados.txt", "r");  // "r" abre arquivo para leitura

    if(fp == NULL) {
        printf("O arquivo não pode ser aberto!");
        exit(1);
    }

    printf("Arquivo aberto com sucesso!!!");

    while(fscanf(fp, "%d %s", &Numero, Palavra) != NULL) {
        printf("\n%s %d", Palavra, Numero);
    }

    fclose(fp);
    return (0);
}