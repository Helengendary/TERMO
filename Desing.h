#include <stdio.h>
#ifndef DESING_H
#define DESING_H
#define VERMELHO     "\x1b[31m"
#define VERDE        "\x1b[32m"
#define AZUL         "\x1b[34m"
#define AMARELO      "\x1b[33m"
#define MAGENTA      "\x1b[35m"
#define CIANO        "\x1b[36m"
#define RESET        "\x1b[0m"



void tituloTermo() { 
    printf(VERMELHO"	______________________\n");
    printf(VERMELHO"      /\\                      \\\n");
    printf(VERMELHO"     /  \\______         _______\\\n");
    printf(VERMELHO"     \\  /      /\\      \\       /\n");
    printf(VERMELHO"      \\/______/  \\      \\_____/\n");
    printf(VERMELHO"              \\   \\      \\   "VERDE"_______  "MAGENTA"________  "AMARELO"___    ___  "CIANO"_______\n");
    printf(VERMELHO"               \\   \\      \\"VERDE"/\\   ____/"MAGENTA"\\   ___  \\"AMARELO"/   \\  /\\  \\"CIANO"/  ___  \\\n");
    printf(VERMELHO"                \\   \\      \\ "VERDE"\\ \\____"MAGENTA"\\ \\  \\  \\ "AMARELO" \\    \\/ /   \\  "CIANO"\\\\ \\  \\\n");
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

// void ImprimirMatriz(char matriz[5][5]) { 
        
//     for (int row = 0; row < 5; row++)
//     {
//         printf("\n");
//         for (int col = 0; col < 5; col++)
//         {
//             printf(" ___      ");
//         }  
//         printf("\n");
//         for (int col = 0; col < 5; col++)
//         {
//             printf("|   |     ");
//         }  
//         printf("\n");
//         for (int col = 0; col < 5; col++)
//         {
//             printf("|   |     ");
//         }  
//         printf("\n");
//         for (int col = 0; col < 5; col++)
//         {
//             printf("|___|     ");
//         }  
//         printf("\n");
//     }
// }

#endif