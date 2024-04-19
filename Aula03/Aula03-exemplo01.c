#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *fp;
    fp=fopen("pagina.txt","w");

    if (fp==NULL)
    {
        printf("O arquivo nao pode ser aberto!");
        exit(1);
    }
    printf("Arquivo aberto com sucesso!!!");
    fclose(fp);
    return (0);
    



    return 0;
}