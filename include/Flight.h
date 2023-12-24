//
// Created by admin1 on 19-12-2023.
//

#ifndef FLIGHTMANAGEMENT_FLIGHT_H
#define FLIGHTMANAGEMENT_FLIGHT_H
#include <memory>
#include <string>
class AirportVertex;

class Flight{
private:
    std::string airlineCode;
    std::shared_ptr<AirportVertex> dest;
public:
    //
    Flight(std::shared_ptr<AirportVertex> dest_, const std::string& airCode);


    const std::string& destinationCode();
    const std::string& getAirlineCode();

    std::shared_ptr<AirportVertex> getDestination();

};


#endif //FLIGHTMANAGEMENT_FLIGHT_H
