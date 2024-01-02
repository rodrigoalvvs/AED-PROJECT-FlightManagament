//
// Created by admin1 on 19-12-2023.
//

#ifndef FLIGHTMANAGEMENT_FLIGHT_H
#define FLIGHTMANAGEMENT_FLIGHT_H
#include <memory>
#include <string>


// Forward declaration
class AirportVertex;


/**
 * @class Flight
 * @brief Represents a flight between two airports.
 */
class Flight{
private:
    std::string airlineCode; /**< The code of the airline associated with the flight. */
    std::shared_ptr<AirportVertex> dest; /**< The destination airport vertex of the flight. */

public:
    /**
     * @brief Constructor for the Flight class.
     * @param dest_ The destination airport vertex.
     * @param airCode The code of the airline for the flight.
     */
    Flight(std::shared_ptr<AirportVertex> dest_, const std::string &airCode);

    /**
     * @brief Gets the airline code of the flight.
     * @return A constant reference to the airline code.
     */
    const std::string &getAirlineCode();

    /**
     * @brief Gets the destination airport vertex of the flight.
     * @return A shared pointer to the destination airport vertex.
     */
    std::shared_ptr<AirportVertex> getDestination();

};


#endif //FLIGHTMANAGEMENT_FLIGHT_H
