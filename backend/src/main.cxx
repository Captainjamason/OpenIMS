#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>

#include "startup.h"

IMStart::config conf;

int main() {
    if(conf.confCheck() == true) {
        std::cout << "Test";
    } else {
        std::cout << "Test failed";
    }
}