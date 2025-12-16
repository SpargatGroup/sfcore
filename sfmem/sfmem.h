/*****[ SpargatFramework ]*****
-----[ BASIC ]-----
author: Comical
company: Spargat
file: sfmem/sfmem.h
language: H
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
#ifndef SF_MEM_MEM_H
#define SF_MEM_MEM_H
#include "../sfbase/sfbase.h"
#ifdef __cplusplus
extern "C" {
#endif
void *sf_memcpy(void *dest, const void *src, stpe n);
#define HEAP_SIZE 1024*1024
static unsigned char heap[HEAP_SIZE];
static stpe heap_index = 0;
void *sf_malloc(stpe size);
#ifdef __cplusplus
}
#endif
#endif