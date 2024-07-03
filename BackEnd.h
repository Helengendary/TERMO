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

    system("cls");
    return resposta;
}

int encontrarIndice(char *letrasVerificadas, int tamanho, char letra) {
    for (int i = 0; i < tamanho; i++) {
        if (letrasVerificadas[i] == letra) {
            return i; // Retorna o índice da letra encontrada
        }
    }
    return -1; // Retorna -1 se a letra não for encontrada
}

char *CompararPalavras(char *palavra_sorteada, char *resposta, int qtd_letras){
    char *resultado = (char *)malloc((qtd_letras + 1) * sizeof(char));
    int *letrasRepetidas = (int *)malloc((qtd_letras + 1) * sizeof(int));
    char *letrasVerificadas = (char *)malloc((qtd_letras + 1) * sizeof(char));
    char *letrasVerificadasResposta = (char *)malloc((qtd_letras + 1) * sizeof(char));
    int *letrasRepetidasResposta = (int *)malloc((qtd_letras + 1) * sizeof(int));
    int indice = 0;
    int indiceResposta = 0;

    for (int i = 0; i < qtd_letras; i++)
    {
        int quantidadeLetras = 0;

        if (strchr(letrasVerificadas, palavra_sorteada[i]))
        {
            printf("Ja esta ali\n");
        }else{
            for (int j = 0 ; j < qtd_letras; j++)
            {
                if (palavra_sorteada[i] == palavra_sorteada[j]){
                    quantidadeLetras++;
                    letrasVerificadas[indice] = palavra_sorteada[i];
                    printf("J: %c\n", palavra_sorteada[j]);
                    indice++;
                }
            }
            letrasRepetidas[i] = quantidadeLetras;
        }
    }

    for(int j = 0; j < qtd_letras ; j++){       
        printf("%d ", letrasRepetidas[j]);
    }
    printf("\n\n");
    
    for (int i = 0; i < qtd_letras; i++)
    {
        int quantidadeLetras = 0;

        if (strchr(letrasVerificadasResposta, resposta[i]))
        {
            printf("Ja esta ali\n");
        }else{
            for (int j = 0 ; j < qtd_letras; j++)
            {
                if (resposta[i] == resposta[j]){
                    quantidadeLetras++;
                    letrasVerificadasResposta[indiceResposta] = resposta[i];
                    printf("J: %c\n", resposta[j]);
                    indiceResposta++;
                }
            }
        }
        letrasRepetidasResposta[i] = quantidadeLetras;
    }

    for(int j = 0; j < qtd_letras ; j++){       
        printf("%d ", letrasRepetidasResposta[j]);
    }
    printf("\n\n");

    char lugar_certo = '1';
    char nao_tem = '0';
    char lugar_errado = '2';

    for (int i = 0; i < qtd_letras; i++)
    {
        resultado[i] = lugar_errado;
        
        if (palavra_sorteada[i] == resposta[i]) {
            resultado[i] = lugar_certo;

        }

        if (strchr(palavra_sorteada, resposta[i]) == NULL) {
            resultado[i] = nao_tem;
        }


    }

    for (int i = 0; i < qtd_letras; i++) {     
        printf("!\n");   
        int indicees = 0, indiceees = 0;        
        if (resultado[i] == lugar_certo) {
            printf("%c", palavra_sorteada[i]);
            indicees = encontrarIndice(letrasVerificadas, qtd_letras, palavra_sorteada[i]);
            indiceees = encontrarIndice(letrasVerificadasResposta, qtd_letras, palavra_sorteada[i]);
        }

        if (letrasRepetidas[indicees] <= letrasRepetidasResposta[indiceees]){
            for (int g = 0; g < qtd_letras; g++) {
                printf("%c", resposta[g]);
                if (resposta[g] == palavra_sorteada[i]) {
                    if (resultado[g] == lugar_errado) {
                        resultado[g] = nao_tem;
                    }
                }
            }
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