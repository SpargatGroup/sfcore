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
#include "../sfbase/sfbase.h"
#include "sfmem.h"
void *sf_memcpy(void *dest, const void *src, stpe n) {
    unsigned char *d = (unsigned char *)dest;
    const unsigned char *s = (const unsigned char *)src;
    for (stpe i = 0; i < n; i++) {
        d[i] = s[i];
    }
    return dest;
}
void *sf_malloc(stpe size) {
    if (heap_index + size > HEAP_SIZE) return nul;
    void *p = &heap[heap_index];
    heap_index += size;
    return p;
}