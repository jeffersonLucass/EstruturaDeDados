#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "calculadora.h"

int main() {
    const char* expressions[] = {
        "3 4 2 * 1 5 - 2 3 ^ ^ / +",
        "3 4 + 5 *",
        "7 2 * 4 +",
        "8 5 2 4 + * +",
        "6 2 / 3 + 4 *",
        "9 5 2 8 * 4 + * +",
        "2 3 + log 5 /",
        "10 log 3 ^ 2 +",
        "45 60 + 30 cos *",
        "0.5 45 sen 2 ^ +"
    };

    for (int i = 0; i < 10; i++) {
        printf("Postfix: %s\n", expressions[i]);
        printf("Resultado: %lf\n", evaluatePostfix(expressions[i]));
        printf("Prefix: %s\n\n", postfixToPrefix(expressions[i]));
    }

    return 0;
}
