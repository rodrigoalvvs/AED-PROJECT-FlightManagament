//
// Created by admin1 on 19-12-2023.
//


#include <unordered_set>
#include "../include/AirportVertex.h"


const std::vector<Flight> &AirportVertex::getFlights() const {
    return this->flights;
}



void AirportVertex::setFlights(const std::vector<Flight> &flights_) {
    this->flights = flights_;
}

AirportVertex::AirportVertex(std::shared_ptr<Airport> airport_) {
    this->airport = airport_;
}

void AirportVertex::addFlight(const std::string &target, std::shared_ptr<AirportVertex> airline) {
    this->flights.emplace_back(airline, target);
}

const std::string &AirportVertex::getAirportCode() const {
    return this->airport->getCode();
}

const std::string &AirportVertex::getCity() const {
    return this->airport->getCity();
}

void AirportVertex::setVisited(bool visited_) {
    this->visited = visited_;
}

bool AirportVertex::isVisited() const {
    return this->visited;
}

int AirportVertex::getDistinctCountries() {
    std::unordered_set<std::string> countries;
    for(Flight flight: this->flights){
        countries.insert(flight.getDestination()->getCountry());
    }
    return static_cast<int>(countries.size());
}

const std::string &AirportVertex::getCountry() const {
    return this->airport->getCountry();
}




