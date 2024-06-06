#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define ERRO -1234

int g(int N);

void main () {
    system("cls");
    int X = g(3);
    printf("Resposta: %d\n", X);
}

int g(int X){
    if(X == 0) return (-1);
    else if (X > 0) return (4 * g(X - 1) + 6);
    else return(ERRO);
}
