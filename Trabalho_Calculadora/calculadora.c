#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "calculadora.h"

void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAXSTACK - 1;
}

void push(Stack *s, char *value) {
    if (isFull(s)) {
        printf("Stack overflow\n");
        exit(1);
    }
    s->stack[++s->top] = value;
}

char *pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        exit(1);
    }
    return s->stack[s->top--];
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int precedence(char c) {
    switch (c) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

double applyOperator(double a, double b, char operator) {
    switch (operator) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return pow(a, b);
        default:
            printf("Invalid operator: %c\n", operator);
            exit(1);
    }
}

double evaluatePostfix(const char* expression) {
    Stack stack;
    initStack(&stack);

    char *exprCopy = strdup(expression);
    char *token = strtok(exprCopy, " ");
    while (token != NULL) {
        if (isOperator(token[0]) && token[1] == '\0') {
            double b = atof(pop(&stack));
            double a = atof(pop(&stack));
            double result = applyOperator(a, b, token[0]);
            char resultStr[20];
            sprintf(resultStr, "%lf", result);
            push(&stack, strdup(resultStr));
        } else if (strcmp(token, "raiz") == 0) {
            double a = atof(pop(&stack));
            double result = sqrt(a);
            char resultStr[20];
            sprintf(resultStr, "%lf", result);
            push(&stack, strdup(resultStr));
        } else if (strcmp(token, "sen") == 0) {
            double a = atof(pop(&stack));
            double result = sin(a);
            char resultStr[20];
            sprintf(resultStr, "%lf", result);
            push(&stack, strdup(resultStr));
        } else if (strcmp(token, "cos") == 0) {
            double a = atof(pop(&stack));
            double result = cos(a);
            char resultStr[20];
            sprintf(resultStr, "%lf", result);
            push(&stack, strdup(resultStr));
        } else if (strcmp(token, "tg") == 0) {
            double a = atof(pop(&stack));
            double result = tan(a);
            char resultStr[20];
            sprintf(resultStr, "%lf", result);
            push(&stack, strdup(resultStr));
        } else if (strcmp(token, "log") == 0) {
            double a = atof(pop(&stack));
            double result = log10(a);
            char resultStr[20];
            sprintf(resultStr, "%lf", result);
            push(&stack, strdup(resultStr));
        } else {
            push(&stack, strdup(token));
        }
        token = strtok(NULL, " ");
    }
    double result = atof(pop(&stack));
    free(exprCopy);
    return result;
}

char* infixToPostfix(const char* infix) {
    Stack stack;
    initStack(&stack);
    char *postfix = malloc(MAXEXPR);
    int k = 0;

    for (int i = 0; infix[i]; i++) {
        if (isdigit(infix[i]) || infix[i] == '.') {
            while (isdigit(infix[i]) || infix[i] == '.') {
                postfix[k++] = infix[i++];
            }
            postfix[k++] = ' ';
            i--;
        } else if (infix[i] == '(') {
            push(&stack, strdup(&infix[i]));
        } else if (infix[i] == ')') {
            while (!isEmpty(&stack) && *stack.stack[stack.top] != '(') {
                postfix[k++] = *pop(&stack);
                postfix[k++] = ' ';
            }
            pop(&stack);
        } else if (isOperator(infix[i])) {
            while (!isEmpty(&stack) && precedence(*stack.stack[stack.top]) >= precedence(infix[i])) {
                postfix[k++] = *pop(&stack);
                postfix[k++] = ' ';
            }
            push(&stack, strdup(&infix[i]));
        }
    }

    while (!isEmpty(&stack)) {
        postfix[k++] = *pop(&stack);
        postfix[k++] = ' ';
    }

    postfix[k-1] = '\0'; // Remove o espaço final
    return postfix;
}

char* postfixToPrefix(const char* postfix) {
    Stack stack;
    initStack(&stack);
    char *prefix = malloc(MAXEXPR);
    char temp[MAXEXPR];

    char *exprCopy = strdup(postfix);
    char *token = strtok(exprCopy, " ");
    while (token != NULL) {
        if (isOperator(token[0]) && token[1] == '\0') {
            char *b = pop(&stack);
            char *a = pop(&stack);
            sprintf(temp, "%c %s %s", token[0], a, b);
            push(&stack, strdup(temp));
            free(a);
            free(b);
        } else {
            push(&stack, strdup(token));
        }
        token = strtok(NULL, " ");
    }
    strcpy(prefix, pop(&stack));
    free(exprCopy);
    return prefix;
}
