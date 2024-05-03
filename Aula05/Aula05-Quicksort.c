#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


#define TAMANHO 400000
#define VERDADEIRO 1
#define FALSO 0



void swap(int *A,int *B){
   int temp = *A;  //A: valor apontado por A
   *A = *B;        //B: valor apontado por B
   *B = temp;
   printf("Teste : %d %d %d %d \n",A,*A,B,*B);
}           

int particao(int Vetor[],int inf,int sup){
    int pivot = Vetor[(inf +sup)/2];
    int i = inf -1;
    int j = sup + 1;
    
    while (VERDADEIRO)
    {
        do{i++;} while (Vetor[i] < pivot);
        do{j--;} while(Vetor[j] > pivot);
        if(i >= j)return i;
        swap(&Vetor[i],&Vetor[j]);
    }

}
void quicksort(int Vetor[],int inf,int sup){
    if (inf < sup)
    {
        int p = particao(Vetor,inf,sup); // calculando posição do pivot
        quicksort(Vetor,inf,p - 1);      //antes do pivot
        quicksort(Vetor,p + 1,sup);    //depois do pivot 
    }
    
}



void main(){
   system("cls");
   int V[] = {3,6,4,5,1,7,2};
   int T = sizeof(V) /sizeof(V[0]);
   quicksort(V,0,T - 1);
   for (int i = 0; i < T; i++)
   {
      printf("%d",V[i]);
      printf("\n");         
   }
   




}