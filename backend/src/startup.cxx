#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include "startup.h"
using namespace IMStart;

bool config::confCheck() {
    std::ifstream mainConf;
    mainConf.open("./config/main.json");
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

bool exampleCheck() {

}

int genFiles() {
    std::ofstream mainConf;
    std::ifstream exampleMainConf;
    std::string data;

    mainConf.open("config/main.json");
    exampleMainConf.open("Examples/main.json");

    while(getline(exampleMainConf, data)) {
        mainConf << data << std::endl;
    }

    exampleMainConf.close();
    mainConf.close();
}

int config::buildConf() {
    std::string confDir = "config/";
    struct stat info;
    if(stat(confDir.c_str(), &info) != 0) {
        if(mkdir(confDir.c_str()) != 0) {
            std::cout << "ERROR: Could not create folder.\n";
            return 1;
        } else {
            std::cout << "Generating configuration files...\n";
            if(genFiles() != 0) {
                std::cout << "ERROR: Could not generate configuration files.\n";
                return 1;
            } else {
                std::cout << "Default configurations generated...\n";
                return 0;
            } 
        }
    } else {
        std::cout << "Generating configuration files...\n";
        if(genFiles() != 0) {
            std::cout << "ERROR: Could not generate configuration files.\n";
            return 1;
        } else {
            std::cout << "Default configurations generated...\n";
            return 0;
        }  
    }
}

int config::loadConf() {
    
}