//
// Created by admin1 on 19-12-2023.
//

#include <iostream>
#include "../include/NetworkController.h"
#include <chrono>
#include <unordered_set>
#include <stack>
#include <set>

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
    return static_cast<int>(this->network.getAirportSet().size());
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
    for(const std::shared_ptr<AirportVertex>& airport: airportsInCity){
        count += static_cast<int>(airport->getFlights().size());
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


void NetworkController::maximumTripDFS(std::shared_ptr<AirportVertex> vertex,
                                       std::vector<std::string> &list) {
    vertex->setVisited(true);
    list.emplace_back(vertex->getAirportCode());

    for(Flight flight: vertex->getFlights()){
        if(!flight.getDestination()->isVisited()){
            maximumTripDFS(flight.getDestination(), list);
        }
    }
}

std::vector<std::string> NetworkController::getMaximumTrip() {
    std::vector<std::string> result;
    this->network.resetFlags();

    for(std::pair<std::string, std::shared_ptr<AirportVertex>> vertex: this->network.getAirportSet()){
        std::vector<std::string> currentTrip;

        if(!vertex.second->isVisited()){
            this->maximumTripDFS(vertex.second, currentTrip);
        }
        if(currentTrip.size() > result.size()){
            result = currentTrip;
        }
        currentTrip.clear();
    }
    return result;
}


int NetworkController::airportsReachable(const std::string &airportCode) {
    return static_cast<int>( this->reachable(airportCode).size()) ;
}

int NetworkController::citiesReachable(const std::string &airportCode) {
    std::vector<std::shared_ptr<AirportVertex>> reachable = this->reachable(airportCode);
    std::unordered_set<std::string> cities;
    for(const std::shared_ptr<AirportVertex>& vertex: reachable){
        cities.insert(vertex->getCity());
    }
    return static_cast<int>(cities.size());
}

int NetworkController::countriesReachable(const std::string &airportCode) {
    std::vector<std::shared_ptr<AirportVertex>> reachable = this->reachable(airportCode);
    std::unordered_set<std::string> countries;
    for(const std::shared_ptr<AirportVertex>& vertex: reachable){
        countries.insert(vertex->getCountry());
    }
    return static_cast<int>(countries.size());
}

std::vector<std::shared_ptr<AirportVertex>> NetworkController::reachable(const std::string &airportCode) {
    std::vector<std::shared_ptr<AirportVertex>> result;
    this->network.resetFlags();
    std::shared_ptr<AirportVertex> source = this->network.findVertex(airportCode);
    if(source == nullptr) return {};
    this->reachableDFS(source, result);
    return result;
}

void NetworkController::reachableDFS(std::shared_ptr<AirportVertex> vertex ,std::vector<std::shared_ptr<AirportVertex>> &reachable) {
    vertex->setVisited(true);
    reachable.push_back(vertex);

    for(Flight flight: vertex->getFlights()){
        if(!flight.getDestination()->isVisited()){
            this->reachableDFS(flight.getDestination(), reachable);
        }
    }
}



void NetworkController::reachableWithNStopsDFS(std::shared_ptr<AirportVertex> vertex, int &counter, int nStops, std::vector<std::shared_ptr<AirportVertex>>& reachable) {
    vertex->setVisited(true);
    reachable.push_back(vertex);

    if(nStops >= 0){
        for(Flight flight: vertex->getFlights()){
            if(!flight.getDestination()->isVisited()){
                counter += 1;
                this->reachableWithNStopsDFS(flight.getDestination(), counter, nStops - 1, reachable);
            }
        }
    }


}

std::vector<std::shared_ptr<AirportVertex>> NetworkController::reachableWithNStops(const std::string &airportCode, int nStops) {
    this->network.resetFlags();
    std::shared_ptr<AirportVertex> source = this->network.findVertex(airportCode);
    if(source == nullptr) return {};

    int counter = 0;
    std::vector<std::shared_ptr<AirportVertex>> reachable;
    this->reachableWithNStopsDFS(source, counter, nStops, reachable);
    return reachable;
}


int NetworkController::airportsReachableNStops(const std::string &airportCode, int nStops) {
    return static_cast<int>(this->reachableWithNStops(airportCode, nStops).size());
}

int NetworkController::citiesReachableNStops(const std::string &airportCode, int nStops) {
    std::vector<std::shared_ptr<AirportVertex>> reachable = this->reachableWithNStops(airportCode, nStops);
    std::unordered_set<std::string> cities;
    for(const std::shared_ptr<AirportVertex>& vertex: reachable){
        cities.insert(vertex->getCity());
    }
    return static_cast<int>(cities.size());
}

int NetworkController::countriesReachableNStops(const std::string &airportCode, int nStops) {
    std::vector<std::shared_ptr<AirportVertex>> reachable = this->reachableWithNStops(airportCode, nStops);
    std::unordered_set<std::string> countries;
    for(const std::shared_ptr<AirportVertex>& vertex: reachable){
        countries.insert(vertex->getCountry());
    }
    return static_cast<int>(countries.size());
}

std::vector<std::pair<std::string, int>> NetworkController::topAirports(int k){
    std::priority_queue<std::pair<int, std::string>> maxHeap;
    for(std::pair<std::string, std::shared_ptr<AirportVertex>> vertex: this->network.getAirportSet()){
        maxHeap.emplace(vertex.second->getFlights().size(),vertex.first);
    }

    std::vector<std::pair<std::string, int>> result;
    while(!maxHeap.empty() && k > 0){
        result.emplace_back(maxHeap.top().second, maxHeap.top().first);
        maxHeap.pop();
        k--;
    }
    return result;
}

std::unordered_set<std::string> NetworkController::articulationAirports() {
    std::unordered_set<std::string> res;
    std::stack<std::string> s;
    int i = 0;
    this->network.resetFlags();

    for(const std::pair<std::string, std::shared_ptr<AirportVertex>>& v : this->network.getAirportSet()){
        if(!v.second->isVisited()){
            dfs_art(v.second, s, res, i);
        }
    }
    return res;
}

void NetworkController::dfs_art(std::shared_ptr<AirportVertex> vertex, std::stack<std::string> &s,
                                std::unordered_set<std::string> &result, int &i) {
    int childCount = 0;
    i++;
    vertex->setNum(i);
    vertex->setLow(i);
    vertex->setVisited(true);
    s.push(vertex->getAirportCode());
    for(auto edge : vertex->getFlights()){
        auto w = edge.getDestination();
        if(!w->isVisited()){
            childCount++;
            dfs_art( w, s, result, i);
            vertex->setLow(std::min(vertex->getLow(), w->getLow()));
            if(w->getLow() >= vertex->getNum() && vertex->getNum() != 1){
                result.insert(vertex->getAirportCode());
            }
        }
        else if(this->inStack(s, w->getAirportCode())){
            vertex->setLow(std::min(vertex->getLow(), w->getNum()));
        }
    }
    s.pop();
    if(vertex->getNum() == 1 && childCount > 1){
        result.insert(vertex->getAirportCode());
    }
}


template<class T>
bool NetworkController::inStack(std::stack<T> stack, T info) {
    while(!stack.empty()){
        if(info == stack.top()) return true;
        stack.pop();
    }
    return false;
}


std::shared_ptr<AirportVertex> NetworkController::findAirportByName(const std::string &name) {
    for(const auto& pair: this->network.getAirportSet()){
        if(pair.second->getName() == name) return pair.second;
    }
    return nullptr;
}

std::vector<std::shared_ptr<AirportVertex>> NetworkController::findAirportsInCity(const std::string &city) {
    std::vector<std::shared_ptr<AirportVertex>> airportsInCity;
    for(const auto& pair: this->network.getAirportSet()){
        if(pair.second->getCity() == city) airportsInCity.push_back(pair.second);
    }
    return airportsInCity;
}

std::vector<std::pair<double, std::shared_ptr<AirportVertex>>>
NetworkController::findAirportsNearPoint(double latitude, double longitude, int firstN) {
    std::vector<std::pair<double, std::shared_ptr<AirportVertex>>> result;


    auto cmp = [](std::pair<double , std::shared_ptr<AirportVertex>> airportA, std::pair<double , std::shared_ptr<AirportVertex>> airportB) -> bool{
        return airportA.first <= airportB.first;
    };

    std::set<std::pair<double, std::shared_ptr<AirportVertex>> , decltype(cmp)> nearbyAirports(cmp);

    for(const auto& pair: this->network.getAirportSet()){
        nearbyAirports.emplace(this->computeDistance(latitude, longitude, pair.second), pair.second);
    }

    int counter = 0;
    for(auto itr = nearbyAirports.begin(); itr != nearbyAirports.end() && (counter++ < firstN); itr++){
        result.push_back(*itr);
    }
    return result;
}

double NetworkController::computeDistance(double latitude, double longitude, std::shared_ptr<AirportVertex> second) {
    double R = 6371000;

    double phi_1 = latitude * (M_PI / 180.0);
    double phi_2 = second->getLatitude() * (M_PI / 180.0);

    double delta_phi = (second->getLatitude() - latitude) * (M_PI / 180.0);
    double delta_lambda = (second->getLongitude() - longitude) * (M_PI / 180.0);

    double a = std::pow(std::sin(delta_phi / 2.0), 2) + std::cos(phi_1) * std::cos(phi_2) * std::pow(std::sin(delta_lambda / 2.0),2);

    double c = 2 * std::atan2(std::sqrt(a), std::sqrt(1 - a));

    double km = std::round(R * c) / 1000.0;
    return km;
}


std::vector<std::vector<std::pair<std::shared_ptr<AirportVertex>, std::string>>> NetworkController::findBestFlightOption(std::shared_ptr<AirportVertex> source, std::shared_ptr<AirportVertex> destination, SearchFilter filter) {

    if(source == nullptr || destination == nullptr || (source == destination)) return {};
    this->network.resetFlags();

    std::vector<std::vector<std::pair<std::shared_ptr<AirportVertex>, std::string>>> result;
    std::queue<std::vector<std::pair<std::shared_ptr<AirportVertex>, std::string>>> q;


    // Push root element
    q.push({{source, ""}});
    source->setVisited(true);

    while(!q.empty()){
        // Root path
        std::vector<std::pair<std::shared_ptr<AirportVertex>, std::string>> rootPath = q.front();
        q.pop();

        std::shared_ptr<AirportVertex> lastVertexVisited = rootPath.back().first;


        for(Flight flight: lastVertexVisited->getFlights()){

            if(!flight.getDestination()->isVisited()){
                std::vector<std::pair<std::shared_ptr<AirportVertex>, std::string>> childPath = rootPath;
                childPath.emplace_back(flight.getDestination(), flight.getAirlineCode());

                if(flight.getDestination() == destination){
                    if((result.empty() || childPath.size() <= result.front().size())  && this->checkFilters(childPath, filter)){
                        result.push_back(childPath);
                    }
                    continue;
                }

                std::vector<std::pair<std::shared_ptr<AirportVertex>, std::string>> newPath = childPath;
                q.push(newPath);
                flight.getDestination()->setVisited(true);
            }
        }
    }

    return result;
}

std::shared_ptr<AirportVertex> NetworkController::findAirportByCode(const std::string &code) {
    return this->network.findVertex(code);
}

bool NetworkController::inSet(std::unordered_set<std::string> set, const std::string & value) {
    for(const std::string& str: set){
        if(value == str) return true;
    }
    return false;
}

bool NetworkController::checkFilters(std::vector<std::pair<std::shared_ptr<AirportVertex>, std::string>> path,
                                     SearchFilter filter) {
    std::unordered_set<std::string> airlinesUsed;
    bool invalidRoute = false;

    for(const std::pair<std::shared_ptr<AirportVertex>, std::string>& route: path){
        // root element
        if(route.second.empty()) continue;

        if(!this->inSet(filter.airlinesToUse, route.second) && filter.filterAirlines) invalidRoute = true;
        airlinesUsed.insert(route.second);
    }

    bool validNumber = airlinesUsed.size() <= filter.limitAirlines || filter.limitAirlines == -1;
    return validNumber && !invalidRoute;
}


















