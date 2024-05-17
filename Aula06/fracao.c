#include <stdio.h>
#include "fracao.h"

Fracao criarFracao(int A, int B){
    Fracao X;
    X.Num = A;
    X.Den = B;
    return X;
}

int mdc(int A, int B){
    int Menor;
    int M = 1;
    A = abs(A);
    B = abs(B);
    if  (A > B) Menor = B;
    else Menor = A;
    for (int i = 1; i <= Menor; i++) {
        if ((A % i == 0) && (B % i == 0)) M = i;
    }
    return M;
}

Fracao simplificarFracao(Fracao F){
    int temp = mdc(F.Num, F.Den);
    F.Num = F.Num / temp;
    F.Den = F.Den / temp;
    return F;
}

void mostrarFracao(Fracao F){
    printf("%d/%d", F.Num, F.Den);
}

Fracao somarFracao(Fracao F, Fracao G){
    Fracao Resultado;
    Resultado.Num = F.Num * G.Den + G.Num * F.Den;
    Resultado.Den = F.Den * G.Den;
    Resultado = simplificarFracao(Resultado);
    return Resultado;
}

Fracao subtrairFracao(Fracao F, Fracao G){
    Fracao Resultado;
    Resultado.Num = F.Num * G.Den - G.Num * F.Den;
    Resultado.Den = F.Den * G.Den;
    Resultado = simplificarFracao(Resultado);
    return Resultado;
}

Fracao subtrairFracao_V02(Fracao F, Fracao G){
    Fracao Resultado;
    G.Num = -G.Num;
    Resultado = somarFracao(F, G);
    return Resultado;
}

Fracao multiplicarFracao (Fracao F, Fracao G) {
    Fracao Resultado;
    Resultado.Num = F.Num * G.Num;
    Resultado.Den = F.Den * G.Den;
    Resultado = simplificarFracao(Resultado);
    return(Resultado);
}




