#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "InterfaceUsuario.h"

#ifndef DADOS_H
#define DADOS_H

void mandarTxt(const char *nome, int ganhou){

    FILE *file = fopen("jogadores.txt", "r");
    FILE *tempFile = fopen("temp.txt", "w");
    int encontrado = 0;

    if (file == NULL) {
        file = fopen("jogadores.txt", "w");
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

void ordRecord() {
    FILE *file = fopen("jogadores.txt", "r");
    FILE *recordes = fopen("recordes.txt", "w");

    int indicer = 10;
    Usuario *informations = malloc(indicer*sizeof(Usuario));

    int aux = 0;

    while (fscanf(file, "%19s %d %d %d", informations[aux].nome, &informations[aux].jogos, &informations[aux].record, &informations[aux].score) != EOF ){

        aux++;
        if (aux == indicer) {
            indicer*=2;
            informations = realloc(informations,indicer*sizeof(Usuario));
        }
    }
    Usuario auxilio;

    int minor_index;
    for(int i =0;i<aux-1;i++)
    {
        minor_index = i;
        for(int j = i+1;j<aux;j++)
        {
            if(informations[minor_index].record<informations[j].record)
            {
                minor_index = j;
            }
        }
        auxilio = informations[i];
        informations[i] = informations[minor_index];
        informations[minor_index] = auxilio;
    }

    for(int i = 0; i < aux; i++){
        fprintf(recordes, "%s %d %d %d\n", informations[i].nome, informations[i].jogos, informations[i].record, informations[i].score);
    }

    close(file);
    close(recordes);
}

#endif