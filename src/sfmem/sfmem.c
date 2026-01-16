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
    * sf_free(ptr, len);
    * sf_malloc(len);
-----[ CONTRIBUTORS ]-----
    * Comical
*****[ SpargatFramework ]*****/
#include "sfdef/sfdef.h"
#include "sfmem/sfmem.h"
void *sf_memcpy(void *dest, const void *src, uint32_64 n) {
    uint8 *d = dest;
    const uint8 *s = src;
    while (n--) *d++ = *s++;
    return dest;
}
static uint32_64 heap_index = 0;
static uint8 heap[HEAP_SIZE];
void sf_free(void *ptr, uint32_64 size) {
    size = (size + 7) & ~7;
    if ((uint8*)ptr + size == &heap[heap_index]) {
        heap_index -= size;
    }
}
void *sf_malloc(uint32_64 size) {
    size = (size + 7) & ~7;
    if (size > HEAP_SIZE - heap_index) return null;
    void *p = &heap[heap_index];
    heap_index += size;
    return p;
}