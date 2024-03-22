#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define ERRO -1234


int MyStrlen(char *str){
   int tamanho;
   for (tamanho = 0; str[tamanho]!= '\0'; tamanho++)
   {
       return tamanho;
   }
}


void main(){
   char Frase[] = "Meu nome e Eneias!!!";
   printf("%s - %d caracteres.\n", Frase ,MyStrlen(Frase));



}