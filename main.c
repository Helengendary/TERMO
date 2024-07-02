#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "InterfaceUsuario.h"
#include "BackEnd.h"
#include "Desing.h"

int main() {
    tituloTermo();
    char palavritas[1000][6];
    int dificuldade = GuardarDificuldade();
    int qtd_letras = 5;
    char arquivo[20];
    PedirNome();

    strcpy(arquivo, "palavras/facil.txt");

    switch (dificuldade)
    {
    case 1:
        jogada(1, arquivo, palavritas, qtd_letras);
        break;
    case 2:
        jogada(2, arquivo, palavritas, qtd_letras);
        break;
    default:
        break;
    }
}