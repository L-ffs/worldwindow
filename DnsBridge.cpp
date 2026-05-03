#include "DnsBridge.h"
#include <string>
#include <iostream>
#include <fstream>



DnsBridge::DnsBridge(std::string fileName) {
    this->getData(fileName);
}

DnsBridge::~DnsBridge()
{
}

void DnsBridge::getData(std::string fileName) {

    std::ifstream file(fileName);
    if (file.is_open()) {

        std::string line;
        while (std::getline(file, line)) {
            this->valueSwitch(line);
        }
        file.close();

    } else {
        std::cerr << "Unable to open file";
    }
}

void DnsBridge::valueSwitch(std::string fileFild) {
    
    if (fileFild.find("token=") != std::string::npos) {
        this->token = fileFild.substr(fileFild.find("=") + 1);

    } else if (fileFild.find("url=") != std::string::npos) {
        this->url = fileFild.substr(fileFild.find("=") + 1);

    } else if (fileFild.find("subdomain=") != std::string::npos) {
        this->subdomain = fileFild.substr(fileFild.find("=") + 1);
    }
}

std::string DnsBridge::geturl() {
    return this->url;
}

std::string DnsBridge::gettoken() {
    return this->token;
}

std::string DnsBridge::getsubdomain() {
    return this->subdomain;
}
