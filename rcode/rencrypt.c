/*****[ SpargatFramework ]*****
-----[ BASIC ]-----
author: Comical
company: Spargat
file: rcode/rencrypt.c
language: C
description:
    Native initialization for Android Application
-----[ DATES ]-----
created on: xy.xy.xxyy
last update: xy.xy.xxyy
-----[ CHANGES ]-----
    * xy.xy.xxyy: Initialization
-----[ References ]-----
    * encrypt(originalText, "output", 11)
-----[ CONTRIBUTORS ]-----
    * Comical
*****[ SpargatFramework ]*****/
#include "../sfdef/sfdef.h"
#include "rcode.h"
void encrypt(const char* input, char* output, int key) {
    int i;
    output[0] = 57;
    for (i = 0; input[i] != '\0'; i++) {
        uint8 c = input[i];
        c = (c + (i * key) + key) % 256;
        output[i + 1] = c;
    }
    output[i + 1] = '\0';
}