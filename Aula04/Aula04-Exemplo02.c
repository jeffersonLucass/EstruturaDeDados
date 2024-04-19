#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main(){
   int *V;
   int tamanho = 400000;


   V=malloc(tamanho * sizeof(int));  //Gera o vetor de 50.000 posições.
   
   srand(time(NULL)); 

   clock_t Inicio = clock();
   for (int i = 0; i < tamanho; i++)
   {
      V[i]=rand() % 21;
      //RAND() gera números inteiros aleatório.
   }
   for (int i = 0; i < tamanho; i++)
   {
      printf("%d ",V[i]);
   }
   
   clock_t Fim=clock();
   double TempoCPU = ((double)(Fim-Inicio)) / CLOCKS_PER_SEC;
   printf("Tempo de execucao : %lf",TempoCPU);


    return 0;
}