/*****[ SpargatFramework ]*****
-----[ BASIC ]-----
author: Comical
company: Spargat
file: types/float.h
language: H
description:
    Definitions function of SpargatFramework
-----[ DATES ]-----
created on: xy.xy.xxyy
last update: xy.xy.xxyy
-----[ CHANGES ]-----
    * xy.xy.xxyy: Initialization
-----[ References ]-----
    * real32 a;
    * real64 a;
    * real64_80_128 a;
-----[ CONTRIBUTORS ]-----
    * Comical
*****[ SpargatFramework ]*****/
#ifndef SF_TYPES_REAL_H
#define SF_TYPES_REAL_H
#ifdef __cplusplus
extern "C" {
#endif
typedef float sfreal32; // 32-bit floating point
typedef double sfreal64; // 64-bit floating point
typedef long double sfreal64_80_128; // 64-bit/80-bit/128-bit floating point
#ifdef __cplusplus
}
namespace sf {
    typedef sfreal32 real32;
    typedef sfreal64 real64;
    typedef sfreal64_80_128 real64_80_128;
}
#endif
#endif