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

int genFile(std::string confPath, std::string examplePath) {
    std::ofstream conf;
    std::ifstream exampleConf;
    std::string data;

    conf.open(confPath);
    exampleConf.open(examplePath);

    while(getline(exampleConf, data)) {
        conf << data << std::endl;
    }

    exampleConf.close();
    conf.close();
    return 0;
};

bool config::check(std::string path) {
    std::ifstream conf;
    conf.open(path);
    if(conf.is_open()) {
        if(conf.fail()){
            return false;
        } else {
            if(verifyConf(path) == false) {
                std::cout << path << " does not exist or is incompatible.\n";
                return false;
            } else {
               return true;
            }
        }
    } else {
        std::cout << "Could not open " << path << std::endl;
        return false;
    }
}

int config::buildConf() {
    struct stat info;
    std::string confDir = "config/";

    // Folder check
    if(stat(confDir.c_str(), &info) != 0) {
        if(mkdir(confDir.c_str()) != 0) {
            std::cout << "ERROR: Could not create folder.\n";
            return 1;
        } else {
            // If folder was successfully created, then generate configuration files in order.
            std::cout << "Generating configuration files...\n";
            std::cout << "Generating main configuration file...\n";
            if(genFile("config/main.json", "Examples/main.json") != 0) {
                std::cout << "ERROR: Could not generate main configuration file.\n";
                return 1;
            } else {
                 std::cout << "Created main.json\n"; 
            }
            
            std::cout << "Generating module configuration file...\n";
            if(genFile("config/modules.json", "Examples/modules.json") != 0) {
                std::cout << "ERROR: Could not generate module.json.\n";
                return 1;
            } else {
                std::cout << "Created modules.json\n";
            }
        }
    } else {
        // TO-DO: Optimize code so its not repeating here.
        // If folder exists alraedy then generate main configuration file,
        std::cout << "Generating configuration files...\n";
            std::cout << "Generating main configuration file...\n";
            if(genFile("config/main.json", "Examples/main.json") != 0) {
                std::cout << "ERROR: Could not generate main configuration file.\n";
                return 1;
            } else {
                 std::cout << "Created main.json\n"; 
            }
            
            std::cout << "Generating module configuration file...\n";
            if(genFile("config/modules.json", "Examples/modules.json") != 0) {
                std::cout << "ERROR: Could not generate module.json.\n";
                return 1;
            } else {
                std::cout << "Created modules.json\n";
            }
    }
}

int config::loadConfigs() {
    
}