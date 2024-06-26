#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Desing.h"

#ifndef BACKEND_H
#define BACKEND_H
#define BACK_VERDE "\x1b[42m"
#define BACK_AMARELO "\x1b[40m"
#define BACK_PRETO "\x1b[43m"
#define RESET "\x1b[0m"

int tentativas = 0;

const char* getColor(char color) {
    
    switch (color) {
        case 'g': return BACK_VERDE;
        case 'y': return BACK_AMARELO;
        case 'b': return BACK_PRETO;
        default: return RESET;
    }
}

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

// Função que sorteia uma palavra e a retorna como string
char* SortearPalavra(int indicePalavras, char palavritas[50][10]) {
    srand(time(NULL));
    int num_sorteado = rand() % indicePalavras;
    char* palavra_sorteada = (char*)malloc(10 * sizeof(char));

    strcpy(palavra_sorteada, palavritas[num_sorteado]);

    return palavra_sorteada;
}

char* InputResposta(int qtd_letras){
    char* resposta = (char*)malloc(qtd_letras * sizeof(char)); 

    printf("\n : ");
    scanf("%s", resposta);

    return resposta;
}

char *CompararPalavras(char *palavra_sorteada, char *resposta, int qtd_letras){
    char *resultado = (char *)malloc((qtd_letras + 1) * sizeof(char));
    char lugar_certo = '1';
    char nao_tem = '0';
    char lugar_errado = '2';

    for(int i = 0; i < qtd_letras; i++){
        if(palavra_sorteada[i] == resposta[i]){
            resultado[i] = lugar_certo;
        }
        else if(strchr(palavra_sorteada, resposta[i])){
            resultado[i] = lugar_errado;
        }
        else{
            resultado[i] = nao_tem;
        }
    }

    resultado[qtd_letras] = '\0';

    return resultado; 
}

void ColocarMatriz(int qtd_letras, char* palavra_sorteada, const char* matriz_cores[6][qtd_letras], char matriz_letras[6][qtd_letras]){
    char* resposta = InputResposta(qtd_letras);
    char* result = CompararPalavras(palavra_sorteada, resposta, qtd_letras);
    
    for (int j = 0; j < qtd_letras; j++) {
        if(result[j] == '1'){
            matriz_cores[tentativas][j] = getColor('g');
        } else if(result[j] == '2'){
            matriz_cores[tentativas][j] = getColor('y');
        } else {
            matriz_cores[tentativas][j] = getColor('b');
        }
        matriz_letras[tentativas][j] = resposta[j];
    }

    tentativas++; // Incrementa tentativas depois de processar a resposta

    free(resposta);
    free(result);
}

void MostrarMatriz(int qtd_letras, const char* matriz_cores[6][qtd_letras], char matriz_letras[6][qtd_letras]){
    for(int i = 0; i < tentativas; i++) {
        for (int j = 0; j < qtd_letras; j++) {
            printf("%s%c%s ", matriz_cores[i][j], matriz_letras[i][j], RESET);
        }
        printf("\n");
    }
}


void jogada(char *arquivo, char palavritas[50][10], int qtd_letras){
    int vitoria = 0;

    char* palavra_sorteada = SortearPalavra(LerArquivo(arquivo, palavritas), palavritas);
    printf("Palavra sorteada: %s", palavra_sorteada);
    char *matriz_letras[tentativas][qtd_letras];
    char *matriz_cores[tentativas][qtd_letras];

    subtituloTermo();

    while (tentativas < 5 || vitoria != 1)
    {

        ColocarMatriz(qtd_letras, palavra_sorteada, matriz_cores, matriz_letras);
        MostrarMatriz(qtd_letras, matriz_cores, matriz_letras);

    }
    
}

#endif 