#include "cidades.h"
#include <string.h>

// Função para inicializar a estrutura Estrada a partir de um arquivo
Estrada *getEstrada(const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (!arquivo) {
        perror("Erro ao abrir o arquivo");
        return NULL;
    }

    Estrada *estrada = (Estrada *)malloc(sizeof(Estrada));
    if (!estrada) {
        perror("Erro ao alocar memória para Estrada");
        fclose(arquivo);
        return NULL;
    }

    fscanf(arquivo, "%d", &(estrada->T));
    fscanf(arquivo, "%d", &(estrada->N));

    estrada->C = (Cidade *)malloc(estrada->N * sizeof(Cidade));
    if (!estrada->C) {
        perror("Erro ao alocar memória para as cidades");
        free(estrada);
        fclose(arquivo);
        return NULL;
    }

    char linha[512];
    for (int i = 0; i < estrada->N; i++) {
        // Ler a linha inteira e depois usar sscanf para extrair os valores
        fgets(linha, sizeof(linha), arquivo);
        sscanf(linha, "%d %[^\n]", &(estrada->C[i].Posicao), estrada->C[i].Nome);
    }

    fclose(arquivo);
    return estrada;
}

// Função para calcular a menor vizinhança de estrada entre as cidades
double calcularMenorVizinhanca(const char *nomeArquivo) {
    Estrada *estrada = getEstrada(nomeArquivo);
    if (!estrada) return -1;

    double menorVizinhanca = estrada->T;
    for (int i = 0; i < estrada->N - 1; i++) {
        double vizinhancaAtual = (estrada->C[i + 1].Posicao - estrada->C[i].Posicao) / 2.0;
        if (vizinhancaAtual < menorVizinhanca) {
            menorVizinhanca = vizinhancaAtual;
        }
    }

    free(estrada->C);
    free(estrada);
    return menorVizinhanca;
}

// Função para encontrar a cidade com a menor vizinhança
char *cidadeMenorVizinhanca(const char *nomeArquivo) {
    Estrada *estrada = getEstrada(nomeArquivo);
    if (!estrada) return NULL;

    double menorVizinhanca = estrada->T;
    char *cidadeMenor = (char *)malloc(256 * sizeof(char));
    if (!cidadeMenor) {
        perror("Erro ao alocar memória para cidadeMenor");
        free(estrada->C);
        free(estrada);
        return NULL;
    }
    
    for (int i = 0; i < estrada->N - 1; i++) {
        double vizinhancaAtual = (estrada->C[i + 1].Posicao - estrada->C[i].Posicao) / 2.0;
        if (vizinhancaAtual < menorVizinhanca) {
            menorVizinhanca = vizinhancaAtual;
            strcpy(cidadeMenor, estrada->C[i].Nome);
        }
    }

    free(estrada->C);
    free(estrada);
    return cidadeMenor;
}
