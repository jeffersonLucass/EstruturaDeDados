#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double x;
    double y;
} Ponto;

double calcularAreaTriangulo(Ponto* Vertices, int TotalDeVertices) {
    double area = 0.0;
    int k = TotalDeVertices - 1;

    for (int i = 0; i < TotalDeVertices; i++) {
        area += (Vertices[k].x + Vertices[i].x) * (Vertices[k].y - Vertices[i].y);
        k = i;
    }

    return abs(area / 2.0);
}

int main() {
    FILE *arquivo= fopen("trianguloABC.txt.txt", "r");
    int TotalDeVertices;
    Ponto *Vertices;

    if (arquivo == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo.\n");
        return 1;
    }
    fscanf(arquivo, "%d", &TotalDeVertices);
    Vertices = (Ponto *)malloc(TotalDeVertices * sizeof(Ponto));
    for (int i = 0; i < TotalDeVertices; i++) {
        fscanf(arquivo, "%lf %lf", &Vertices[i].x, &Vertices[i].y);
    }
    fclose(arquivo);
    double area = calcularAreaTriangulo(Vertices, TotalDeVertices);
    printf("A area do poligono eh: %.2lf\n", area);
    free(Vertices);

    return 0;
}
