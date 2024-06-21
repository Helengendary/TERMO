#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "InterfaceUsuario.h"

int main() {
    int dificuldade = GuardarDificuldade();
    PedirNome();

    switch (dificuldade)
    {
    case 1:
        printf(">>> MODO FACIL <<<\n");
        // arquivo = fopen("palavras/facil.txt", "rt");

        
        break;
    case 2:
        printf(">>> MODO MEDIO <<<\n");
        // arquivo = fopen("palavras/medio.txt", "rt");
        break;
    case 3:
        printf(">>> MODO DIFÍCIL <<<\n");
        // arquivo = fopen("palavras/dificil.txt", "rt");
        break;
    
    default:
        break;
    }
    
    VerUser();

    // fclose(arquivo);
}
