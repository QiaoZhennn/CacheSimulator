//
// Created by qiaoz on 11/19/2017.
//

#include "set.h"
#include <cstring>
#include<iostream>
#include <cmath>
#define DEBUG 0

#ifndef CACHESIM_CACHE_H
#define CACHESIM_CACHE_H


class Cache {

public:
    Set *sets[Num_Sets];

    Cache();
    void printStatus();
    bool charEqual(char* a, char* b, int N);
    int getSetIndex(char* addrBin);
    bool isHit(char* addrBin, int setIndex);
    void read(char* addrBin);
    void write(char* addrBin);
};


#endif //CACHESIM_CACHE_H
