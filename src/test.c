#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <uchar.h>
#include <stdio.h>
#include "cu32.h"

int main()
{
    char* s = "João Paulo Lazzarini Cyrino Análise Sintática";
    assert(strlen(s) == 48);
    assert(u8strlen(s) == 45);
    
    char32_t* u32 = malloc(5 * sizeof(char32_t));
    char* u8;
    u8to32(s,u32);
    size_t mbstrlen = u32strmblen(u32);
    u8 = malloc((mbstrlen + 1) * sizeof(char));
    u32to8(u32,u8);
    assert(u32strlen(u32) == u8strlen(s));
    assert(strcmp(u8,s) == 0);
    free(u32); u32 = NULL;
    free(u8); u8 = NULL;
    return 0;
}
