#include <stdio.h>

#ifndef ARQUIVO_H
#define ARQUIVO_H

void MandarArquivo(char *nome, int jogos, int record,int score) {
    FILE * arquivo;

    arquivo = fopen("jogadas.txt", "a");
    
    fprintf(arquivo, "\nNome: %s\nJogos: %d\nRecord: %d\nScore: %d\n", nome, jogos, record, score);
}

#endif