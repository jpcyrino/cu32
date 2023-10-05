#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <uchar.h>
#include <stdio.h>
#include "cu32.h"

int main()
{
    char* s = "我是老师不是中文";

    // Verifica número de bytes em s
    assert(strlen(s) == 24);
    
    // Verifica número de caracteres em s
    assert(u8strlen(s) == 8);

    // Converte string s em string de caracteres de 32bits
    char32_t* u32 = malloc((u8strlen(s) + 1) * sizeof(char32_t));
    char* u8;
    u8to32(s,u32);

    // Copia string u32 para string u32n
    char32_t* u32n = malloc((u32strlen(u32) + 1) * sizeof(char32_t));
    u32strcpy(u32n,u32);
    assert(strcmp((char*) u32n, (char*) u32) == 0);

    // Converte string u32 em string codificada em utf8
    size_t mbstrlen = u32strmblen(u32);
    u8 = malloc((mbstrlen + 1) * sizeof(char));
    u32to8(u32,u8);

    // Verifica número de caracteres igual em u32 e s
    assert(u32strlen(u32) == u8strlen(s));

    // Verifica igualdade entre u8 e s
    assert(strcmp(u8,s) == 0);

    // Liberar memória
    free(u32n); u32n = NULL;
    free(u32); u32 = NULL;
    free(u8); u8 = NULL;

    printf("All assertions passed!\n");
    return 0;
}
