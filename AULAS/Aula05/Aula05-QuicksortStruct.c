#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define VERDADEIRO 1
#define FALSO 0


struct dados
{
    int Idade;
    int Peso;
}; typedef struct dados Dados;


void swap(Dados **A,Dados **B){
    Dados *temp = *A;
    *A = *B;
    *B=temp;

}
int comparar(Dados **A,Dados **B){
    Dados *X = *A;
    Dados *Y = *B;
    int DeltaIdade = X->Idade - Y->Idade;
    int DeltaPeso = X->Peso - Y->Peso;
    
    if (X->Idade != Y->Idade)
    {
        return DeltaIdade;
        
    }else{
        return DeltaPeso;
    }
    

}
int particao(Dados **Vetor,int inf,int sup){
    Dados *Pivot = Vetor[(inf + sup)/2];
    int i = sup;
    int j = inf;
    while (i <= j)
    {
        while(comparar(&Vetor[i],&Pivot) < 0 )i++;
        while(comparar(&Vetor[j],&Pivot) > 0 )j--;
        if (i<=j)
        {
            swap(&Vetor[i],&Vetor[j]);
            i++;
            j--;
        }
        
    }
    return i; //i :posição do pivô
}
void quicksort(Dados **Vetor,int inf,int sup){
    if (inf < sup)
    {
        int P = particao(Vetor,inf,sup);
        quicksort(Vetor,inf,P - 1);
        quicksort(Vetor,P,sup);
    }
}



int main(){
    Dados D1={25,50};
    Dados D2={20,30};
    Dados D3={30,40};
    Dados D4={20,65};
    Dados D5={20,40};
    Dados D6={18,65};
    Dados D7={30,45};
    Dados D8={18,90};
    Dados D9={41,90}; 
    

    //Criar vetor de endereços de memória para dados.

    Dados *X[]= {&D1,&D2,&D3,&D4,&D5,&D6,&D7,&D8,&D9};
    int N = sizeof(X) /sizeof(X[0]);
    quicksort(X,0,N-1);
    for (int i = 0; i < N; i++)
    {
        printf("{%d,%d}\n", X[i]->Idade, X[i]->Peso);
    }
    



    return 0;
}