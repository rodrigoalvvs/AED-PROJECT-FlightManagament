#include <iostream>
#include "include/NetworkController.h"


int main() {

    NetworkController controller;
    for(std::basic_string<char> c: controller.articulationAirports()){
        std::cout << c << std::endl;
    }
    std::cout << controller.articulationAirports().size();
    return 0;
}
