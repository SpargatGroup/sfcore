/*****[ SpargatFramework ]*****
-----[ BASIC ]-----
author: Comical
company: Spargat
file: sfstr/sfstr.h
language: H
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
#ifndef SF_STR_STR_H
#define SF_STR_STR_H
#ifdef __cplusplus
extern "C" {
#endif
#include "../sfdef/sfdef.h"
uint32_64 sfstrlen(const char *s);
void sfstrcopy(char *dest, const char *src);
#ifdef __cplusplus
}
#endif
#endif