/*****[ SpargatFramework ]*****
-----[ BASIC ]-----
author: Comical
company: Spargat
file: sfmem/sfmem.c
language: C
description:
    Memory function of SpargatFramework
-----[ DATES ]-----
created on: xy.xy.xxyy
last update: xy.xy.xxyy
-----[ CHANGES ]-----
    * xy.xy.xxyy: Initialization
-----[ References ]-----
    * sf_memcpy(p, s, len);
    * sf_malloc(len);
-----[ CONTRIBUTORS ]-----
    * Comical
*****[ SpargatFramework ]*****/
#include "../sfdef/sfdef.h"
#include "sfmem.h"
void *sf_memcpy(void *dest, const void *src, uint32_64 n) {
    unsigned char *d = (unsigned char *)dest;
    const unsigned char *s = (const unsigned char *)src;
    for (uint32_64 i = 0; i < n; i++) {
        d[i] = s[i];
    }
    return dest;
}
static uint32_64 heap_index = 0;
void *sf_malloc(uint32_64 size) {
    if (heap_index + size > HEAP_SIZE) return nul;
    void *p = &heap[heap_index];
    heap_index += size;
    return p;
}