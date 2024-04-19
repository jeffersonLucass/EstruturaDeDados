#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE * fp;
    int N;
    char Palavra[50];
    fp=fopen("dados.txt","r");  // "r" abre arquivo para leitura.

    if (fp==NULL)
    {
        printf("O arquivo nao pode ser aberto!");
        exit(1);
    }
    printf("Arquivo aberto com sucesso!!!");
    while (fscanf(fp,"%d %s",&N,Palavra) != EOF)
    {
        printf("%s  %d\n");
    }
        
    fscanf(fp,"%d %s",&N,Palavra);
    printf("Resultado: \n");
    printf("%d\n",N);
    printf("%s\n",Palavra);
    
    fclose(fp);
   
    
    return 0;
}