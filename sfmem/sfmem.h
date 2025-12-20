/*****[ SpargatFramework ]*****
-----[ BASIC ]-----
author: Comical
company: Spargat
file: sfmem/sfmem.h
language: H
description:
    Memory function of SpargatFramework
-----[ DATES ]-----
created on: xy.xy.xxyy
last update: xy.xy.xxyy
-----[ CHANGES ]-----
    * xy.xy.xxyy: Initialization
-----[ References ]-----
    * sf_memcpy(p, s, len);
    * sf_malloc(len);
    * launch([](){
        std::cout << "Task 1 started\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout << "Task 1 finished\n";
    });
    * unit a {
        sflog(debug, "Text");
        return (Unit){};
    };
    * unit b = a;
    * nul;
    * stpe; // size type
-----[ CONTRIBUTORS ]-----
    * Comical
*****[ SpargatFramework ]*****/
#ifndef SF_MEM_MEM_H
#define SF_MEM_MEM_H
#ifdef __cplusplus
#include <thread>
#include <vector>
std::vector<std::thread> threads;
template<typename Func>
void launch(Func&& f) {
    threads.emplace_back(std::forward<Func>(f));
}
extern "C" {
#endif
#define nul 0
typedef unsigned long stpe;
typedef struct {} unit;
void *sf_memcpy(void *dest, const void *src, stpe n);
#define HEAP_SIZE 1024*1024
static unsigned char heap[HEAP_SIZE];
static stpe heap_index = 0;
void *sf_malloc(stpe size);
#ifdef __cplusplus
}
#endif
#endif