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

int GuardarDificuldade(){
    int num_dificuldade = 0;

    printf("Escolha o nivel que deseja jogar\n1- Termo\n2- Dueto\n > ");
    scanf("%d", &num_dificuldade);

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