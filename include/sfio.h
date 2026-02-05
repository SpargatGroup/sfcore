/*****[ SpargatFramework ]*****
-----[ BASIC ]-----
author: Comical
company: Spargat
file: sfio.h
language: Header
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
    * sflog(critical, "Text");
    * sfswap(&a, &b);
    * sf::swap(&a, &b);
-----[ CONTRIBUTORS ]-----
    * Comical
*****[ SpargatFramework ]*****/
#ifndef SF_SFIO_H
#define SF_SFIO_H
#ifdef __cplusplus
extern "C" {
#endif
#include "sfdef/sfdef.h"
#include "sfstr/sfstr.h"
typedef enum {
    debug = 0,
    info,
    success,
    warn,
    warning,
    error,
    critical
} logLevel;
typedef struct logNode {
    logLevel level;
    const char* tag;
    const char* msg;
    struct logNode *next;
} logNode;
extern logNode *logList;
void set_level(logLevel level);
const char* level_to_string(logLevel level);
void log_add(logNode **head, logLevel level, const char* tag, const char* msg);
void sflog_clear();
#ifdef ANDROID
    int android_log_level(logLevel level);
#endif
void raw_print(const char* msg);
void sflog(logLevel level, const char* tag, const char* msg);
void sfswap(int *a, int *b);
#ifdef __cplusplus
}
namespace sf {
    inline void swap(int *a, int *b) {
        ::sfswap(a, b);
    }
}
#endif
#endif