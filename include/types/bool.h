/*****[ SpargatFramework ]*****
-----[ BASIC ]-----
author: Comical
company: Spargat
file: types/int.h
language: H
description:
    Definitions function of SpargatFramework
-----[ DATES ]-----
created on: xy.xy.xxyy
last update: xy.xy.xxyy
-----[ CHANGES ]-----
    * xy.xy.xxyy: Initialization
-----[ References ]-----
    * bool a;
-----[ CONTRIBUTORS ]-----
    * Comical
*****[ SpargatFramework ]*****/
#ifndef SF_TYPES_INT_H
#define SF_TYPES_INT_H
#ifdef __cplusplus
extern "C" {
#endif
typedef unsigned char sfbool;
#define true 1
#define false 0
#ifdef __cplusplus
}
namespace sf {
    typedef sfbool bool
}
#endif
#endif