#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "InterfaceUsuario.h"
#include "BackEnd.h"
#include "Desing.h"

int main() {
    tituloTermo();
    char palavritas[50][10];
    int dificuldade = GuardarDificuldade();
    int qtd_letras = 5;
    char arquivo[20];
    PedirNome();
    strcpy(arquivo, "palavras/facil.txt");

    switch (dificuldade)
    {
    case 1:
        jogadaTermo(arquivo, palavritas, qtd_letras);
        break;
    case 2:
        jogadaDueto(arquivo, palavritas, qtd_letras);
        break;
    default:
        break;
    }
    

}
