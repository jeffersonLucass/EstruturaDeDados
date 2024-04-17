#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct 
{
    float X;
    float Y;
} Ponto;

float AreaTriangulo(float x1, float y1, float x2, float y2, float x3, float y3){
    return fabs((x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2)) / 2.0);
}



int main(){
   float x1 = 0.0, y1 = 0.0;
   float x2 = 4.0, y2 = 0.0;
   float x3 = 0.0, y3 = 3.0;
   printf("Área do triângulo: %.2f\n",AreaTriangulo(x1, y1, x2, y2, x3, y3));






    return 0;
}