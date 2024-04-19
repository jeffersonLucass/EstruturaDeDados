#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item
{
    char Nome[128];
    int Quantidade;
    float Preco;
};

int main(){
   FILE *fp;
   FILE *html;
   struct Item X;
   fp=fopen("listadecompra.txt","r");
   html = fopen("resultado.html","w");
   if (fp != NULL || html != NULL)
   {
      printf("Arquivo nao pode ser aberto!!!\n");
      exit(1);
   }

   system("cls");
   float Total=0.0;

   fprintf(html,"")
   while (fscanf(fp,"%s %d %f",X.Nome,&X.Quantidade,&X.Preco) != EOF)
   {
      float SubTotal = X.Quantidade * X.Preco;
      printf("%s",X.Nome);
      printf("\t");
      printf("%d",X.Quantidade);
      printf("\t");
      printf("%f",X.Preco);
      printf("\t");
      printf("%.2f",SubTotal);
      printf("\n");

      Total =+ SubTotal;
   }
    



    fclose(fp);
    return 0;
}