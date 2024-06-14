#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "calculadora.h"

#define MAX_SIZE 512

// Função para empilhar elementoos na pilha
void empilhar(float *stack, int *topo, float elemento) {
    stack[++(*topo)] = elemento;
}

// Função para desempilhar elementoos da pilha
float desempilhar(float *stack, int *topo) {
    return stack[(*topo)--];
}

// Função para avaliar uma expressão pós-fixa
float evaluatePostfix(char *expression) {
    float stack[MAX_SIZE];
    int topo = -1;
    char *token = strtok(expression, " "); // Dividir a expressão em tokens separados por espaço

    while (token != NULL) {
        if (isdigit(*token) || (*token == '-' && isdigit(*(token + 1)))) {
            // Se o token for um número, empilhá-lo
            empilhar(stack, &topo, atof(token));
        } else {
            // Se o token for um operador
            float operand2 = desempilhar(stack, &topo);
            float operand1 = desempilhar(stack, &topo);
            float result;

            switch (*token) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                case '^':
                    result = pow(operand1, operand2);
                    break;
                case 's': // seno
                    result = sin(operand2);
                    break;
                case 'c': // cosseno
                    result = cos(operand2);
                    break;
                case 't': // tangente
                    result = tan(operand2);
                    break;
                case 'l': // logaritmo de base 10
                    result = log10(operand2);
                    break;
                case 'r': // radiciação (raiz quadrada)
                    result = sqrt(operand2);
                    break;
                default:
                    printf("Operador inválido: %c\n", *token);
                    return 0;
            }

            // Empilhar o resultado
            empilhar(stack, &topo, result);
        }

        token = strtok(NULL, " "); // Próximo token
    }

    // O resultado final estará no topoo da pilha
    return desempilhar(stack, &topo);
}

// Função para obter a forma pós-fixa de uma expressão
char *getFormaPosFixa(char *Str) {
    return Str;
}

// Função para calcular o valor de uma expressão pós-fixa
float getValor(char *Str) {
    return evaluatePostfix(Str);
}



