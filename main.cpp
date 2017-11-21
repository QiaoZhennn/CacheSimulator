#include "driver.h"
using namespace std;

int main() {
    string file = "C:\\Users\\qiaoz\\Desktop\\UCI\\250P\\HW\\HW4\\Test\\cache-simulator-master\\test1.txt";
    Driver* mydriver = new Driver(file);
    mydriver->process();
    delete(mydriver);
    return 0;
}