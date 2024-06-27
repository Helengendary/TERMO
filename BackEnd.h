#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Desing.h"
#include <conio.h>

#ifndef BACKEND_H
#define BACKEND_H

int vitoria = 0;
int tentativas = 0;

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

    system("clear");
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
        else if(strchr(palavra_sorteada, resposta[i])) {
            resultado[i] = lugar_errado;
        }
        else{
            resultado[i] = nao_tem;
        }
    }

    resultado[qtd_letras] = '\0';

    return resultado; 
}

int cont = 0;

char **PreencherMatrizCores(char **matriz_cores, int qtd_letras, char *result){
    
    for(int i = cont; i == tentativas ; i++){
        for(int j = 0; j < qtd_letras ; j++){
            if(result[j] == '1'){
                matriz_cores[i][j] = 'g';
            } else if(result[j] == '2'){
                matriz_cores[i][j] = 'y';
            } else if(result[j] == '0'){
                matriz_cores[i][j] = 'w';
            }
        }
        cont++;
    }

    return matriz_cores;
}
char **PreencherMatrizLetras(char **matriz_letras, int qtd_letras, char *resposta){
    
    for(int i = cont; i == tentativas ; i++){
        for(int j = 0; j < qtd_letras ; j++){

            matriz_letras[i][j] = resposta[j];          
            // printf("%c ", matriz_letras[i][j]);
        }
    }

    return matriz_letras;
}

int ColocarMatriz(int qtd_letras, char* palavra_sorteada, char **matriz_letras, char **matriz_cores){
    char* resposta = InputResposta(qtd_letras);
    char* result = CompararPalavras(palavra_sorteada, resposta, qtd_letras);

    int contador = 0;
    for(int i = 0; i < qtd_letras; i++){
        if(result[i] == '1'){
            contador++;
        }
    }

    matriz_letras = PreencherMatrizLetras(matriz_letras, qtd_letras, resposta);
    matriz_cores = PreencherMatrizCores(matriz_cores, qtd_letras, result);


    subtituloTermo();
    ImprimirMatriz(matriz_letras, qtd_letras, tentativas, matriz_cores);
    Teclado();

    if(contador == qtd_letras){
        return 1;
    }

    tentativas++;

    return 0;
}

void jogada(char *arquivo, char palavritas[50][10], int qtd_letras){

    char* palavra_sorteada = SortearPalavra(LerArquivo(arquivo, palavritas), palavritas);
    printf("Palavra sorteada: %s\n", palavra_sorteada);

    char **matriz_cores = (char **)malloc(5 * sizeof(char *));
    for (int i = 0; i < 5; i++) {
        matriz_cores[i] = (char *)malloc(qtd_letras * sizeof(char));
    }

    char **matriz_letras = (char **)malloc(5 * sizeof(char *));
    for (int i = 0; i < 5; i++) {
        matriz_letras[i] = (char *)malloc(qtd_letras * sizeof(char));
    }

    subtituloTermo();

    while (tentativas < 5 && vitoria != 1)
    {
        vitoria = ColocarMatriz(qtd_letras, palavra_sorteada, matriz_letras, matriz_cores);

    }

    free(matriz_cores);
    free(matriz_letras);
}
    

#endif 