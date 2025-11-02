/*****[ SpargatFramework ]*****
-----[ BASIC ]-----
author: Comical
company: Spargat
file: Core/log/log.h
language: Header
description:
    Native initialization for Android Application
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
#ifndef OS_LOG_LOG_H
#define OS_LOG_LOG_H
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
void set_level(logLevel level);
const char* level_to_string(logLevel level);
#ifdef ANDROID
    int android_log_level(logLevel level);
#endif
void raw_print(const char *msg);
void sflog(logLevel level, const char *msg);
#ifdef __cplusplus
}
#endif
#endif