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

    printf("Escolha o nivel que deseja jogar\n1- Facil\n2- Medio\n3- Dificil\n > ");
    scanf("%d", &num_dificuldade);

    return num_dificuldade;
}

void VerUser(){
    printf("Nome: %s\n", new_user.nome);
}

#endif 