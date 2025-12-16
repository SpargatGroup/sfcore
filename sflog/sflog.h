/*****[ SpargatFramework ]*****
-----[ BASIC ]-----
author: Comical
company: Spargat
file: sflog/sflog.h
language: Header
description:
    Log function of SpargatFramework
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
#ifndef SF_LOG_LOG_H
#define SF_LOG_LOG_H
#include "../sfbase/sfbase.h"
#include "../sfstr/sfstr.h"
#ifdef __cplusplus
extern "C" {
#endif
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
logNode *logList = nul;
void set_level(logLevel level);
const char* level_to_string(logLevel level);
void log_add(logNode **head, logLevel level, const char* tag, const char* msg);
#ifdef ANDROID
    int android_log_level(logLevel level);
#endif
void raw_print(const char* msg);
void sflog(logLevel level, const char* tag, const char* msg);
#ifdef __cplusplus
}
#endif
#endif