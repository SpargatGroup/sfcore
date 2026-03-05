/*****[ SpargatFramework ]*****
-----[ BASIC ]-----
author: Comical
company: Spargat
file: sfutility.h
language: Header
description:
    Utility functions of SpargatFramework
-----[ DATES ]-----
created on: xy.xy.xxyy
last update: xy.xy.xxyy
-----[ CHANGES ]-----
    * xy.xy.xxyy: Initialization
-----[ References ]-----
    * sfswap(&a, &b);
    * sf::swap(&a, &b);
-----[ CONTRIBUTORS ]-----
    * Comical
*****[ SpargatFramework ]*****/
#ifndef SF_UTILITY_H
#define SF_UTILITY_H
#ifdef __cplusplus
extern "C" {
#endif
void sfswap(int *a, int *b);
#ifdef __cplusplus
}
namespace sf {
    using swap = sfswap;
}
#endif
#endif