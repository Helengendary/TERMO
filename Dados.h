#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "InterfaceUsuario.h"

#ifndef DADOS_H
#define DADOS_H

void mandarTxt(const char *nome, int ganhou){

    FILE *file = fopen("jogadores.txt", "r+");
    FILE *tempFile = fopen("temp.txt", "w");
    int encontrado = 0;

    if (file == NULL) {
        file = fopen("jogadores.txt", "w+");
    }

    char usernome[20];
    int userjogos, userrecord, userscore;

    // Ler cada linha do arquivo original e verificar se o jogador já existe
    while (fscanf(file, "%19s %d %d %d", usernome, &userjogos, &userrecord, &userscore) != EOF) {
        if (strcmp(usernome, nome) == 0) {
            encontrado = 1;
            userjogos++;
            if (ganhou) {
                userscore++;
                if (userscore > userrecord) {
                    userrecord = userscore;
                }
            } else {
                userscore = 0;
            }

            new_user.jogos = userjogos;
            new_user.record = userrecord;
            new_user.score = userscore;
        }
        fprintf(tempFile, "%s %d %d %d\n", usernome, userjogos, userrecord, userscore);
    }

    if (!encontrado) {
        new_user.jogos = 1;
        if (ganhou) {
            new_user.score = 1;
            new_user.record = 1;
        } else {
            new_user.score = 0;
            new_user.record = 0;
        }
        fprintf(tempFile, "%s %d %d %d\n", new_user.nome, new_user.jogos, new_user.record, new_user.score);
    }

    VerUser(new_user);

    fclose(file);
    fclose(tempFile);

    // Substituir o arquivo original pelo arquivo temporário
    remove("jogadores.txt");
    rename("temp.txt", "jogadores.txt");

}

#endif