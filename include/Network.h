//
// Created by admin1 on 19-12-2023.
//

#ifndef FLIGHTMANAGEMENT_NETWORK_H
#define FLIGHTMANAGEMENT_NETWORK_H

#include <vector>
#include <string>
#include <unordered_map>
#include <memory>

#include "AirportVertex.h"
#include "Airline.h"


class Network{
private:
    int flightCount;

    std::unordered_map<std::string, std::shared_ptr<AirportVertex>> airportSet;

    std::unordered_map<std::string, std::shared_ptr<Airline>> airlineMap;
public:
    // Constructor
    Network();

    // getter methods
    const std::unordered_map<std::string, std::shared_ptr<AirportVertex>>& getAirportSet() const;
    const std::unordered_map<std::string, std::shared_ptr<Airline>>& getAirlineMap() const;

    int getFlightCount() const;

    void increaseFlightCount();

    // class methods

    bool addAirport(std::shared_ptr<AirportVertex> airport);
    bool addAirline(std::shared_ptr<Airline> airline);
    void addFlight(const std::string& source, const std::string& target, const std::string& airline);

    void resetFlags();

    int outDegree(const std::string& airportCode) const;

    std::shared_ptr<AirportVertex> findVertex(const std::string &info);

    const std::vector<Flight>& getFlightsFromAirport(const std::string& airportCode) const;

    std::vector<std::shared_ptr<AirportVertex>> airportsInCity(const std::string &basicString);


};

#endif //FLIGHTMANAGEMENT_NETWORK_H
