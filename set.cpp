//
// Created by qiaoz on 11/19/2017.
//

#include "set.h"

Set::Set() {
    for(int i=0;i<Way_Associative;++i){
        cachelines[i]=new Cacheline();
    }
}

/*
 * For example, 4 way-associative: MRU-LRU1-LRU2_LRU3
 * First, pull data from LRU2 to LRU3
 * Second, pull data from LRU1 to LRU2
 * Third, pull data from MRU to LRU1
 * Fourth, insert new data to MRU, which is cachelines[0]
 */
void Set::insertMRU_Set(char *addrBin) {
    updateLRU_Sets();
    cachelines[0]->valid=true;
    for(int i=0;i<Tag_Size;i++) {
        cachelines[0]->tag[i]=addrBin[i];
    }
}

void Set::updateLRU_Sets() {
    for(int i=Way_Associative-1;i>0;i--){
        for(int j=0;j<Tag_Size;j++) {
            cachelines[i]->tag[j]=cachelines[i-1]->tag[j];
            cachelines[i]->valid=cachelines[i-1]->valid;
        }
    }
}
