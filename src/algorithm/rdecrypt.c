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
#include "types/int.h"
#include "sfrcode.h"
void sfdecrypt(const char* input, char* output, int key) {
    uint8 current_key_offset = (uint8)key;
    uint8 k = (uint8)key;
    int i;
    while (input[i] != '\0') {
        output[i - 1] = (uint8)input[i] - current_key_offset;
        current_key_offset += k;
        i++;
    }
    output[i - 1] = '\0';
}