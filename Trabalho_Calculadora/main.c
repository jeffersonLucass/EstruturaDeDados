#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "calculadora.h"

int main() {
    char posFixa1[] = "53 23 + 8 2 - *";
    char posFixa2[] = "10 2 / 3 4 * +";
    char posFixa3[] = "12 3 / 4 2 ^ +";

    // Convertendo para a forma infixa
    char *inFixa1 = getFormaInFixa(posFixa1);
    char *inFixa2 = getFormaInFixa(posFixa2);
    char *inFixa3 = getFormaInFixa(posFixa3);

    // Calculando o valor das expressões
    float valor1 = getValor(posFixa1);
    float valor2 = getValor(posFixa2);
    float valor3 = getValor(posFixa3);

    // Imprimindo os resultados
    printf("Expressao 1: %s\n", posFixa1);
    printf("Infixa 1: %s\n", inFixa1);
    printf("Valor 1: %.2f\n\n", valor1);

    printf("Expressao 2: %s\n", posFixa2);
    printf("Infixa 2: %s\n", inFixa2);
    printf("Valor 2: %.2f\n\n", valor2);

    printf("Expressao 3: %s\n", posFixa3);
    printf("Infixa 3: %s\n", inFixa3);
    printf("Valor 3: %.2f\n\n", valor3);

    return 0;
}


