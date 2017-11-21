#include "driver.h"
using namespace std;

int main(int argc, char* argv[]) {
    char* fileName = argv[argc-1];
//    string file = "C:\\Users\\qiaoz\\Desktop\\UCI\\250P\\HW\\HW4\\Test\\cache-simulator-master\\test1.txt";
    Driver* mydriver = new Driver(fileName);
    mydriver->process();
    delete(mydriver);
    return 0;
}