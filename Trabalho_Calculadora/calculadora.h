#ifndef CALCULADORA_H
#define CALCULADORA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAXSTACK 100
#define MAXEXPR 100

typedef struct {
    char posFixa[512];     // Expressão na forma pos fixa, como 3 12 4 + *
    char inFixa[512];      // Expressão na forma pos fixa, como 3 * (12 + 4)
    float Valor;           // Valor numérico da expressão  
} Expressao;


char *getFormaInFixa(char *Str);    // Retorna a forma inFixa de Str (posFixa)
float getValor(char *Str);          // Calcula o valor de Str (na forma posFixa)


#endif
