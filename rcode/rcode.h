/*****[ SpargatFramework ]*****
-----[ BASIC ]-----
author: Comical
company: Spargat
file: rcode/rcode.h
language: Header
description:
    Native initialization for Android Application
-----[ DATES ]-----
created on: xy.xy.xxyy
last update: xy.xy.xxyy
-----[ CHANGES ]-----
    * xy.xy.xxyy: Initialization
-----[ References ]-----
    * encrypt(originalText, "output", 11)
    * decrypt("output", "originalText", 11)
-----[ CONTRIBUTORS ]-----
    * Comical
*****[ SpargatFramework ]*****/
#ifndef SF_RCODE_RCODE_H
#define SF_RCODE_RCODE_H
#ifdef __cplusplus
extern "C" {
#endif
void encrypt(const char* input, char* output, int key);
void decrypt(const char* input, char* output, int key);
#ifdef __cplusplus
}
#endif
#endif