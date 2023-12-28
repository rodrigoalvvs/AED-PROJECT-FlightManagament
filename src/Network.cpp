//
// Created by admin1 on 19-12-2023.
//

#include <iostream>
#include "../include/Network.h"

Network::Network() {
    this->airportSet.clear();
    this->airlineMap.clear();
    this->flightCount = 0;
}

const std::unordered_map<std::string, std::shared_ptr<AirportVertex>>& Network::getAirportSet() const {
    return this->airportSet;
}


const std::unordered_map<std::string, std::shared_ptr<Airline>>& Network::getAirlineMap() const {
    return this->airlineMap;
}

bool Network::addAirline(std::shared_ptr<Airline> airline) {
    this->airlineMap.insert(std::pair<std::string, std::shared_ptr<Airline>  >(airline->getCode(), airline));
    return false;
}

bool Network::addAirport(std::shared_ptr<AirportVertex> airport) {
    if(this->airportSet.find(airport->getAirportCode()) != this->airportSet.end()){return false;}
    this->airportSet.emplace(airport->getAirportCode(), airport);
    return true;
}

void Network::addFlight(const std::string &source, const std::string &target, const std::string &airline) {
    std::shared_ptr<AirportVertex> airportSource = this->findVertex(source);
    std::shared_ptr<AirportVertex> airportTarget = this->findVertex(target);
    if(airportSource != nullptr && airportTarget != nullptr){
        airportSource->addFlight(airline, airportTarget);
        this->increaseFlightCount();
    }
}

std::shared_ptr<AirportVertex> Network::findVertex(const std::string &info) {
    if(this->airportSet.find(info) != this->airportSet.end()){
        return this->airportSet[info];
    }
    return nullptr;
}



int Network::getFlightCount() const {
    return this->flightCount;
}

void Network::increaseFlightCount() {
    this->flightCount += 1;
}

int Network::outDegree(const std::string &airportCode) const {
    if(this->airportSet.find(airportCode) == this->airportSet.end()) return -1;
    return this->airportSet.find(airportCode)->second->getFlights().size();
}

const std::vector<Flight> &Network::getFlightsFromAirport(const std::string &airportCode) const{
    if(this->airportSet.find(airportCode) == this->airportSet.end()) return {};
    return this->airportSet.find(airportCode)->second->getFlights();
}

std::vector<std::shared_ptr<AirportVertex>> Network::airportsInCity(const std::string &city) {
    std::vector<std::shared_ptr<AirportVertex>> airportsVector;
    for(std::pair<std::string, std::shared_ptr<AirportVertex>> airportVertex: this->airportSet){
        if(airportVertex.second->getCity() == city){
            airportsVector.push_back(airportVertex.second);
        }
    }
    return airportsVector;
}

void Network::resetFlags() {
    for(std::pair<std::string, std::shared_ptr<AirportVertex>> airportVertex: this->airportSet){
        airportVertex.second->setVisited(false);
    }
}

std::shared_ptr<AirportVertex> Network::findAirportByName(const std::string &name) {
    for(const auto& pair: this->airportSet){
        if(pair.second->getName() == name){
            return pair.second;
        }
    }
    return nullptr;
}
