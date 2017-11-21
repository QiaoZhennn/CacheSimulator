//
// Created by qiaoz on 11/19/2017.
//
#include <cstdio>
#include <fstream>
#include "driver.h"
#include "cache.h"
using namespace std;

Driver::Driver(string arg) {
    fileString = arg;
}

char* Driver::hexToBin(char* input){
    int x = 4;
    int size;
    size = strlen(input);
    //printf("size is %d\n",size);

    char* output = new char[size*4+1];

    for (int i = 0; i < size; i++)
    {
        if (input[i] =='0') {
            output[i*x +0] = '0';
            output[i*x +1] = '0';
            output[i*x +2] = '0';
            output[i*x +3] = '0';
        }
        else if (input[i] =='1') {
            output[i*x +0] = '0';
            output[i*x +1] = '0';
            output[i*x +2] = '0';
            output[i*x +3] = '1';
        }
        else if (input[i] =='2') {
            output[i*x +0] = '0';
            output[i*x +1] = '0';
            output[i*x +2] = '1';
            output[i*x +3] = '0';
        }
        else if (input[i] =='3') {
            output[i*x +0] = '0';
            output[i*x +1] = '0';
            output[i*x +2] = '1';
            output[i*x +3] = '1';
        }
        else if (input[i] =='4') {
            output[i*x +0] = '0';
            output[i*x +1] = '1';
            output[i*x +2] = '0';
            output[i*x +3] = '0';
        }
        else if (input[i] =='5') {
            output[i*x +0] = '0';
            output[i*x +1] = '1';
            output[i*x +2] = '0';
            output[i*x +3] = '1';
        }
        else if (input[i] =='6') {
            output[i*x +0] = '0';
            output[i*x +1] = '1';
            output[i*x +2] = '1';
            output[i*x +3] = '0';
        }
        else if (input[i] =='7') {
            output[i*x +0] = '0';
            output[i*x +1] = '1';
            output[i*x +2] = '1';
            output[i*x +3] = '1';
        }
        else if (input[i] =='8') {
            output[i*x +0] = '1';
            output[i*x +1] = '0';
            output[i*x +2] = '0';
            output[i*x +3] = '0';
        }
        else if (input[i] =='9') {
            output[i*x +0] = '1';
            output[i*x +1] = '0';
            output[i*x +2] = '0';
            output[i*x +3] = '1';
        }
        else if (input[i] =='a') {
            output[i*x +0] = '1';
            output[i*x +1] = '0';
            output[i*x +2] = '1';
            output[i*x +3] = '0';
        }
        else if (input[i] =='b') {
            output[i*x +0] = '1';
            output[i*x +1] = '0';
            output[i*x +2] = '1';
            output[i*x +3] = '1';
        }
        else if (input[i] =='c') {
            output[i*x +0] = '1';
            output[i*x +1] = '1';
            output[i*x +2] = '0';
            output[i*x +3] = '0';
        }
        else if (input[i] =='d') {
            output[i*x +0] = '1';
            output[i*x +1] = '1';
            output[i*x +2] = '0';
            output[i*x +3] = '1';
        }
        else if (input[i] =='e'){
            output[i*x +0] = '1';
            output[i*x +1] = '1';
            output[i*x +2] = '1';
            output[i*x +3] = '0';
        }
        else if (input[i] =='f') {
            output[i*x +0] = '1';
            output[i*x +1] = '1';
            output[i*x +2] = '1';
            output[i*x +3] = '1';
        }
    }

    output[32] = '\0';
    //printf("strlen of output is %d\n",strlen(output));
    return output;
}


void Driver::process() {
    const char* s = fileString.c_str();
    ifstream infile;
    infile.open(s);
    if(!infile.is_open())printf("This file is invalid! \n \n");
    else{
        printf("File is successfully loaded \n");
        Cache* myCache = new Cache();

        while(true){
            char hex_address[8];
            char r_w;
            infile>>hex_address;
            infile>>r_w;
            if(infile.eof()) break;

            if(r_w=='R'){
                char *bin = hexToBin(&hex_address[0]);
                myCache->read(bin);
            }
            else if(r_w=='W'){
                char *bin = hexToBin(&hex_address[0]);
                myCache->write(bin);
            }
            else {
                printf("Invalid input!\n");
                return;//exit prog
            }

        }//end-while-loop
        fclose(stdin);//close the stdin stream
        myCache->printStatus();
    }//end-else
}
