#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char word[] = "assim";
    char * copy = malloc(sizeof(strlen(word)));
    strcpy(copy,word);
    
    char * resp = malloc(sizeof(strlen(word)));;
    int * nussa = malloc(sizeof(strlen(word)));;

    scanf("%s",resp);
    int certo = 0;
    int mei_certo = 0;
    int errado = 0;

    for(int i=0; i<strlen(word); i++)
        if(word[i] == resp[i])
        {
            copy[i] = '0';
            nussa[i] = 0;
            certo++;
        }
    
    printf("\n%s",copy);
    printf("\nlen : %d",strlen(word));
    
    for(int i=0; i<strlen(word); i++)
        for(int j=0; j<strlen(word); j++)
            if(copy[i] == resp[j])
            {
                copy[i] = '1';
                nussa[j] = 1;
                mei_certo++;
            } 

    printf("\n%s\n",copy);

    for (int i = 0; i < 5; i++)
        printf("%d ", nussa[i]);
    
    printf("\n\ncerto  %d\nmei_certo  %d\nerrado  %d",certo,mei_certo,errado);
}