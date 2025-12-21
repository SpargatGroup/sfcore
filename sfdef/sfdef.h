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
    * a = null;
    * uint8 a;
    * uint16 a;
    * uint32 a;
    * uint32_64 a;
    * uint64 a;
    * int8 a;
    * int16 a;
    * int32 a;
    * int32_64 a;
    * int64 a;
-----[ CONTRIBUTORS ]-----
    * Comical
*****[ SpargatFramework ]*****/
#ifndef SF_DEF_DEF_H
#define SF_DEF_DEF_H
#ifdef __cplusplus
extern "C" {
#endif
typedef struct {} unit;
#define null ((void*)0) // NULL from C
//unsigned
typedef unsigned char uint8; // 8-bit unsigned integer
typedef unsigned short uint16; // 16-bit unsigned integer
typedef unsigned int uint32; // 32-bit unsigned integer
typedef unsigned long uint32_64; // 32-bit/64-bit unsigned integer & size_t
typedef unsigned long long uint64; // 64-bit unsigned integer
//signed
typedef signed char int8; // 8-bit signed integer
typedef signed short int16; // 16-bit signed integer
typedef signed int int32; // 32-bit signed integer
typedef signed long int32_64; // 32-bit/64-bit signed integer & ptrdiff_t
typedef signed long long int64; // 64-bit signed integer
//real
typedef float real32; // 32-bit floating point
typedef double real64; // 64-bit floating point
typedef long double real64_80_128; // 64-bit/80-bit/128-bit floating point
#ifdef __cplusplus
}
#endif
#endif