//
// Created by admin1 on 19-12-2023.
//


#include <unordered_set>
#include <utility>
#include "../include/AirportVertex.h"


const  std::vector<Flight>&AirportVertex::getFlights() const {
    return this->flights;
}



void AirportVertex::setFlights(const std::vector<Flight>& flights_) {
    this->flights = flights_;
}

AirportVertex::AirportVertex(Airport airport_) : airport(std::move(airport_)) {
    this->flights.clear();
    this->visited = false;
    this->num = INT16_MIN;
    this->low = INT16_MAX;
}

void AirportVertex::addFlight(std::shared_ptr<AirportVertex> airline, const std::string& target) {
    this->flights.emplace_back(airline, target);
}

const std::string &AirportVertex::getAirportCode() const {
    return this->airport.getCode();
}

const std::string &AirportVertex::getCity() const {
    return this->airport.getCity();
}

void AirportVertex::setVisited(bool visited_) {
    this->visited = visited_;
}

bool AirportVertex::isVisited() const {
    return this->visited;
}

int AirportVertex::getDistinctCountries() {
    std::unordered_set<std::string> countries;
    countries.insert(this->getCountry());
    for(Flight flight: this->flights){
        countries.insert(flight.getDestination()->getCountry());
    }
    return static_cast<int>(countries.size() - 1);
}

std::unordered_set<std::string> AirportVertex::getDistinctCountriesSet(){
    std::unordered_set<std::string> countries;
    for(Flight flight: this->flights){
        countries.insert(flight.getDestination()->getCountry());
    }
    return countries;
}


const std::string &AirportVertex::getCountry() const {
    return this->airport.getCountry();
}

void AirportVertex::setLow(int low_) {
    this->low = low_;
}

void AirportVertex::setNum(int num_) {
    this->num = num_;
}

int AirportVertex::getLow() const {
    return this->low;
}

int AirportVertex::getNum() const {
    return this->num;
}

const std::string &AirportVertex::getName() const {
    return this->airport.getName();
}

double AirportVertex::getLatitude() const {
    return this->airport.getLatitude();
}

double AirportVertex::getLongitude() const {
    return this->airport.getLongitude();
}





