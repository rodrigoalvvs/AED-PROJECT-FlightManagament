//
// Created by admin1 on 19-12-2023.
//

#ifndef FLIGHTMANAGEMENT_NETWORKCONTROLLER_H
#define FLIGHTMANAGEMENT_NETWORKCONTROLLER_H

#include <fstream>
#include <sstream>
#include <string>

#include "Network.h"
#include "AirportVertex.h"
#include "Airline.h"
#include "Flight.h"

class NetworkController{
private:
    Network network;

public:
    NetworkController();


    void loadData();
    void loadFlights();
    void loadAirports();
    void loadAirlines();


    // 3.i
    int airportCount();
    int flightCount();


    // 3.ii
    int flightCountFromAirport(const std::string& airportCode) const;
    int distinctAirlinesInAirport(const std::string& airportCode) const;

    // 3.iii
    int flightsPerCity(const std::string& city);

    int flightsPerAirline(const std::string& airline);
    void airlineDFS(std::shared_ptr<AirportVertex> vertex, int& counter, const std::string& match);

    // 3.iv
    int distinctCountriesFromAirport(const std::string& airportCode);
    int distinctCountriesFromCity(const std::string& city);
    void distinctDFS(std::shared_ptr<AirportVertex> vertex, int& counter, const std::string& match);

    // 3.v

    // 3.vi
    int reachableWithNStops(const std::string& airportCode, int nStops);
    void reachableDFS(std::shared_ptr<AirportVertex> vertex, int& counter, int nStops);

};

#endif //FLIGHTMANAGEMENT_NETWORKCONTROLLER_H
