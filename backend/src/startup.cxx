#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include "startup.h"
#include <nlohmann/json.hpp>
using namespace IMStart;
using json = nlohmann::json;

bool verifyConf(std::string confPath) {
    std::ifstream conf;
    conf.open(confPath);
    json data = json::parse(conf);
    if(data.contains("ver")) {
        return true;
    } else {
        return false;
    }
}

bool config::confCheck() {
    std::ifstream mainConf;
    mainConf.open("./config/main.json");
    if(mainConf.is_open()) {
        if(mainConf.fail()){
            return false;
        } else {
            if(verifyConf("config/main.json") == false) {
                std::cout << "Main configuration file does not exist or is incompatible. \n";
                return false;
            } else {
                std::cout << "Loaded main configuration file.";
            }
        }
    } else {
        return false;
    }
}

int genMainFile() {
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
    return 0;
}

int config::buildConf() {
    std::string confDir = "config/";
    struct stat info;
    // Folder check
    if(stat(confDir.c_str(), &info) != 0) {
        if(mkdir(confDir.c_str()) != 0) {
            std::cout << "ERROR: Could not create folder.\n";
            return 1;
        } else {
            // If folder was successfully created, then generate configuration files in order.
            std::cout << "Generating configuration files...\n";
            std::cout << "Generating main configuration file...\n";
            if(genMainFile() != 0) {
                std::cout << "ERROR: Could not generate main configuration file.\n";
                return 1;
            } else {
                std::cout << "Main configuration file generated...\n";
                return 0;
            } 
        }
    } else {
        // TO-DO: Optimize code so its not repeating here.
        // If folder exists alraedy then generate main configuration file,
        std::cout << "Generating configuration files...\n";
        if(genMainFile() != 0) {
            std::cout << "ERROR: Could not generate main configuration file.\n";
            return 1;
        } else {
            std::cout << "Main configuration file generated...\n";
            return 0;
        }  
    }
}

int config::loadConf() {
    
}