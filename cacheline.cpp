//
// Created by qiaoz on 11/19/2017.
//

#include "cacheline.h"

Cacheline::Cacheline() {
    for(int i=0;i<Tag_Size;++i)tag[i]='x';//initialize
    valid=false;
}
