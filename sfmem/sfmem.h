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
-----[ CONTRIBUTORS ]-----
    * Comical
*****[ SpargatFramework ]*****/
#ifndef SF_MEM_MEM_H
#define SF_MEM_MEM_H
#include "../sfdef/sfdef.h"
#ifdef __cplusplus
#include <thread>
#include <vector>
#include <utility>
class ThreadLauncher {
    std::vector<std::thread> threads;
public:
    template<typename Func>
    void launch(Func&& f) {
        threads.emplace_back(std::forward<Func>(f));
    }

    ~ThreadLauncher() {
        for (auto& t : threads) {
            if (t.joinable()) t.join();
        }
    }

    void join_all() {
        for (auto& t : threads) {
            if (t.joinable()) t.join();
        }
        threads.clear();
    }
};
extern "C" {
#endif
void *sf_memcpy(void *dest, const void *src, uint32_64 n);
#define HEAP_SIZE 1024*1024
void sf_free(void *ptr, uint32_64 size);
void *sf_malloc(uint32_64 size);
#ifdef __cplusplus
}
#endif
#endif