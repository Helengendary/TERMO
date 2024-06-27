#include <stdio.h>
#ifndef DESING_H
#define DESING_H
#define VERMELHO     "\x1b[31m"
#define VERDE        "\x1b[32m"
#define AZUL         "\x1b[34m"
#define AMARELO      "\x1b[33m"
#define MAGENTA      "\x1b[35m"
#define CIANO        "\x1b[36m"
#define NEGRITO      "\033[1m"
#define RESET        "\x1b[0m"
#define BACK_VERDE   "\x1b[32m"
#define BACK_AMARELO "\x1b[33m"
#define NEGRITO      "\033[1m"
#define VERMELHO     "\x1b[31m"
#define RESET        "\x1b[0m"


const char* getColor(char color) {
    switch (color) {
        case 'g': return BACK_VERDE;
        case 'y': return BACK_AMARELO;
        case 'w': return VERMELHO;
        default: return RESET;
    }
}


void tituloTermo() { 
    printf(VERMELHO"	______________________\n");
    printf(VERMELHO"      /\\                      \\\n");
    printf(VERMELHO"     /  \\______         _______\\\n");
    printf(VERMELHO"     \\  /      /\\      \\       /\n");
    printf(VERMELHO"      \\/______/  \\      \\_____/\n");
    printf(VERMELHO"              \\   \\      \\   "VERDE"_______  "MAGENTA"________  "AMARELO"___    ___  "CIANO"_______\n");
    printf(VERMELHO"               \\   \\      \\"VERDE"/\\   ____/"MAGENTA"\\   ___  \\"AMARELO"/   \\  /\\  \\"CIANO"/  ___  \\\n");
    printf(VERMELHO"                \\   \\      \\ "VERDE"\\ \\____"MAGENTA"\\ \\  \\  \\  \\"AMARELO"    \\/ /   \\  "CIANO"\\\\ \\  \\\n");
    printf(VERMELHO"                 \\   \\      \\ "VERDE"\\  ____"MAGENTA"\\ \\  \\_/  /"AMARELO"\\ \\   _     \\  "CIANO"\\\\ \\  \\\n");
    printf(VERMELHO"                  \\   \\______\\ "VERDE"\\ \\____"MAGENTA"\\ \\  \\ \\  \\"AMARELO"\\ \\  \\\\/ \\  \\  "CIANO"\\\\_\\  \\\n");
    printf(VERMELHO"                   \\  /      /"VERDE"\\ \\______"MAGENTA"\\ \\__\\ \\__\\"AMARELO"\\ \\__\\ \\ \\__\\"CIANO"\\______/  \n");
    printf(VERMELHO"                    \\/______/ "VERDE" \\/______/"MAGENTA"\\/__/\\/__/ "AMARELO"\\/__/  \\/__/"CIANO"/_____/\n\n\n" RESET);

}

void subtituloTermo(){

    printf(" _______  ____  _____  __  __   ___\n");
    printf("|__   __||  __||  _  ||  \\/  | /   \\\n");
    printf("   | |   | |_  | |_| ||      ||  _  |\n");
    printf("   | |   |  _| |    _|| |\\/| || |_| |\n");
    printf("   | |   | |__ | |\\ \\ | |  | ||     |\n");
    printf("   |_|   |____||_| \\_\\|_|  |_| \\___/\n"RESET);

}

void Teclado(){
    char *alfabeto[30] = {"Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "A", "S", "D", "F", "G", "H", "J", "K", "L", "Z", "X", "C", "V", "B", "N", "M"};

    printf("\n");
    for (int i = 0; i < 26; i++)
    {
        if (i == 10) {
            printf("\n");
            printf("   ");
        } else if(i == 19){
            printf("\n");
            printf("      ");
        }
        printf("%s   ", alfabeto[i]);
    }
    printf("\n");
    
}

void ImprimirMatriz(char **matriz, int qtd_letras, int tentativa, char **matriz_cores) { 

    for (int row = 0; row < tentativa+1; row++)
    {
        printf("\n");
        for (int col = 0; col < qtd_letras; col++)
        {
            printf("%s%s ___      %s", NEGRITO, getColor(matriz_cores[row][col]), RESET);
        }  
        printf("\n");
        for (int col = 0; col < qtd_letras; col++)
        {
            printf("%s%s|   |     %s", NEGRITO, getColor(matriz_cores[row][col]), RESET);
        }  
        printf("\n");
        for (int col = 0; col < qtd_letras; col++)
        {
            printf("%s%s| %c |     %s", NEGRITO, getColor(matriz_cores[row][col]), matriz[row][col], RESET);
        }  
        printf("\n");
        for (int col = 0; col < qtd_letras; col++)
        {
            printf("%s%s|___|     %s", NEGRITO, getColor(matriz_cores[row][col]), RESET);
        }  
        printf("\n");
    }
      
}

#endif