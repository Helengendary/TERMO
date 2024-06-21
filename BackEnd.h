#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#ifndef BACKEND_H
#define BACKEND_H


int LerArquivo(char nomeArq[50], char palavritas[50][10]) {
    FILE *arquivo;
    char c;
    int indicePalavras = 0;
    int indiceLetra = 0;

    //abrindo o arquivo_frase em modo "somente leitura"
    arquivo = fopen(nomeArq, "r");
    
    //enquanto não for fim de arquivo o looping será executado
    //e será impresso o texto
    //Faça 
    while ((c = fgetc(arquivo)) != EOF)
        {  
            // Se encontrar uma vírgula, termina a palavra atual e passa para a próxima
            if (c == ',')
            {
                palavritas[indicePalavras][indiceLetra] = '\0'; // Termina a string
                indicePalavras++;
                indiceLetra = 0;
            }
            else if (c != '\n') // Ignora quebras de linha, se houver
            {
                palavritas[indicePalavras][indiceLetra] = c;
                indiceLetra++;
            }
        }
        // Finaliza a última palavra
        palavritas[indicePalavras][indiceLetra] = '\0';

    // Fecha o arquivo
    fclose(arquivo);
    return indicePalavras;
}

char *SortearPalavra(int indicePalavras, char palavritas[50][10]){

    srand(time(NULL));
    int num_sorteado = rand()%(indicePalavras-1);
    char palavra_sorteada[10];
    int tamanho_palavra = sizeof(palavritas[0]);

    for(int i = 0; i < tamanho_palavra; i++){
    palavra_sorteada[i] = palavritas[num_sorteado][i];
    }


    return palavra_sorteada;
}

#endif 