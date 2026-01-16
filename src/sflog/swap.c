/*****[ SpargatFramework ]*****
-----[ BASIC ]-----
author: Comical
company: Spargat
file: sflog/swap.c
language: C
description:
    Log function of SpargatFramework
-----[ DATES ]-----
created on: xy.xy.xxyy
last update: xy.xy.xxyy
-----[ CHANGES ]-----
    * xy.xy.xxyy: Initialization
-----[ References ]-----
    * raw_print("Text");
    * sflog(debug, "Text");
    * sflog(info, "Text");
    * sflog(success, "Text");
    * sflog(warn, "Text");
    * sflog(warning, "Text");
    * sflog(error, "Text");
    * sflag(critical, "Text");
-----[ CONTRIBUTORS ]-----
    * Comical
*****[ SpargatFramework ]*****/
#include "sfio.h"
void sfswap(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}