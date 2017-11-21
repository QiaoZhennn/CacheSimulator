//
// Created by qiaoz on 11/19/2017.
//
#include "cacheline.h"

#ifndef CACHESIM_SET_H
#define CACHESIM_SET_H


class Set {
public:
    Cacheline* cachelines[Way_Associative];

    Set();
    void insertMRU_Set(char* addrBin);
    void updateLRU_Sets();
};


#endif //CACHESIM_SET_H
