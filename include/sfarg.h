/*****[ SpargatFramework ]*****
-----[ BASIC ]-----
author: Comical
company: Spargat
file: sfarg.h
language: Header
description:
    Core Header function of SpargatFramework
-----[ DATES ]-----
created on: xy.xy.xxyy
last update: xy.xy.xxyy
-----[ CHANGES ]-----
    * xy.xy.xxyy: Initialization
-----[ References ]-----
    * sfva_start(v,arg);
    * sfva_end(v);
    * sfva_arg(v,t);
    * sfva_copy(d,s);
    * sfva_list;
    * sf::va_start(v,arg);
    * sf::va_end(v);
    * sf::va_arg(v,t);
    * sf::va_copy(d,s);
    * sf::va_list;
-----[ CONTRIBUTORS ]-----
    * Comical
*****[ SpargatFramework ]*****/
#ifndef SF_SFARG_H
#define SF_SFARG_H
#ifndef MSVC
#define sfva_start(v,arg) __builtin_va_start(v,arg)
#define sfva_end(v)	__builtin_va_end(v)
#define sfva_arg(v,t)	__builtin_va_arg(v,t)
#define sfva_copy(d,s)	__builtin_va_copy(d,s)
typedef __builtin_va_list sfva_list;
#ifdef __cplusplus
namespace sf {
    #define va_start(v,arg) sfva_start(v,arg)
    #define va_end(v)	sfva_end(v)
    #define va_arg(v,t)	sfva_arg(v,t)
    #define va_copy(d,s)	sfva_copy(d,s)
    typedef sfva_list va_list;
}
#endif
#endif
#endif