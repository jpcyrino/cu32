/* CU32
 * Rotinas para conversão de strings em utf8 para
 * strings de caracteres de largura fixa de 32bits.
 * Não há conversão garantida para utf32 no momento.
 * Use para facilitar acesso randômico a caracteres 
 * unicode internamente ao programa.
 * 
 * Testado em GCC 13.2, C11
 * Autor: João Paulo Lazzarini Cyrino
 * Data 05.10.2023
 */

#ifndef __CU32_H__
#define __CU32_H__

#include <uchar.h>

// Retorna o número de caracteres em uma string codificada
// em UTF8
// u8str = string padrão C codificada em UTF8
size_t u8strlen(const char* u8str);

// Retorna o número de caracteres em uma string de
// caracteres de 32bits
// u32str = string padrão C codificada em caracteres de 32bits
size_t u32strlen(const char32_t* u32str);

// Retorna o número de bytes necessários para codificar uma string
// em caracteres de 32bits em uma string UTF8. Útil para
// alocar memória para string UTF8 que receberá a conversão na função
// u32to8 abaixo.
// u32str = string padrão C codificada em caracteres de 32bits
size_t u32strmblen(const char32_t* u32str);

// Copia uma string de caracteres de 32bits para um buffer de caracteres
// de 32bits. Interface semelhante a strcpy.
// dest = buffer de caracteres de 32bits.
// src = string a ser copiada
void u32strcpy(char32_t* dest, const char32_t* src);

// Converte uma string em UTF8 em uma string de caracteres
// de largura fixa de 32bits. 
// u8str = string padrão C codificada em UTF8
// u32str = buffer previamente alocado que receberá a string convertida.
size_t u8to32(const char* u8str, char32_t* u32str);

// Converte uma string de caracteres de largura fixa para uma 
// string codificada em UTF8.
// u32str = string padrão C codificada em largura fixa de 32bits
// u8str = buffer previamente alocado que recebeá a string convertida.
size_t u32to8(const char32_t* u32str, char* u8str);
#endif
