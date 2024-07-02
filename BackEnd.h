#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Desing.h"
#include "Dados.h"
#include "InterfaceUsuario.h"
#include <conio.h>
#include <ctype.h>


#ifndef BACKEND_H
#define BACKEND_H
#define MAX_PALAVRA 100 // Tamanho máximo de uma palavra

int vitoria = 0;
int tentativas = 0;
int vit1 = 0;
int vit2 = 0;

int LerArquivo(char nomeArq[50], char palavritas[1000][6]) {
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
char* SortearPalavra(int indicePalavras, char palavritas[1000][6])
{
    int num_sorteado = rand() % indicePalavras;
    char* palavra_sorteada = (char*)malloc(10 * sizeof(char));

    strcpy(palavra_sorteada, palavritas[num_sorteado]);

    return palavra_sorteada;
}

int palavraValida(const char* word) {
    if (strlen(word) != 5) {
        return 0;
    }
    for (int i = 0; i < 5; i++) {
        if (!isalpha(word[i])) {
            return 0;
        }
    }
    return 1;
}

int palavraExiste(const char* word) {
    FILE *file = fopen("palavrasPossiveis.txt", "r");

    char buffer[MAX_PALAVRA];
    while (fscanf(file, "%[^,],", buffer) != EOF) {
        if (strcmp(word, buffer) == 0) {
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}

char* InputResposta(int qtd_letras) {
    char* resposta = (char*)malloc((qtd_letras + 1) * sizeof(char)); // +1 para o caractere nulo

    if (resposta == NULL) {
        printf("Erro ao alocar memória\n");
        exit(1);
    }

    while (1) {
        printf("\nDigite uma palavra de %d letras: ", qtd_letras);
        scanf("%s", resposta);

        if (!palavraValida(resposta)) {
            printf("Entrada inválida. Certifique-se de que a palavra tem %d letras e contém apenas letras.\n", qtd_letras);
        } else if (!palavraExiste(resposta)) {
            printf("Palavra não encontrada na lista de palavras possíveis.\n");
        } else {
            break;
        }
    }

    system("cls");
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


int cont2 = 0;

char **PreencherMatrizCores2(char **matriz_cores, int qtd_letras, char *result, int vit2){
    if(vit2 == 0){
        for(int i = cont2; i == tentativas ; i++){
            for(int j = 0; j < qtd_letras ; j++){
                if(result[j] == '1'){
                    matriz_cores[i][j] = 'g';
                } else if(result[j] == '2'){
                    matriz_cores[i][j] = 'y';
                } else if(result[j] == '0'){
                    matriz_cores[i][j] = 'w';
                }
            }
            cont2++;
        }
    }else{
        for(int i = cont2; i == tentativas ; i++){
            for(int j = 0; j < qtd_letras ; j++){
                matriz_cores[i][j] = 'x';
            }
            cont2++;
        }
    }

    return matriz_cores;
}


char **PreencherMatrizLetras2(char **matriz_letras, int qtd_letras, char *resposta, int vit2){
    if(vit2 == 0){
        for(int i = cont2; i == tentativas ; i++){
            for(int j = 0; j < qtd_letras ; j++){
                matriz_letras[i][j] = resposta[j];
            }
        }
    }else{
        for(int i = cont2; i == tentativas ; i++){
            for(int j = 0; j < qtd_letras ; j++){
                matriz_letras[i][j] = ' ';
            }
        }
    }

    return matriz_letras;
}


int cont = 0;

char **PreencherMatrizCores(char **matriz_cores, int qtd_letras, char *result, int vit1){
    
    if(vit1 == 0){
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
    }else{
        for(int i = cont; i == tentativas ; i++){
            for(int j = 0; j < qtd_letras ; j++){
                matriz_cores[i][j] = 'x';
            }
            cont++;
        }
    }

    return matriz_cores;
}

char **PreencherMatrizLetras(char **matriz_letras, int qtd_letras, char *resposta, int vit1){
    
    if(vit1 == 0){
        for(int i = cont; i == tentativas ; i++){
            for(int j = 0; j < qtd_letras ; j++){
                matriz_letras[i][j] = resposta[j];
            }
        }
    }else{
        for(int i = cont; i == tentativas ; i++){
            for(int j = 0; j < qtd_letras ; j++){
                matriz_letras[i][j] = ' ';
            }
        }
    }

    return matriz_letras;
}

char *PreencherCoresAlfabeto(char *cores_alfabeto,char *alfabeto, char *result, char *resposta, int qtd_letras){
    char caractere;

    for(int i = 0; i < qtd_letras; i++){

        caractere = resposta[i];

        for(int j = 0; j <= 26; j++){
            if(result[i] == '1'){
                if((caractere == alfabeto[j]) && (cores_alfabeto[j] == 'x')){
                    cores_alfabeto[j] = 'g';
                }
            }else if(result[i] == '2'){
                if((caractere == alfabeto[j]) && (cores_alfabeto[j] == 'x')){
                    cores_alfabeto[j] = 'y';
                }
            }else if(result[i] == '0'){
                if((caractere == alfabeto[j]) && (cores_alfabeto[j] == 'x')){
                    cores_alfabeto[j] = 'w';
                }
            }
        }
    }

    return cores_alfabeto;
}

char *PreencherCoresAlfabetoDueto(char *cores_alfabeto,char *alfabeto, char *result1, char *resposta, char *result2, int qtd_letras){
    char caractere;

    for(int i = 0; i < qtd_letras; i++){

        caractere = resposta[i];

        for(int j = 0; j <= 26; j++){
            if((result1[i] == '1') || (result2[i] == '1')){
                if((caractere == alfabeto[j]) && (cores_alfabeto[j] == 'x')){
                    cores_alfabeto[j] = 'g';
                }
            }else if((result1[i] == '2') || (result2[i] == '2')){
                if((caractere == alfabeto[j]) && (cores_alfabeto[j] == 'x')){
                    cores_alfabeto[j] = 'y';
                }
            }else if((result1[i] == '0') || (result2[i] == '0')){
                if((caractere == alfabeto[j]) && (cores_alfabeto[j] == 'x')){
                    cores_alfabeto[j] = 'w';
                }
            }
        }

        
    }

    return cores_alfabeto;
}


int ColocarMatrizTermo(int qtd_letras, char* palavra_sorteada, char **matriz_letras, char **matriz_cores, char *alfabeto, char *cores_alfabeto){
    char* resposta = InputResposta(qtd_letras);
    char* result = CompararPalavras(palavra_sorteada, resposta, qtd_letras);

    int contador = 0;
    for(int i = 0; i < qtd_letras; i++){
        if(result[i] == '1'){
            contador++;
        }
    }

    matriz_letras = PreencherMatrizLetras(matriz_letras, qtd_letras, resposta, vit1);
    matriz_cores = PreencherMatrizCores(matriz_cores, qtd_letras, result, vit1);

    cores_alfabeto = PreencherCoresAlfabeto(cores_alfabeto, alfabeto, result, resposta, qtd_letras);

    subtituloTermo();
    ImprimirMatrizTermo(matriz_letras, qtd_letras, tentativas, matriz_cores);
    Teclado(alfabeto, cores_alfabeto);

    if(contador == qtd_letras){
        return 1;
    }

    tentativas++;

    return 0;
}

int ColocarMatrizDueto(int qtd_letras, char* palavra_sorteada1, char **matriz_letras1, char **matriz_cores1, char* palavra_sorteada2, char **matriz_letras2, char **matriz_cores2, char *alfabeto, char *cores_alfabeto){
    
    char* resposta = InputResposta(qtd_letras);
    char* result1 = CompararPalavras(palavra_sorteada1, resposta, qtd_letras);
    char* result2 = CompararPalavras(palavra_sorteada2, resposta, qtd_letras);

    int contador1 = 0;
    int contador2 = 0;

    for(int i = 0; i < qtd_letras; i++){
        if(result1[i] == '1'){
            contador1++;
        }
        if(result2[i] == '1'){
            contador2++;
        }
    }

    matriz_letras1 = PreencherMatrizLetras(matriz_letras1, qtd_letras, resposta, vit1);
    matriz_cores1 = PreencherMatrizCores(matriz_cores1, qtd_letras, result1, vit1);

    matriz_letras2 = PreencherMatrizLetras2(matriz_letras2, qtd_letras, resposta, vit2);
    matriz_cores2 = PreencherMatrizCores2(matriz_cores2, qtd_letras, result2, vit2);

    cores_alfabeto = PreencherCoresAlfabetoDueto(cores_alfabeto, alfabeto, result1, resposta, result2, qtd_letras);

    subtituloDueto();
    ImprimirMatrizDueto(matriz_letras1, matriz_letras2, qtd_letras, tentativas, matriz_cores1, matriz_cores2);
    Teclado(alfabeto, cores_alfabeto);

    tentativas++;

    if(contador1 == qtd_letras){
        vit1 = 1;
        return 1;
    }else if(contador2 == qtd_letras){
        vit2 = 1;
        return 1;
    }else{
        return 0;
    }

}

int jogadaTermo(char *arquivo, char palavritas[1000][6], int qtd_letras){
    srand(time(NULL));

    char* palavra_sorteada = SortearPalavra(LerArquivo(arquivo, palavritas), palavritas);
    printf("\nPalavra: %s", palavra_sorteada);

    char **matriz_cores = (char **)malloc(5 * sizeof(char *));
    for (int i = 0; i < 5; i++) {
        matriz_cores[i] = (char *)malloc(qtd_letras * sizeof(char));
    }

    char **matriz_letras = (char **)malloc(5 * sizeof(char *));
    for (int i = 0; i < 5; i++) {
        matriz_letras[i] = (char *)malloc(qtd_letras * sizeof(char));
    }

    char alfabeto[] = {'q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l','z','x','c','v','b','n','m'};
    char cores_alfabeto[] = {'x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x'};

    subtituloTermo();

    while (tentativas < 5 && vitoria != 1)
    {
        vitoria = ColocarMatrizTermo(qtd_letras, palavra_sorteada, matriz_letras, matriz_cores, alfabeto, cores_alfabeto);
    }

    if(vitoria>=1){
        return 1;
    }else{
        printf("\nPalavra: %s", palavra_sorteada);
        return 0;
    }

    free(matriz_cores);
    free(matriz_letras);
}

int jogadaDueto(char *arquivo, char palavritas[1000][6], int qtd_letras){
    int soma = 0;
    srand(time(NULL));

    char* palavra_sorteada1 = SortearPalavra(LerArquivo(arquivo, palavritas), palavritas);
    char* palavra_sorteada2 = SortearPalavra(LerArquivo(arquivo, palavritas), palavritas);
    printf("\nPalavras: %s, %s\n", palavra_sorteada1,palavra_sorteada2);

    //   - MATRIZ 1
    char **matriz_cores1 = (char **)malloc(7 * sizeof(char *));
    for (int i = 0; i < 7; i++) {
        matriz_cores1[i] = (char *)malloc(qtd_letras * sizeof(char));
    }

    char **matriz_letras1 = (char **)malloc(7 * sizeof(char *));
    for (int i = 0; i < 7; i++) {
        matriz_letras1[i] = (char *)malloc(qtd_letras * sizeof(char));
    }

    //   - MATRIZ 2
    char **matriz_cores2 = (char **)malloc(7 * sizeof(char *));
    for (int i = 0; i < 7; i++) {
        matriz_cores2[i] = (char *)malloc(qtd_letras * sizeof(char));
    }

    char **matriz_letras2 = (char **)malloc(7 * sizeof(char *));
    for (int i = 0; i < 7; i++) {
        matriz_letras2[i] = (char *)malloc(qtd_letras * sizeof(char));
    }

    char alfabeto[] = {'q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l','z','x','c','v','b','n','m'};
    char cores_alfabeto[] = {'x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x'};

    subtituloDueto();

    while (tentativas < 7 && vitoria != 2)
    {
        soma = ColocarMatrizDueto(qtd_letras, palavra_sorteada1, matriz_letras1, matriz_cores1, palavra_sorteada2, matriz_letras2, matriz_cores2, alfabeto, cores_alfabeto);
        vitoria += soma;
    }

    if(vitoria>=2){
        return 1;
    }else{

        printf("\nPalavras: %s, %s\n", palavra_sorteada1,palavra_sorteada2);
        return 0;
    }
    
    free(matriz_cores1);
    free(matriz_letras1);
    free(matriz_cores2);
    free(matriz_letras2);
}

void jogada(int choice, char *arquivo, char palavritas[1000][6], int qtd_letras){
    int v = 0;

    if(choice == 1){
        v = jogadaTermo(arquivo, palavritas, qtd_letras);
    }else{
        v = jogadaDueto(arquivo, palavritas, qtd_letras);
    }

    mandarTxt(new_user.nome, v);
}
    

#endif