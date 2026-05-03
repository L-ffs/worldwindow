#include <iostream>
#include <string>
#include "DnsBridge.h"

using namespace std;


int main() {
    DnsBridge bridge("data");
    std::cout << "URL: " << bridge.geturl() << std::endl;
    std::cout << "Token: " << bridge.gettoken() << std::endl;
    std::cout << "Subdomain: " << bridge.getsubdomain() << std::endl;
    return 0;
}