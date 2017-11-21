//
// Created by qiaoz on 11/19/2017.
//

#include "cache.h"


using namespace std;


Cache::Cache() {
    for (int i = 0; i < Num_Sets; ++i) {
        sets[i] = new Set();
    }
}

struct cache_status {
    int total_traces;  //number of memory refs
    int read_count; //number of reads
    int write_count; //number of writes
    int miss_count;
    int hit_count;
    int read_hit_count;
    int write_hit_count;
    double hit_rate;
} status = {0, 0, 0, 0, 0, 0, 0, 0.0};


void Cache::printStatus() {
    /* prepare data before printing */
    status.total_traces = status.read_count + status.write_count;
    status.hit_count = status.read_hit_count + status.write_hit_count;

    status.hit_rate = (double) status.hit_count / status.total_traces;
    cout << "-----------------BEGIN-----------------" << endl;
    cout << "Total traces: " << status.total_traces << endl;
    cout << "Reads: " << status.read_count << endl;
    cout << "Writes: " << status.write_count << endl;
    cout << "Cache hits: " << status.hit_count << endl;
    cout << "Cache misses: " << status.miss_count << endl;
    cout << "Hit rate: " << status.hit_rate * 100 << " %" << endl;
    cout << "-----------------END-----------------" << endl;
}


bool Cache::charEqual(char *a, char *b, int N) {
    int count = 0;
    for (int i = 0; i < N; ++i) {
        if (a[i] == b[i])count++;
    }
    return count == N;
}

int Cache::getSetIndex(char *addrBin) {
    int setIndex = 0;
    for (int i = 0; i < Index_Size; ++i) {
        if (addrBin[Tag_Size + i] == '1') setIndex += pow(2, Index_Size - 1 - i);
    }
    return setIndex;
}

bool Cache::isHit(char *addrBin, int setIndex) {
    string address = addrBin;
    if (DEBUG) {
        cout << "address tag: " << address.substr(0, 11) << "\tindex: " << address.substr(11, 17) << "\toffset: "
             << address.substr(28, 4) << endl;
    }
    for (int i = 0; i < Way_Associative; ++i) {
        Set *set = sets[setIndex];
        Cacheline *cacheline = set->cachelines[i];
        char *tag = cacheline->tag;
        if (DEBUG) {
            cout << "Way: " << i << "\tSet Index: " << setIndex << "\tTag: " << tag << endl;
        }
        bool a = charEqual(tag, addrBin, Tag_Size);
        bool b = cacheline->valid;
        if (a && b) {
            if (DEBUG) {
                cout << "hit" << endl << endl;
            }
            //hit here
            if (i == Way_Associative - 1) {
                //if the hit set is not MRU, put it into MRU. Only work for the last LRU is hit's scenario.
                set->insertMRU_Set(addrBin);
            }
            return true;
        }
    }
    if (DEBUG) cout << endl;
    return false;
}

void Cache::read(char *addrBin) {
    int setIndex = getSetIndex(addrBin);
    status.read_count++;
    if (isHit(addrBin, setIndex)) {
        status.read_hit_count++;
    } else {
        status.miss_count++;
        sets[setIndex]->insertMRU_Set(addrBin);
    }
}

void Cache::write(char *addrBin) {
    int setIndex = getSetIndex(addrBin);
    status.write_count++;
    if (isHit(addrBin, setIndex)) {
        status.write_hit_count++;
    } else {
        status.miss_count++;
        sets[setIndex]->insertMRU_Set(addrBin);
    }
}