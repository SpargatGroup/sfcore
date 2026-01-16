/*****[ SpargatFramework ]*****
-----[ BASIC ]-----
author: Comical
company: Spargat
file: sfcore.h
language: Header
description:
    Core Header function of SpargatFramework
-----[ DATES ]-----
created on: xy.xy.xxyy
last update: xy.xy.xxyy
-----[ CHANGES ]-----
    * xy.xy.xxyy: Initialization
-----[ References ]-----
    * log(LOG_debug, "Text");
    * log(LOG_ERROR, "Text");
    * log(LOG_WARNING, "Text");
    * log(LOG_SUCCESS, "Text");
    * log(LOG_INFO, "Text");
-----[ CONTRIBUTORS ]-----
    * Comical
*****[ SpargatFramework ]*****/
#ifndef SF_SFARG_H
#define SF_SFARG_H
#define va_start(v,arg) __builtin_va_start(v,arg)
#define va_end(v)	__builtin_va_end(v)
#define va_arg(v,t)	__builtin_va_arg(v,t)
#define va_copy(d,s)	__builtin_va_copy(d,s)
typedef __builtin_va_list va_list;
#endif