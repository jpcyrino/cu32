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

    // Verifica a igualdade entre u32 e u32n
    assert(u32streq(u32n,u32) == 1);

    // Converte string u32 em string codificada em utf8
    size_t mbstrlen = u32strmblen(u32);
    u8 = malloc((mbstrlen + 1) * sizeof(char));
    u32to8(u32,u8);

    // Verifica número de caracteres igual em u32 e s
    assert(u32strlen(u32) == u8strlen(s));

    // Obtem uma cópia dos 3 primeiros caracteres de u32
    char32_t u32cp[4];
    u32strncpy(u32cp,u32,3);
    assert(u32strlen(u32cp) == 3);
    assert(u32cp[0] == u32[0]);
    assert(u32cp[1] == u32[1]);
    assert(u32cp[2] == u32[2]);


    // Liberar memória
    free(u32n); u32n = NULL;
    free(u32); u32 = NULL;
    free(u8); u8 = NULL;

    printf("All assertions passed!\n");
    return 0;
}
