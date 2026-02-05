/*****[ SpargatFramework ]*****
-----[ BASIC ]-----
author: Comical
company: Spargat
file: sfstr/sfstr.c
language: C
description:
    String function of SpargatFramework
-----[ DATES ]-----
created on: xy.xy.xxyy
last update: xy.xy.xxyy
-----[ CHANGES ]-----
    * xy.xy.xxyy: Initialization
-----[ References ]-----
    * sfstrlen(s);
    * sf_strdup(char);
-----[ CONTRIBUTORS ]-----
    * Comical
*****[ SpargatFramework ]*****/
#include "sfmem/sfmem.h"
#include "sfdef/sfdef.h"
#include "sfstr/sfstr.h"
uint32_64 sfstrlen(const char *s) {
    if (!s) return 0;
    uint32_64 len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}
void sfstrcopy(char *dest, const char *src) {
    while (*src) {
        *dest++ = *src++;
    }
    *dest = '\0';
}