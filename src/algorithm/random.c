/*****[ SpargatFramework ]*****
-----[ BASIC ]-----
author: Comical
company: Spargat
file: algorithm/random.c
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
uint32 xorshift32(uint32 *state) {
    uint32 x = *state;
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    *state = x;
    return x;
}
uint32 random_limit(uint32 *state, uint32 max) {
    return xorshift32(state) % max;
}