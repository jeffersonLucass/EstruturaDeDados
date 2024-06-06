#ifndef FRACAO_H
#define FRACAO_H
typedef struct {
    int Num;
    int Den;
} Fracao;

int mdc(int A, int B);
void mostrarFracao(Fracao F);
Fracao criarFracao(int A, int B);
Fracao simplificarFracao(Fracao F);
Fracao somarFracao(Fracao F, Fracao G);
Fracao subtrairFracao(Fracao F, Fracao G);
Fracao multiplicarFracao(Fracao F, Fracao G);
Fracao dividirFracao(Fracao F, Fracao G);
Fracao inverterFracao(Fracao F, Fracao G);
#endif