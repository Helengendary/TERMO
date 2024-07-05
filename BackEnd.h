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

// Variáveis globais para controlar o estado do jogo
int vitoria = 0; // Saber se o usuário acertou
int tentativas = 0; // Quantidade de tentativas
int vit1 = 0; // Vitória do primeiro jogador
int vit2 = 0; // Vitória do segundo jogador

// Função para ler arquivo com as palavras para serem sorteadas
int LerArquivo(char nomeArq[50], char palavritas[1000][6]) {
    FILE *arquivo;
    char c;
    int indicePalavras = 0;
    int indiceLetra = 0;

    // Abrindo o arquivo em modo "somente leitura"
    arquivo = fopen(nomeArq, "r");
    
    // Loop para ler o arquivo até o fim
    while ((c = fgetc(arquivo)) != EOF) {  
        // Se encontrar uma vírgula, termina a palavra atual e passa para a próxima
        if (c == ',') {
            palavritas[indicePalavras][indiceLetra] = '\0'; // Termina a string
            indicePalavras++;
            indiceLetra = 0;
        } else if (c != '\n') { // Ignora quebras de linha, se houver
            palavritas[indicePalavras][indiceLetra] = c;
            indiceLetra++;
        }
    }
    // Finaliza a última palavra
    palavritas[indicePalavras][indiceLetra] = '\0';

    // Fecha o arquivo
    fclose(arquivo);
    // Retorna quantas palavras tem no arquivo
    return indicePalavras;
}

// Função que sorteia uma palavra e a retorna como string
char* SortearPalavra(int indicePalavras, char palavritas[1000][6]) {
    int num_sorteado = rand() % indicePalavras;
    char* palavra_sorteada = (char*)malloc(10 * sizeof(char));

    strcpy(palavra_sorteada, palavritas[num_sorteado]);

    return palavra_sorteada;
}

// Verifica se a palavra digitada pelo usuário tem 5 letras ou se tem número
int palavraValida(const char* word) {
    // Verificação pela quantidade
    if (strlen(word) != 5) {
        return 0;
    }
    // Verificação pelo número
    for (int i = 0; i < 5; i++) {
        if (!isalpha(word[i])) {
            return 0;
        }
    }
    return 1;
}

// Verifica se a palavra que o usuário digitou está dentro do arquivo palavrasPossiveis
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

// Pede para o usuário digitar seu chute
char* InputResposta(int qtd_letras) {
    char* resposta = (char*)malloc((qtd_letras + 1) * sizeof(char)); // +1 para o caractere nulo

    // Verificação de alocar memória
    if (resposta == NULL) {
        printf("Erro ao alocar memoria\n");
        exit(1);
    }

    // Para pedir ao usuário digitar até que a palavra seja válida
    while (1) {
        printf("\nDigite uma palavra de %d letras: ", qtd_letras);
        scanf("%s", resposta);

        // deixa resposta em letra minuscúla
        for(int i = 0; resposta[i]; i++){
            resposta[i] = tolower(resposta[i]);
        }

        // Verificações de quantidade, número e existência
        if (!palavraValida(resposta)) {
            printf("Entrada invalida. Certifique-se de que a palavra tem %d letras e contem apenas letras.\n", qtd_letras);
        } else if (!palavraExiste(resposta)) {
            printf("Palavra nao encontrada na lista de palavras possiveis.\n");
        } else {
            break;
        }
    }

    system("cls");
    // Retorna o que o usuário digitou
    return resposta;
}

// Verifica posições das letras
char *CompararPalavras(char *palavra_sorteada, char *resposta, int qtd_letras) {
    // Copia a palavra certa
    char *resultado = (char *)malloc((qtd_letras + 1) * sizeof(char));
    strcpy(resultado, palavra_sorteada);

    // Valores para as posições das letras
    char lugar_certo = '1';
    char nao_tem = '0';
    char lugar_errado = '2';

    char *copy = malloc(sizeof(qtd_letras + 1));
    strcpy(copy, palavra_sorteada);

    // Preenche tudo como errado
    for (int i = 0; i < qtd_letras; i++) {
        resultado[i] = nao_tem;
    }

    // Se a posição estiver certa a posição da letra vai ser certa e a letra que estiver certa em copy vale '0'
    for (int i = 0; i < qtd_letras; i++) {
        if (copy[i] == resposta[i]) {
            copy[i] = '0';
            resultado[i] = lugar_certo;
        }
    }
    
    // Verificar se a letra está na palavra, mas, não no lugar certo
    for (int i = 0; i < qtd_letras; i++) {
        for (int j = 0; j < qtd_letras; j++) {
            // Se a letra já foi verificada pula ela
            if (copy[i] == '0') {
                continue;
            }

            if (copy[i] == resposta[j]) {
                if (copy[j] != '0') {
                    copy[i] = '1';
                    resultado[j] = lugar_errado;
                }
            } 
        } 
    }

    resultado[qtd_letras] = '\0';

    return resultado; 
    
    free(copy);
    free(resultado);
}

int cont2 = 0;

// Preencher matriz de cores de acordo com a posição das letras
char **PreencherMatrizCores2(char **matriz_cores, int qtd_letras, char *result, int vit2) {
    // Se ainda não tem vitória
    if (vit2 == 0) {
        for (int i = cont2; i == tentativas; i++) {
            for (int j = 0; j < qtd_letras; j++) {
                if (result[j] == '1') {
                    matriz_cores[i][j] = 'g';
                } else if (result[j] == '2') {
                    matriz_cores[i][j] = 'y';
                } else if (result[j] == '0') {
                    matriz_cores[i][j] = 'w';
                }
            }
            cont2++;
        }
    } else {
        // Para o caso de a palavra já ter sido resolvida
        for (int i = cont2; i == tentativas; i++) {
            for (int j = 0; j < qtd_letras; j++) {
                matriz_cores[i][j] = 'x';
            }
            cont2++;
        }
    }

    return matriz_cores;
}

// Preencher uma matriz com as letras que o usuário digitou
char **PreencherMatrizLetras2(char **matriz_letras, int qtd_letras, char *resposta, int vit2) {
    if (vit2 == 0) {
        for (int i = cont2; i == tentativas; i++) {
            for (int j = 0; j < qtd_letras; j++) {
                // Atribui resposta para a matriz
                matriz_letras[i][j] = resposta[j];
            }
        }
    } else {
        // Se o usuário ganhou
        for (int i = cont2; i == tentativas; i++) {
            for (int j = 0; j < qtd_letras; j++) {
                matriz_letras[i][j] = ' ';
            }
        }
    }

    // Retorna a matriz
    return matriz_letras;
}

int cont = 0; // para saber daonde começar a matriz

// Preenche a matriz de cores de acordo com o resultado da comparação das palavras
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

// Preenche a matriz de letras com as letras que o usuário digitou
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

// Preenche as cores do alfabeto de acordo com o resultado da comparação das palavras
char *PreencherCoresAlfabeto(char *cores_alfabeto,char *alfabeto, char *result, char *resposta, int qtd_letras){
    char caractere;

    for(int i = 0; i < qtd_letras; i++){

        caractere = resposta[i];

        for(int j = 0; j <= 26; j++){
            if(result[i] == '1'){
                if((caractere == alfabeto[j]) && ((cores_alfabeto[j] == 'x') || (cores_alfabeto[j] == 'y'))){
                    cores_alfabeto[j] = 'g';
                }
            }else if(result[i] == '2'){
                if((caractere == alfabeto[j]) && ((cores_alfabeto[j] == 'x') || (cores_alfabeto[j] == 'w'))){
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

// Preenche as cores do alfabeto de acordo com os resultados da comparação das palavras para o modo Dueto
char *PreencherCoresAlfabetoDueto(char *cores_alfabeto,char *alfabeto, char *result1, char *resposta, char *result2, int qtd_letras){
    char caractere;

    for(int i = 0; i < qtd_letras; i++){

        caractere = resposta[i];

        for(int j = 0; j <= 26; j++){
            if((result1[i] == '1') || (result2[i] == '1')){
                if((caractere == alfabeto[j]) && ((cores_alfabeto[j] == 'x') || (cores_alfabeto[j] == 'y'))){
                    cores_alfabeto[j] = 'g';
                }
            }else if((result1[i] == '2') || (result2[i] == '2')){
                if((caractere == alfabeto[j]) && ((cores_alfabeto[j] == 'x') || (cores_alfabeto[j] == 'w'))){
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

// Função para realizar uma jogada no modo Termo
int ColocarMatrizTermo(int qtd_letras, char* palavra_sorteada, char **matriz_letras, char **matriz_cores, char *alfabeto, char *cores_alfabeto) {
    char* resposta = InputResposta(qtd_letras); // Obtém a resposta do usuário
    char* result = CompararPalavras(palavra_sorteada, resposta, qtd_letras); // Compara a resposta com a palavra sorteada

    int contador = 0;
    // Conta quantas letras estão na posição correta
    for (int i = 0; i < qtd_letras; i++) {
        if (result[i] == '1') {
            contador++;
        }
    }

    // Preenche as matrizes de letras e cores com a resposta e o resultado
    matriz_letras = PreencherMatrizLetras(matriz_letras, qtd_letras, resposta, vit1);
    matriz_cores = PreencherMatrizCores(matriz_cores, qtd_letras, result, vit1);

    // Atualiza as cores do alfabeto
    cores_alfabeto = PreencherCoresAlfabeto(cores_alfabeto, alfabeto, result, resposta, qtd_letras);

    // Imprime a matriz e o teclado
    subtituloTermo();
    ImprimirMatrizTermo(matriz_letras, qtd_letras, tentativas, matriz_cores);
    Teclado(alfabeto, cores_alfabeto);

    // Verifica se todas as letras estão na posição correta
    if (contador == qtd_letras) {
        return 1;
    }

    tentativas++; // Incrementa o número de tentativas

    return 0;
}

// Função para realizar uma jogada no modo Dueto
int ColocarMatrizDueto(int qtd_letras, char* palavra_sorteada1, char **matriz_letras1, char **matriz_cores1, char* palavra_sorteada2, char **matriz_letras2, char **matriz_cores2, char *alfabeto, char *cores_alfabeto) {
    char* resposta = InputResposta(qtd_letras); // Obtém a resposta do usuário
    char* result1 = CompararPalavras(palavra_sorteada1, resposta, qtd_letras); // Compara a resposta com a primeira palavra sorteada
    char* result2 = CompararPalavras(palavra_sorteada2, resposta, qtd_letras); // Compara a resposta com a segunda palavra sorteada

    int contador1 = 0;
    int contador2 = 0;

    // Conta quantas letras estão na posição correta para ambas as palavras
    for (int i = 0; i < qtd_letras; i++) {
        if (result1[i] == '1') {
            contador1++;
        }
        if (result2[i] == '1') {
            contador2++;
        }
    }

    // Preenche as matrizes de letras e cores para ambas as palavras
    matriz_letras1 = PreencherMatrizLetras(matriz_letras1, qtd_letras, resposta, vit1);
    matriz_cores1 = PreencherMatrizCores(matriz_cores1, qtd_letras, result1, vit1);

    matriz_letras2 = PreencherMatrizLetras2(matriz_letras2, qtd_letras, resposta, vit2);
    matriz_cores2 = PreencherMatrizCores2(matriz_cores2, qtd_letras, result2, vit2);

    // Atualiza as cores do alfabeto considerando ambos os resultados
    cores_alfabeto = PreencherCoresAlfabetoDueto(cores_alfabeto, alfabeto, result1, resposta, result2, qtd_letras);

    // Imprime a matriz e o teclado
    subtituloDueto();
    ImprimirMatrizDueto(matriz_letras1, matriz_letras2, qtd_letras, tentativas, matriz_cores1, matriz_cores2);
    Teclado(alfabeto, cores_alfabeto);

    tentativas++; // Incrementa o número de tentativas

    // Verifica se todas as letras estão na posição correta para ambas as palavras
    if (contador1 == qtd_letras) {
        vit1 = 1;
        return 1;
    } else if (contador2 == qtd_letras) {
        vit2 = 1;
        return 1;
    } else {
        return 0;
    }
}

// Função para iniciar e controlar o modo Termo
int jogadaTermo(char *arquivo, char palavritas[1000][6], int qtd_letras) {
    srand(time(NULL)); // Inicializa o gerador de números aleatórios

    char* palavra_sorteada = SortearPalavra(LerArquivo(arquivo, palavritas), palavritas); // Sorteia uma palavra
    // printf("\nPalavra: %s\n", palavra_sorteada);

    // Aloca memória para as matrizes de cores e letras
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

    subtituloTermo(); // Exibe o subtítulo para o modo Termo

    // Loop de tentativas até o limite ou até vencer
    while (tentativas < 5 && vitoria != 1) {
        vitoria = ColocarMatrizTermo(qtd_letras, palavra_sorteada, matriz_letras, matriz_cores, alfabeto, cores_alfabeto);
    }

    // Verifica se o jogador venceu
    if (vitoria >= 1) {
        return 1;
    } else {
        printf("\nPalavra: %s", palavra_sorteada); // Exibe a palavra correta
        return 0;
    }

    // Libera a memória alocada para as matrizes
    free(matriz_cores);
    free(matriz_letras);
}

// Função para iniciar e controlar o modo Dueto
int jogadaDueto(char *arquivo, char palavritas[1000][6], int qtd_letras) {
    int soma = 0;
    srand(time(NULL)); // Inicializa o gerador de números aleatórios

    char* palavra_sorteada1 = SortearPalavra(LerArquivo(arquivo, palavritas), palavritas); // Sorteia a primeira palavra
    char* palavra_sorteada2 = SortearPalavra(LerArquivo(arquivo, palavritas), palavritas); // Sorteia a segunda palavra
    // printf("\nPalavras: %s, %s\n", palavra_sorteada1, palavra_sorteada2);

    // Aloca memória para as matrizes de cores e letras da primeira palavra
    char **matriz_cores1 = (char **)malloc(7 * sizeof(char *));
    for (int i = 0; i < 7; i++) {
        matriz_cores1[i] = (char *)malloc(qtd_letras * sizeof(char));
    }

    char **matriz_letras1 = (char **)malloc(7 * sizeof(char *));
    for (int i = 0; i < 7; i++) {
        matriz_letras1[i] = (char *)malloc(qtd_letras * sizeof(char));
    }

    // Aloca memória para as matrizes de cores e letras da segunda palavra
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

    subtituloDueto(); // Exibe o subtítulo para o modo Dueto

    // Loop de tentativas até o limite ou até vencer
    while (tentativas < 7 && vitoria != 2) {
        soma = ColocarMatrizDueto(qtd_letras, palavra_sorteada1, matriz_letras1, matriz_cores1, palavra_sorteada2, matriz_letras2, matriz_cores2, alfabeto, cores_alfabeto);
        vitoria += soma;
    }

    // Verifica se o jogador venceu
    if (vitoria >= 2) {
        return 1;
    } else {
        printf("\nPalavras: %s, %s\n", palavra_sorteada1, palavra_sorteada2); // Exibe as palavras corretas
        return 0;
    }

    // Libera a memória alocada para as matrizes
    free(matriz_cores1);
    free(matriz_letras1);
    free(matriz_cores2);
    free(matriz_letras2);
}

// Função principal para controlar a jogada de acordo com o modo escolhido
void jogada(int choice, char *arquivo, char palavritas[1000][6], int qtd_letras) {
    int v = 0;

    if (choice == 1) {
        v = jogadaTermo(arquivo, palavritas, qtd_letras); // Modo Termo
    } else {
        v = jogadaDueto(arquivo, palavritas, qtd_letras); // Modo Dueto
    }

    mandarTxt(new_user.nome, v); // Registra o resultado da jogada
}
#endif