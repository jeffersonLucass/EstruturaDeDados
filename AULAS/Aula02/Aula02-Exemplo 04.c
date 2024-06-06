#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERRO 1


void exibirArray(int array[],int tamanho){
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d\t",array[i]);
    }
    printf("\n");
}

//array é um ponteiro para inteiro.

void modificarArray(int *array,int tamanho){
  printf("Endereco : %d\n",array);
  for (int i = 0; i < tamanho; i++)
  {
     array[i]=array[i]*2;
  }
  
}
//A função malloc reserva uma quantidade de bytes dentro daquela função.

int *criarArray(int tamanho){
   int *vetor = malloc(tamanho*sizeof(int));  //Alocação dinâmica
   for (int i = 0; i < tamanho; i++)
   {
     vetor[i] = 2* i - 1;
     
   }
   return vetor; // array indica o endereço do vetor
}
int main(){
  int T;
  printf("Digite um inteiro qualquer:");
  scanf("%d",&T);
  int *Vetor = criarArray(T);
  exibirArray(Vetor,T);
  modificarArray(Vetor,T);
  exibirArray(Vetor,T);

  return 0;
}