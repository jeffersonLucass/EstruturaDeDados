#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double x;
    double y;
} Ponto;

float area_triangulo(Ponto a, Ponto b,Ponto c){
    return 0.5 * abs(a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y));
}

float calcularAreaPoligono(Ponto Vertices[], int TotalDeVertices) {
    float area = 0.0;

    for (int i = 0; i < TotalDeVertices -1; i++) {
        area += area_triangulo(Vertices[0],Vertices[i],Vertices[i + 1]);
    }

    return area;
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
    float area = calcularAreaPoligono(Vertices, TotalDeVertices);
    printf("A area do poligono eh: %.2lf\n", area);
    free(Vertices);

    return 0;
}
