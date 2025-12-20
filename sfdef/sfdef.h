/*****[ SpargatFramework ]*****
-----[ BASIC ]-----
author: Comical
company: Spargat
file: sfdef/sfdef.h
language: H
description:
    Definitions function of SpargatFramework
-----[ DATES ]-----
created on: xy.xy.xxyy
last update: xy.xy.xxyy
-----[ CHANGES ]-----
    * xy.xy.xxyy: Initialization
-----[ References ]-----
    * unit a {
        sflog(debug, "Text");
        return (Unit){};
    };
    * unit b = a;
    * nul; // NULL from C
    * uint8; // 8-bit unsigned integer
    * uint16; // 16-bit unsigned integer
    * uint32; // 32-bit unsigned integer
    * uint32_64; // 32-bit/64-bit unsigned integer
    * uint64; // 64-bit unsigned integer
    * sint8; // 8-bit signed integer
    * sint16; // 16-bit signed integer
    * sint32; // 32-bit signed integer
    * sint32_64; // 32-bit/64-bit signed integer
    * sint64; // 64-bit signed integer
-----[ CONTRIBUTORS ]-----
    * Comical
*****[ SpargatFramework ]*****/
#ifndef SF_DEF_DEF_H
#define SF_DEF_DEF_H
#ifdef __cplusplus
extern "C" {
#endif
typedef struct {} unit;
#define nul ((void*)0)
//unsigned
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef unsigned long uint32_64;
typedef unsigned long long uint64;
//signed
typedef signed char sint8;
typedef signed short sint16;
typedef signed int sint32;
typedef signed long sint32_64;
typedef signed long long sint64;
#ifdef __cplusplus
}
#endif
#endif