/*****[ SpargatFramework ]*****
-----[ BASIC ]-----
author: Comical
company: Spargat
file: sfrcode.h
language: Header
description:
    Native initialization for Android Application
-----[ DATES ]-----
created on: xy.xy.xxyy
last update: xy.xy.xxyy
-----[ CHANGES ]-----
    * xy.xy.xxyy: Initialization
-----[ References ]-----
    * sfencrypt(originalText, "output", 11)
    * sfdecrypt("output", "originalText", 11)
    * sf::encrypt(originalText, "output", 11)
    * sf::decrypt("output", "originalText", 11)
-----[ CONTRIBUTORS ]-----
    * Comical
*****[ SpargatFramework ]*****/
#ifndef SF_SFRCODE_H
#define SF_SFRCODE_H
#ifdef __cplusplus
extern "C" {
#endif
void sfencrypt(const char* input, char* output, int key);
void sfdecrypt(const char* input, char* output, int key);
#ifdef __cplusplus
}
namespace sf {
    inline void encrypt(const char* input, char* output, int key) {
        ::sfencrypt(input, output, key);
    }
    inline void decrypt(const char* input, char* output, int key) {
        ::sfdecrypt(input, output, key);
    }
}
#endif
#endif