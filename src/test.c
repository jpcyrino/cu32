#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <uchar.h>
#include <stdio.h>
#include "cu32.h"

int main()
{
    char* s = "我是老师不是中文";
    assert(strlen(s) == 24);
    assert(u8strlen(s) == 8);
    
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

    printf("All assertions passed!\n");
    return 0;
}
