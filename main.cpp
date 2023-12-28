#include <iostream>
#include "include/NetworkController.h"


int main() {
    NetworkController controller;
    SearchFilter filter;
    for(const auto& vector: controller.findBestFlightOption(controller.findAirportByCode("OPO"), controller.findAirportByCode("CZL"), filter)){

        std::cout << "With " << vector.size() - 2 << " stops" << std:: endl;
        for(auto current: vector){
            std::cout << current.first->getName() << " with " << current.second << ", ";
        }
        std::cout << std::endl;
    }

    return 0;
}
