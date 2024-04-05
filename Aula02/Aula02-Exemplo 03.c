#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>

#define ERRO 1

struct Pessoa{
   char nome[100];
   int idade;
   float altura;
   float peso;

} typedef Pessoa;

Pessoa CadastrarPessoa(){
  Pessoa P;
  printf("Nome: ");
  gets(P.nome);
  printf("Idade: ");
  scanf("%d",&P.idade );
  printf("Altura: ");
  scanf("%f",&P.altura);
  printf("Peso: ");
  scanf("%f",&P.peso);

}

void ExibirPessoa(struct Pessoa X){
  printf("nome:%s , idade: %d , peso:%.2f ,  altura:%.2f \n",X.nome,X.idade,X.peso,X.altura);

}

float CalcularIMC(Pessoa X){
    float IMC = X.peso / pow(X.altura,2);
    return IMC;
}

void FazendoAniversario(Pessoa *X){
    X ->idade = X ->idade + 1;
} // Usando -> no

int main() {
  Pessoa X = CadastrarPessoa();
  ExibirPessoa(X);
  FazendoAniversario(&X);
  ExibirPessoa(X);
  printf("O IMC e igual a %.3f\n",CalcularIMC(X));
  return 0;


}