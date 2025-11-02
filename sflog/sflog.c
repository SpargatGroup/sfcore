/*****[ SpargatFramework ]*****
-----[ BASIC ]-----
author: Comical
company: Spargat
file: Core/log/log.c
language: C
description:
    Native initialization for Android Application
-----[ DATES ]-----
created on: xy.xy.xxyy
last update: xy.xy.xxyy
-----[ CHANGES ]-----
    * xy.xy.xxyy: Initialization
-----[ References ]-----
    * log(debug, "Text");
    * log(info, "Text");
    * log(success, "Text");
    * log(warn, "Text");
    * log(warning, "Text");
    * log(error, "Text");
    * lag(critical, "Text");
-----[ CONTRIBUTORS ]-----
    * Comical
*****[ SpargatFramework ]*****/
#ifdef ANDROID
    #include <android/log.h>
#elif defined(WINDOWS)
    #include <windows.h>
#endif
#include "sflog.h"
static logLevel currentLogLevel = debug;
void set_level(logLevel level) {
    currentLogLevel = level;
}
const char* level_to_string(logLevel level) {
    switch (level) {
        case debug: return "DEBUG";
        case info: return "INFO";
        case success: return "SUCCESS";
        case warn: return "WARNING";
        case warning: return "WARNING";
        case error: return "ERROR";
        case critical: return "CRITICAL";
        default: return "UNKNOWN";
    }
}
#ifdef ANDROID
    int android_log_level(logLevel level) {
        switch (level) {
            case debug: return ANDROID_LOG_debug;
            case info: return ANDROID_LOG_INFO;
            case success: return ANDROID_LOG_INFO;
            case warn: return ANDROID_LOG_WARN;
            case warning: return ANDROID_LOG_WARN;
            case error: return ANDROID_LOG_ERROR;
            case critical: return ANDROID_LOG_FATAL;
            default: return ANDROID_LOG_UNKNOWN;
        }
    }
#endif
void raw_print(const char *msg) {
    #ifdef WINDOWS
        DWORD written;
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        WriteFile(h, msg, (DWORD)strlen(msg), &written, NULL);
    #else
        unsigned long len = 0;
        while (msg[len] != '\0') len++;
        asm volatile (
            "mov $1, %%rax\n\t"
            "mov $1, %%rdi\n\t"
            "mov %0, %%rsi\n\t"
            "mov %1, %%rdx\n\t"
            "syscall\n\t"
            :
            : "r"(msg), "r"(len)
            : "%rax", "%rdi", "%rsi", "%rdx"
        );
    #endif
}
void sflog(logLevel level, const char *msg) {
    if (level < currentLogLevel)
        return;
    #ifdef ANDROID
        __android_log_write(android_log_level(level), "SFLog", msg);
    #endif
    raw_print("[");
    raw_print(level_to_string(level));
    raw_print("] ");
    raw_print(msg);
    raw_print("\n");
}