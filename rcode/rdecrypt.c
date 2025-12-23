/*****[ SpargatFramework ]*****
-----[ BASIC ]-----
author: Comical
company: Spargat
file: rcode/rdecrypt.c
language: C
description:
    Native initialization for Android Application
-----[ DATES ]-----
created on: xy.xy.xxyy
last update: xy.xy.xxyy
-----[ CHANGES ]-----
    * xy.xy.xxyy: Initialization
-----[ References ]-----
    * decrypt("output", "originalText", 11)
-----[ CONTRIBUTORS ]-----
    * Comical
*****[ SpargatFramework ]*****/
#include "../sfdef/sfdef.h"
#include "rcode.h"
void decrypt(const char* input, char* output, int key) {
    int i;
    for (i = 1; input[i] != '\0'; i++) {
        uint8 c = input[i];
        c = (c - (i - 1) * key - key + 256) % 256;
        output[i - 1] = c;
    }
    output[i - 1] = '\0';
}