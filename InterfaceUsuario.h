#include <stdio.h>
#include <string.h>

#ifndef InterfaceUsuario_h
#define InterfaceUsuario_h

// struct que guarda as informações de quem está jogando
typedef struct Usuario
{
    char nome[20];
    int jogos;
    int record;
    int score;

}Usuario;

Usuario new_user;

// Pede nome do usuário
void PedirNome(){
    printf("Digite seu nome: ");
    scanf("%s", new_user.nome);
    // Deixa em letra minuscúla
    for(int i = 0; new_user.nome[i]; i++){
        new_user.nome[i] = tolower(new_user.nome[i]);
    }
}

// Pergunta de o usuário que dueto ou termo
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

    // retorna a opção do usuário
    return num_dificuldade;
}

// Imprime no final as informações do jogador
void VerUser(Usuario user){
    printf("\n\nProgresso\n");
    printf("Nome    -   %s\n", user.nome);
    printf("Jogos   -   %d\n", user.jogos);
    printf("Record  -   %d\n", user.record);
    printf("Score   -   %d\n\n", user.score);   
}

#endif 