//
// Created by admin1 on 19-12-2023.
//

#include <utility>

#include "../include/Flight.h"

Flight::Flight(std::shared_ptr<AirportVertex> dest_, const std::string& airCode) {
    this->dest = std::move(dest_);
    this->airlineCode = airCode;
}


const std::string& Flight::getAirlineCode() {
    return this->airlineCode;
}

std::shared_ptr<AirportVertex> Flight::getDestination() {
    return this->dest;
}

