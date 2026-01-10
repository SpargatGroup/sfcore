/*****[ SpargatFramework ]*****
-----[ BASIC ]-----
author: Comical
company: Spargat
file: sflog/sflog.c
language: C
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
    * sflag(critical, "Text");
-----[ CONTRIBUTORS ]-----
    * Comical
*****[ SpargatFramework ]*****/
#include "../sfmem/sfmem.h"
#include "../sfstr/sfstr.h"
#ifdef ANDROID
    #include <android/log.h>
#elif defined(WINDOWS)
    #include <windows.h>
#endif
#include "sflog.h"
static logLevel currentLogLevel = debug;
logNode *logList = null;
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
void raw_print(const char* msg) {
    #ifdef WINDOWS
        DWORD written;
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        if (h == INVALID_HANDLE_VALUE) return;
        if (!msg) return;
        WriteFile(h, msg, (DWORD)sf_strlen(msg), &written, null);
    #elif defined(LINUX) || defined(ANDROID)
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
    #elif defined(AMUI)
        // in work
    #endif
}
void log_add(logNode **head, logLevel level, const char* tag, const char* msg) {
    logNode *n = sf_malloc(sizeof(logNode));
    n->level = level;
    n->tag = sf_strdup(tag);
    n->msg = sf_strdup(msg);
    n->next = *head;
    *head = n;
}
void sflog_clear() {
    logNode *curr = logList;
    while (curr != null) {
        logNode *temp = (logNode*)curr->next;
        if (curr->tag) {
            uint32_64 tagLen = (uint32_64)sf_strlen(curr->tag) + 1;
            sf_free((void*)curr->tag, tagLen);
        }
        if (curr->msg) {
            uint32_64 msgLen = (uint32_64)sf_strlen(curr->msg) + 1;
            sf_free((void*)curr->msg, msgLen);
        }
        sf_free(curr, sizeof(logNode));
        curr = temp;
    }
    logList = null;
}
void sflog(logLevel level, const char* tag, const char* msg) {
    if (level < currentLogLevel)
        return;
    #ifdef ANDROID
        __android_log_write(android_log_level(level), tag, msg);
    #else
        raw_print("[");
        raw_print(level_to_string(level));
        raw_print("] ");
        raw_print(msg);
        raw_print("\n");
    #endif
    log_add(&logList, level, tag, msg);
}