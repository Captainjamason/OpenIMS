#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>

#include "startup.h"
using namespace IMStart;

bool config::confCheck() {
    std::ifstream mainConf;
    mainConf.open("config.json");
    if(mainConf.is_open()) {
        if(mainConf.fail()){
            return false;
        } else {
            return true;
        }
    } else {
        return false;
    }
}

int config::buildConf() {
    
}

int config::loadConf() {
    
}