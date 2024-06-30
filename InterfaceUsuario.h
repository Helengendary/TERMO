#include <stdio.h>
#include <string.h>

#ifndef InterfaceUsuario_h
#define InterfaceUsuario_h

typedef struct Usuario
{
    char nome[20];
    int jogos;
    int record;
    int score;

}Usuario;

Usuario new_user;

void PedirNome(){
    printf("Digite seu nome: ");
    scanf("%s", new_user.nome);
}

int GuardarDificuldade() {
    int num_dificuldade = 0;
    char buffer[100];

    while (1) {
        printf("Escolha o nivel que deseja jogar\n1- Termo\n2- Dueto\n > ");
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            // Tente converter a entrada para um inteiro
            if (sscanf(buffer, "%d", &num_dificuldade) == 1) {
                if (num_dificuldade == 1 || num_dificuldade == 2) {
                    break;
                } else {
                    printf("Entrada invalida. Por favor, escolha 1 ou 2.\n");
                }
            } else {
                printf("Entrada invalida. Por favor, escolha 1 ou 2.\n");
            }
        } else {
            printf("Erro ao ler a entrada. Tente novamente.\n");
        }
    }

    return num_dificuldade;
}

void VerUser(){
    printf("\n\nProgresso\n");
    printf("Nome    -   %s\n", new_user.nome);
    printf("Jogos   -   %d\n", new_user.jogos);
    printf("Record  -   %d\n", new_user.record);
    printf("Score   -   %d\n", new_user.score);
}

#endif 