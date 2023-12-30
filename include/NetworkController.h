//
// Created by admin1 on 19-12-2023.
//

#ifndef FLIGHTMANAGEMENT_NETWORKCONTROLLER_H
#define FLIGHTMANAGEMENT_NETWORKCONTROLLER_H

#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <stack>
#include <cmath>

#include "Network.h"
#include "AirportVertex.h"
#include "Airline.h"
#include "Flight.h"


struct SearchFilter{
    int limitAirlines = -1; // -1 to use as many as necessary
    bool filterAirlines = false; // false to not filter the airlines
    bool filterCities = false;
    std::unordered_set<std::string> airlinesToUse;
    std::unordered_set<std::string> citiesToStop;
};


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
    int countDistinctCountries(const std::vector<std::shared_ptr<AirportVertex>>& airports);

    // 3.v
    int airportsReachable(const std::string& airportCode);
    int citiesReachable(const std::string& airportCode);
    int countriesReachable(const std::string& airportCode);
    std::vector<std::shared_ptr<AirportVertex>> reachable(const std::string& airportCode);
    void reachableDFS(std::shared_ptr<AirportVertex> vertex, std::vector<std::shared_ptr<AirportVertex>>& reachable);


    // 3.vi
    int airportsReachableNStops(const std::string& airportCode, int nStops);
    int citiesReachableNStops(const std::string& airportCode, int nStops);
    int countriesReachableNStops(const std::string& airportCode, int nStops);
    std::vector<std::shared_ptr<AirportVertex>> reachableWithNStops(const std::string& airportCode, int nStops);
    void reachableWithNStopsDFS(std::shared_ptr<AirportVertex> vertex, int& counter, int nStops, std::vector<std::shared_ptr<AirportVertex>>& reachable);

    // 3.vii
    std::pair<std::vector<std::pair<std::string, std::string>>, int> getLongestTripWithDistance();

    // 3.viii
    std::vector<std::pair<std::string, int>> topAirports(int k);

    // 3. ix (Articulation points)
    std::unordered_set<std::string> articulationAirports();
    void dfs_art(std::shared_ptr<AirportVertex> vertex, std::stack<std::string>& s, std::unordered_set<std::string>& result, int& i);

    template<class T>
    bool inStack(std::stack<T> stack, T info);


    // 4.
    std::shared_ptr<AirportVertex> findAirportByCode(const std::string& code);
    std::shared_ptr<AirportVertex> findAirportByName(const std::string& name);
    std::vector<std::shared_ptr<AirportVertex>> findAirportsInCity(const std::string& city);
    std::vector< std::shared_ptr<AirportVertex>> findAirportsNearPoint(double latitude, double longitude);
    double computeDistance(double latitude, double longitude, std::shared_ptr<AirportVertex>);


    std::vector<std::vector<Flight>> findBestFlightOption(std::shared_ptr<AirportVertex> source, std::shared_ptr<AirportVertex> destination, SearchFilter filter, std::vector<std::vector<Flight>>& result);


    std::vector<std::vector<Flight>> getPaths(const std::vector<std::shared_ptr<AirportVertex>> & sources,const std::vector<std::shared_ptr<AirportVertex>> & destinations,const  SearchFilter& filter);


    // 5.
    bool inSet(std::unordered_set<std::string>, const std::string&);
    bool checkFilters(const std::vector<Flight>& path, SearchFilter filter);

};

#endif //FLIGHTMANAGEMENT_NETWORKCONTROLLER_H
