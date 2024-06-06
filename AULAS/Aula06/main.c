#include <stdio.h>
#include <stdlib.h>
#include "fracao.h"



int main() {

    Fracao Resultado;

    printf("Teste n. 1: Simplicando fracao: ");
    Fracao F = criarFracao(20, 30);
    Resultado = simplificarFracao(F);
    mostrarFracao(Resultado);
    printf("\n");

    printf("Teste n. 2: Somando as fracoes 5/6 e 4/9: ");
    Fracao F1 = criarFracao(5, 6);
    Fracao F2 = criarFracao(4, 9);
    Resultado = somarFracao(F1, F2);
    mostrarFracao(Resultado);
    printf("\n");

    printf("Teste n. 3: Subtraindo as fracoes 5/6 e 4/9: ");
    Fracao F3 = criarFracao(5, 6);
    Fracao F4 = criarFracao(4, 9);
    Resultado = subtrairFracao(F3, F4);
    mostrarFracao(Resultado);
    printf("\n");

    printf("Teste n. 4: Multiplicando as fracoes 5/7 e 21/20: ");
    Fracao F5 = criarFracao(5, 7);
    Fracao F6 = criarFracao(21, 20);
    Resultado = multiplicarFracao(F5, F6);
    mostrarFracao(Resultado);
    printf("\n");


    return 0;
}