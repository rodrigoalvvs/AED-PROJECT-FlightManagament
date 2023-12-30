//
// Created by admin1 on 19-12-2023.
//

#ifndef FLIGHTMANAGEMENT_AIRPORTVERTEX_H
#define FLIGHTMANAGEMENT_AIRPORTVERTEX_H

#include <string>
#include <vector>
#include <unordered_set>


#include "Flight.h"
#include "Airport.h"


class AirportVertex{
private:
    Airport airport;
    std::vector<Flight> flights;
    int low;
    int num;
    bool visited;
public:
    // Constructor
    AirportVertex(Airport);

    // Getter methods
    const  std::vector<Flight> &getFlights() const;
    const std::string& getAirportCode() const;
    const std::string& getCity() const;
    const std::string& getCountry() const;
    const std::string& getName() const;
    double getLatitude() const;
    double getLongitude() const;
    void setLow(int low);
    void setNum(int num_);

    // Setter methods
    void setFlights(const std::vector<Flight>&);
    void addFlight(std::shared_ptr<AirportVertex> airline, const std::string& target);
    int getLow() const;
    int getNum() const;

    void setVisited(bool visited);
    bool isVisited() const;

    int getDistinctCountries();
    std::unordered_set<std::string> getDistinctCountriesSet();

};

#endif //FLIGHTMANAGEMENT_AIRPORTVERTEX_H
