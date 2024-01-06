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

/**
 * @class AirportVertex
 * @brief Represents a vertex in the flight network associated with an airport.
 */
class AirportVertex{
private:
    Airport airport; /**< The airport associated with the vertex. */
    std::vector<Flight> flights; /**< The flights associated with the vertex. */
    bool visited; /**< Flag indicating whether the vertex has been visited. */
    int num; /**< Numerical value associated with the vertex. */
    int low; /**< Low value associated with the vertex. */

public:
    /**
     * @brief Default constructor for the AirportVertex class.
     * @param airport_ The airport to associate with the vertex.
     */
    AirportVertex(Airport airport_);

    /**
     * @brief Gets the flights associated with the vertex.
     * @return A constant reference to the vector of flights.
     */
    const std::vector<Flight> &getFlights() const;

    /**
     * @brief Sets the flights associated with the vertex.
     * @param flights_ The vector of flights to set.
     */
    void setFlights(const std::vector<Flight> &flights_);

    /**
     * @brief Adds a flight to the vertex.
     * @param airline The destination airport vertex.
     * @param target The target of the flight.
     */
    void addFlight(std::shared_ptr<AirportVertex> target, const std::string &airline);

    /**
     * @brief Gets the airport code associated with the vertex.
     * @return A constant reference to the airport code.
     */
    const std::string &getAirportCode() const;

    /**
     * @brief Gets the city associated with the vertex.
     * @return A constant reference to the city.
     */
    const std::string &getCity() const;

    /**
     * @brief Sets the visited flag for the vertex.
     * @param visited_ The value to set for the visited flag.
     */
    void setVisited(bool visited_);

    /**
     * @brief Checks if the vertex has been visited.
     * @return True if the vertex has been visited, false otherwise.
     */
    bool isVisited() const;

    /**
     * @brief Gets the number of distinct countries connected to the vertex through flights.
     * @return The number of distinct countries.
     */
    int getDistinctCountries();

    /**
     * @brief Gets the set of distinct countries connected to the vertex through flights.
     * @return The set of distinct countries.
     */
    std::unordered_set<std::string> getDistinctCountriesSet();

    /**
     * @brief Gets the country associated with the vertex.
     * @return A constant reference to the country.
     */
    const std::string &getCountry() const;

    /**
     * @brief Sets the low value for the vertex.
     * @param low_ The value to set for the low value.
     */
    void setLow(int low_);

    /**
     * @brief Sets the numerical value for the vertex.
     * @param num_ The value to set for the numerical value.
     */
    void setNum(int num_);

    /**
     * @brief Gets the low value associated with the vertex.
     * @return The low value.
     */
    int getLow() const;

    /**
     * @brief Gets the numerical value associated with the vertex.
     * @return The numerical value.
     */
    int getNum() const;

    /**
     * @brief Gets the name associated with the vertex.
     * @return A constant reference to the name.
     */
    const std::string &getName() const;

    /**
     * @brief Gets the latitude associated with the vertex.
     * @return The latitude value.
     */
    double getLatitude() const;

    /**
     * @brief Gets the longitude associated with the vertex.
     * @return The longitude value.
     */
    double getLongitude() const;

};

#endif //FLIGHTMANAGEMENT_AIRPORTVERTEX_H
