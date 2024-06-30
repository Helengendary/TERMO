#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PALAVRA 100 // Tamanho máximo de uma palavra

int is_valid_word(const char* word) {
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

int word_exists(const char* word, const char* filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return 0;
    }

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

char* InputResposta(int qtd_letras, const char* filename) {
    char* resposta = (char*)malloc((qtd_letras + 1) * sizeof(char)); // +1 para o caractere nulo

    if (resposta == NULL) {
        printf("Erro ao alocar memória\n");
        exit(1);
    }

    while (1) {
        printf("\nDigite uma palavra de %d letras: ", qtd_letras);
        scanf("%s", resposta);

        if (!is_valid_word(resposta)) {
            printf("Entrada inválida. Certifique-se de que a palavra tem %d letras e contém apenas letras.\n", qtd_letras);
        } else if (!word_exists(resposta, filename)) {
            printf("Palavra não encontrada na lista de palavras possíveis.\n");
        } else {
            break;
        }
    }

    return resposta;
}

int main() {
    const char* filename = "palavrasPossiveis.txt";
    char* resposta = InputResposta(5, filename);
    printf("Você digitou a palavra válida: %s\n", resposta);
    free(resposta);
    return 0;
}
