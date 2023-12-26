//
// Created by admin1 on 19-12-2023.
//

#ifndef FLIGHTMANAGEMENT_AIRPORTVERTEX_H
#define FLIGHTMANAGEMENT_AIRPORTVERTEX_H

#include <string>
#include <vector>


#include "Flight.h"
#include "Airport.h"


class AirportVertex{
private:
    std::shared_ptr<Airport> airport;
    std::vector<Flight> flights;
    int low;
    int num;
    bool visited;
public:
    // Constructor
    AirportVertex(std::shared_ptr<Airport> airport_);

    // Getter methods
    const std::vector<Flight> &getFlights() const;
    const std::string& getAirportCode() const;
    const std::string& getCity() const;
    const std::string& getCountry() const;
    void setLow(int low);
    void setNum(int num_);

    // Setter methods
    void setFlights(const std::vector<Flight> &flights_);
    void addFlight(const std::string& target, std::shared_ptr<AirportVertex> airline);
    int getLow() const;
    int getNum() const;

    void setVisited(bool visited);
    bool isVisited() const;

    int getDistinctCountries();

};

#endif //FLIGHTMANAGEMENT_AIRPORTVERTEX_H
