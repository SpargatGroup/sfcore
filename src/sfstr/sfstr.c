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
    * sf_strlen(s);
    * sf_strdup(char);
-----[ CONTRIBUTORS ]-----
    * Comical
*****[ SpargatFramework ]*****/
#include "sfmem/sfmem.h"
#include "sfdef/sfdef.h"
#include "sfstr/sfstr.h"
uint32_64 sf_strlen(const char *s) {
    if (!s) return 0;
    uint32_64 len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}
char *sf_strdup(const char *s) {
    if (!s) return null;
    uint32_64 len = sf_strlen(s) + 1;
    char *p = sf_malloc(len);
    if (p) sf_memcpy(p, s, len);
    return p;
}