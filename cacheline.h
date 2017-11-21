//
// Created by qiaoz on 11/19/2017.
//

#define Block_Size 16
#define Num_Sets 131072
#define Way_Associative 2
#define Tag_Size 11
#define Index_Size 17
#define Offset_Size 4

#ifndef CACHESIM_CACHELINE_H
#define CACHESIM_CACHELINE_H


class Cacheline {
public:
    char* tag = new char[Tag_Size];
    bool valid;
    Cacheline();
};


#endif //CACHESIM_CACHELINE_H
