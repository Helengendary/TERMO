#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 100

int main() {
    FILE *file;
    char line[MAX_WORD_LENGTH];
    char *words[MAX_WORDS];
    int count = 0;

    // Abre o arquivo em modo leitura
    file = fopen("palavras.txt", "r");                                                                                                                         
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return EXIT_FAILURE;
    }

    // Lê cada linha do arquivo e armazena no array de palavras
    while (fgets(line, sizeof(line), file)) {
        // Remove o caractere de nova linha, se houver
        line[strcspn(line, "\n")] = '\0';
        
        // Aloca memória para a palavra e copia a linha para o array de palavras
        words[count] = malloc(strlen(line) + 1);
        if (words[count] == NULL) {
            perror("Erro ao alocar memória");
            return EXIT_FAILURE;
        }
        strcpy(words[count], line);
        count++;
    }

    // Fecha o arquivo
    fclose(file);

    // Exibe as palavras armazenadas no array
    printf("Palavras lidas do arquivo:\n");
    for (int i = 0; i < count; i++) {
        printf("%s\n", words[i]);
        free(words[i]); // Libera a memória alocada para cada palavra
    }

    return EXIT_SUCCESS;
}
