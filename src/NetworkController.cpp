//
// Created by admin1 on 19-12-2023.
//

#include <iostream>
#include "../include/NetworkController.h"
#include <chrono>
#include <unordered_set>

NetworkController::NetworkController() {
    Network network1;
    this->network = network1;
    this->loadData();
}

void NetworkController::loadData() {
    this->loadAirports();
    this->loadAirlines();
    this->loadFlights();
}

void NetworkController::loadAirports() {
    std::ifstream in("../data/airports.csv");
    std::string line;
    std::getline(in, line);

    while(std::getline(in, line)){
        if(line.find(',') == std::string::npos) continue;
        if(line.find('\r') != std::string::npos) line.pop_back();

        std::istringstream stream(line);
        std::string code, name, city, country, latitude, longitude;

        std::getline(stream, code, ',');
        std::getline(stream, name, ',');
        std::getline(stream, city, ',');
        std::getline(stream, country, ',');
        std::getline(stream, latitude, ',');
        std::getline(stream, longitude, ',');
        try{
            Airport current(code, name, city, country, std::stod(latitude), std::stod(longitude));
            AirportVertex vertex(std::make_shared<Airport>(current));
            this->network.addAirport(std::make_shared<AirportVertex>(vertex));
        } catch(const std::invalid_argument & e){
            std::cout << "Invalid argument"<< std::endl;
            continue;
        }

    }

}

void NetworkController::loadAirlines() {
    std::ifstream in("../data/airlines.csv");
    std::string line;
    std::getline(in, line);

    while(std::getline(in, line)){
        if(line.find(',') == std::string::npos) continue;
        if(line.find('\r') != std::string::npos) line.pop_back();

        std::istringstream stream(line);
        std::string code, name, callsign, country;

        std::getline(stream, code, ',');
        std::getline(stream, name, ',');
        std::getline(stream, callsign, ',');
        std::getline(stream, country, ',');

        Airline airline(code, name, callsign, country);

        this->network.addAirline(std::make_shared<Airline>(airline));

    }
}

void NetworkController::loadFlights() {
    std::ifstream in("../data/flights.csv");
    std::string line;
    std::getline(in, line);

    while(std::getline(in, line)){
        if(line.find(',') == std::string::npos) continue;
        if(line.find('\r') != std::string::npos) line.pop_back();

        std::istringstream stream(line);
        std::string source, target, airline;

        std::getline(stream, source, ',');
        std::getline(stream, target, ',');
        std::getline(stream, airline, ',');

        this->network.addFlight(source, target, airline);
    }
}

int NetworkController::airportCount() {
    return this->network.getAirportSet().size();
}

int NetworkController::flightCount() {
    return this->network.getFlightCount();
}

int NetworkController::flightCountFromAirport(const std::string &airportCode) const {
    return this->network.outDegree(airportCode);
}

int NetworkController::distinctAirlinesInAirport(const std::string &airportCode) const {
    std::vector<Flight> flights = this->network.getFlightsFromAirport(airportCode);
    std::unordered_set<std::string> distinctAirlines;
    for(Flight flight_: flights){
        distinctAirlines.insert(flight_.getAirlineCode());
    }

    return static_cast<int>(distinctAirlines.size());
}

int NetworkController::flightsPerCity(const std::string &city) {
    std::vector<std::shared_ptr<AirportVertex>> airportsInCity = this->network.airportsInCity(city);
    int count = 0;
    for(std::shared_ptr<AirportVertex> airport: airportsInCity){
        count += airport->getFlights().size();
    }
    return count;
}

void NetworkController::airlineDFS(std::shared_ptr<AirportVertex> vertex, int& counter, const std::string& match){
    vertex->setVisited(true);

    for(Flight flight: vertex->getFlights()){
        if(flight.getAirlineCode() == match){
            counter += 1;
        }
        if(!flight.getDestination()->isVisited()){
            this->airlineDFS(flight.getDestination(), counter, match);
        }
    }
}

int NetworkController::flightsPerAirline(const std::string &airline) {
    int counter = 0;
    this->network.resetFlags();

    for(std::pair<std::string, std::shared_ptr<AirportVertex>> vertex: this->network.getAirportSet()){
        if(!vertex.second->isVisited()){
            this->airlineDFS(vertex.second, counter, airline);
        }
    }

    return counter;
}

int NetworkController::distinctCountriesFromAirport(const std::string &airportCode) {
    std::shared_ptr<AirportVertex> airport = this->network.findVertex(airportCode);
    if(airport == nullptr) return -1;
    return airport->getDistinctCountries();
}

void NetworkController::distinctDFS(std::shared_ptr<AirportVertex> vertex, int &counter, const std::string &match) {
    vertex->setVisited(true);

    if(vertex->getCity() == match){
        counter += this->distinctCountriesFromAirport(vertex->getAirportCode());
    }

    for(Flight flight: vertex->getFlights()){
        if(!flight.getDestination()->isVisited()){
            this->distinctDFS(flight.getDestination(), counter, match);
        }
    }

}

int NetworkController::distinctCountriesFromCity(const std::string &city) {
    this->network.resetFlags();
    int counter = 0;

    for(std::pair<std::string, std::shared_ptr<AirportVertex>> vertex: this->network.getAirportSet()){
        if(!vertex.second->isVisited()){
            this->distinctDFS(vertex.second, counter, city);
        }
    }
    return counter;
}

void NetworkController::reachableDFS(std::shared_ptr<AirportVertex> vertex, int &counter, int nStops) {
    vertex->setVisited(true);

    if(nStops >= 0){
        for(Flight flight: vertex->getFlights()){
            if(!flight.getDestination()->isVisited()){
                counter += 1;
                this->reachableDFS(flight.getDestination(), counter, nStops - 1);
            }
        }
    }


}

int NetworkController::reachableWithNStops(const std::string &airportCode, int nStops) {
    this->network.resetFlags();
    std::shared_ptr<AirportVertex> source = this->network.findVertex(airportCode);
    if(source == nullptr) return -1;

    int counter = 0;
    this->reachableDFS(source, counter, nStops);
    return counter;
}













