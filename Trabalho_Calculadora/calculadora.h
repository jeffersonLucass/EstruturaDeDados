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
    int top;
    char *stack[MAXSTACK];
} Stack;

void initStack(Stack *s);
int isEmpty(Stack *s);
int isFull(Stack *s);
void push(Stack *s, char *value);
char *pop(Stack *s);
int isOperator(char c);
int precedence(char c);
double applyOperator(double a, double b, char operator);
double evaluatePostfix(const char* expression);
char* infixToPostfix(const char* infix);
char* postfixToPrefix(const char* postfix);

#endif
