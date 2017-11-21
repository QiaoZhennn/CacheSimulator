//
// Created by qiaoz on 11/19/2017.
//

#ifndef CACHESIM_DRIVER_H
#define CACHESIM_DRIVER_H
#include <string>
using namespace std;


class Driver {
    string fileString;
public:
    explicit Driver(string arg);
    char* hexToBin(char* input);
    void process();

};


#endif //CACHESIM_DRIVER_H
