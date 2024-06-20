#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PALAVRAS 1000  // Define o tamanho máximo do array de palavras
#define MAX_LINHA 100      // Define o tamanho máximo de cada palavra

void ImprimirMatriz(char matriz[5][5]) {

    for (int row = 0; row < 5; row++)
    {
        printf("\n");
        for (int col = 0; col < 5; col++)
        {
            printf(" ___      ");
        }  
        printf("\n");
        for (int col = 0; col < 5; col++)
        {
            printf("|   |     ");
        }  
        printf("\n");
        for (int col = 0; col < 5; col++)
        {
            printf("| %c |     ", matriz[row][col]);
        }  
        printf("\n");
        for (int col = 0; col < 5; col++)
        {
            printf("|___|     ");
        }  
        printf("\n");
    }
}

int main() {
    int choice = 0;
    // FILE *arquivo;
    // char palavra_sorteada[7];
    // char linha[MAX_LINHA];
    // char *palavras[MAX_PALAVRAS];
    // int i = 0;



    printf("Escolha o nivel que deseja jogar\n1- Facil\n2- Medio\n3- Dificil\n > ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("MODO FACIL");
        // arquivo = fopen("palavras/facil.txt", "rt");
        
        char matriz[5][5];

        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                matriz[i][j] = "O";
            }     
        }

        ImprimirMatriz(matriz);

        break;
    case 2:
        printf("MODO MEDIO");
        // arquivo = fopen("palavras/medio.txt", "rt");
        break;
    case 3:
        printf("MODO DIFÍCIL");
        // arquivo = fopen("palavras/dificil.txt", "rt");
        break;
    
    default:
        break;
    }
    

    // fclose(arquivo);
}
