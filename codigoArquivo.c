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
    int qtd_letras;
    char arquivo[20];
    PedirNome();

    switch (dificuldade)
    {
    case 1:
        printf(">>> MODO FACIL (5 letras) <<<\n");
        strcpy(arquivo, "palavras/facil.txt");
        qtd_letras = 5;
        break;
    case 2:
        printf(">>> MODO MEDIO (6 letras) <<<\n");
        strcpy(arquivo, "palavras/medio.txt");
        qtd_letras = 6;
        break;
    case 3:
        printf(">>> MODO DIFÍCIL (7 letras) <<<\n");
        strcpy(arquivo, "palavras/dificil.txt");
        qtd_letras = 7;
        break;
    default:
        break;
    }
    
    jogada(arquivo, palavritas, qtd_letras);


    // char* palavra_sorteada = SortearPalavra(LerArquivo(arquivo, palavritas), palavritas);
    // subtituloTermo();
    // printf("Palavra sorteada : %s\n", palavra_sorteada);

    // char *result = CompararPalavras(palavra_sorteada, InputResposta(qtd_letras), qtd_letras);

    // printf("%s\n", result);

    // VerUser();

}
