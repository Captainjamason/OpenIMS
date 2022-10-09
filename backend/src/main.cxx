#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>

#include "startup.h"

IMStart::config conf;

int main() {
    std::cout << "Welcome to OpenIMS.\n";
    std::cout << "Checking for configuration files...\n";
    if(conf.confCheck() == true) {
        std::cout << "Configuration files found. Continuing...\n";
        conf.loadConf();
    } else {
        conf.buildConf();
        conf.loadConf();
    }
}