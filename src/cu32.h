#ifndef __CU32_H__
#define __CU32_H__

#include <uchar.h>

size_t u8strlen(const char* u8str);
size_t u32strlen(const char32_t* u32str);
size_t u32strmblen(const char32_t* u32str);
size_t u8to32(const char* u8str, char32_t* u32str);
size_t u32to8(const char32_t* u32str, char* u8str);
#endif
