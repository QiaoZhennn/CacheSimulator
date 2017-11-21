//
// Created by qiaoz on 11/19/2017.
//

#ifndef CACHESIM_DRIVER_H
#define CACHESIM_DRIVER_H
#include <string>
using namespace std;


class Driver {
    char* fileString;
public:
    explicit Driver(char* arg);
    char* hexToBin(char* input);
    void process();

};


#endif //CACHESIM_DRIVER_H
