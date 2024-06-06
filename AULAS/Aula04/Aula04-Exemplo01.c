#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main(){
   int *V;
   int tamanho = 200000;

   V=malloc(tamanho * sizeof(int));  //Gera o vetor de 50.000 posições.
   
   srand(time(NULL)); 
   for (int i = 0; i < tamanho; i++)
   {
      V[i]=rand() % 21;
      //RAND() gera números inteiros aleatório.
   }
   for (int i = 0; i < tamanho; i++)
   {
      printf("%d ",V[i]);
   }
   




    return 0;
}