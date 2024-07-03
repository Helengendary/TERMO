#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para encontrar o índice de uma letra em um array de caracteres
int encontrarIndice(char *array, int tamanho, char letra) {
    for (int i = 0; i < tamanho; i++) {
        if (array[i] == letra) {
            return i;
        }
    }
    return -1; // Retorna -1 se a letra não for encontrada
}

char *CompararPalavras(char *palavra_sorteada, char *resposta, int qtd_letras) {
    char *resultado = (char *)malloc((qtd_letras + 1) * sizeof(char));
    int *letrasRepetidas = (int *)malloc((qtd_letras + 1) * sizeof(int));
    char *letrasVerificadas = (char *)malloc((qtd_letras + 1) * sizeof(char));
    char *letrasVerificadasResposta = (char *)malloc((qtd_letras + 1) * sizeof(char));
    int *letrasRepetidasResposta = (int *)malloc((qtd_letras + 1) * sizeof(int));
    int indice = 0;
    int indiceResposta = 0;

    // Inicializa letrasRepetidas e letrasRepetidasResposta com zeros
    memset(letrasRepetidas, 0, (qtd_letras + 1) * sizeof(int));
    memset(letrasRepetidasResposta, 0, (qtd_letras + 1) * sizeof(int));

    // Verifica letras corretas e quantidade de ocorrências em palavra_sorteada
    for (int i = 0; i < qtd_letras; i++) {
        int quantidadeLetras = 0;

        if (!strchr(letrasVerificadas, palavra_sorteada[i])) {
            letrasVerificadas[indice] = palavra_sorteada[i];
            for (int j = 0; j < qtd_letras; j++) {
                if (palavra_sorteada[i] == palavra_sorteada[j]) {
                    quantidadeLetras++;
                }
            }
            letrasRepetidas[indice] = quantidadeLetras;
            indice++;
        }
    }

    // Verifica letras corretas e quantidade de ocorrências em resposta
    for (int i = 0; i < qtd_letras; i++) {
        int quantidadeLetras = 0;

        if (!strchr(letrasVerificadasResposta, resposta[i])) {
            letrasVerificadasResposta[indiceResposta] = resposta[i];
            for (int j = 0; j < qtd_letras; j++) {
                if (resposta[i] == resposta[j]) {
                    quantidadeLetras++;
                }
            }
            letrasRepetidasResposta[indiceResposta] = quantidadeLetras;
            indiceResposta++;
        }
    }

    // Constantes para indicar o resultado
    char lugar_certo = '1';
    char lugar_errado = '2';
    char nao_tem = '0';

    // Verifica lugar certo, lugar errado e não tem
    for (int i = 0; i < qtd_letras; i++) {
        resultado[i] = lugar_errado; // Inicialmente assume que está no lugar errado
        
        if (palavra_sorteada[i] == resposta[i]) {
            resultado[i] = lugar_certo; // Se estiver no lugar certo
        } else {
            // Se a letra da resposta existe em palavra_sorteada
            if (strchr(palavra_sorteada, resposta[i])) {
                int indice_palavra_sorteada = encontrarIndice(letrasVerificadas, qtd_letras, resposta[i]);
                int indice_resposta = encontrarIndice(letrasVerificadasResposta, qtd_letras, resposta[i]);

                // Se a letra da resposta está mais vezes em palavra_sorteada do que na resposta na posição correta
                if (letrasRepetidas[indice_palavra_sorteada] > letrasRepetidasResposta[indice_resposta]) {
                    int qtd_corretos = 0;
                    for (int k = 0; k < qtd_letras; k++) {
                        if (palavra_sorteada[k] == resposta[k] && resultado[k] == lugar_certo) {
                            qtd_corretos++;
                        }
                    }

                    // Se ainda há espaço para atribuir lugar_errado
                    if (qtd_corretos < letrasRepetidasResposta[indice_resposta]) {
                        resultado[i] = lugar_errado; // Marca como lugar_errado
                    } else {
                        resultado[i] = nao_tem; // Marca como não tem
                    }
                } else {
                    resultado[i] = nao_tem; // Marca como não tem
                }
            } else {
                resultado[i] = nao_tem; // Marca como não tem
            }
        }
    }

    resultado[qtd_letras] = '\0'; // Adiciona terminador nulo

    // Libera a memória alocada
    free(letrasRepetidas);
    free(letrasVerificadas);
    free(letrasVerificadasResposta);
    free(letrasRepetidasResposta);

    return resultado; // Retorna o resultado
}

int main() {
    char palavra_sorteada[] = "banana";
    char resposta[] = "bnnnaa";
    int qtd_letras = strlen(palavra_sorteada);

    char *resultado = CompararPalavras(palavra_sorteada, resposta, qtd_letras);

    printf("Resultado: %s\n", resultado);

    free(resultado); // Libera a memória alocada para o resultado

    return 0;
}
