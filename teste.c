#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "BackEnd.h"

int main(void)
{
char palavritas[50][10];

char* palavra = SortearPalavra(LerArquivo("palavras/facil.txt", palavritas), palavritas);

printf("%s\n", palavra);
}