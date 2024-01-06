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

/**
 * @class Network
 * @brief Represents a network of airports and airlines.
 */
class Network {
private:
    int flightCount; /**< The total number of flights in the network. */
    std::unordered_map<std::string, std::shared_ptr<AirportVertex>> airportSet; /**< Map of airport codes to AirportVertex objects. */
    std::unordered_map<std::string, std::shared_ptr<Airline>> airlineMap; /**< Map of airline codes to Airline objects. */
    std::unordered_map<std::string, std::vector<std::shared_ptr<AirportVertex>>> cityMap; //**< Map of cities to airports. */

public:
    /**
     * @brief Constructor for the Network class.
     */
    Network();

    /**
     * @brief Gets the set of airports in the network.
     * @return A constant reference to the map of airport codes to AirportVertex objects.
     */
    const std::unordered_map<std::string, std::shared_ptr<AirportVertex>>& getAirportSet() const;

    /**
     * @brief Gets the set of airlines in the network.
     * @return A constant reference to the map of airline codes to Airline objects.
     */
    const std::unordered_map<std::string, std::shared_ptr<Airline>>& getAirlineMap() const;

    /**
     * @brief Gets the total number of flights in the network.
     * @return The total number of flights.
     */
    int getFlightCount() const;

    /**
     * @brief Increases the total number of flights in the network by 1.
     */
    void increaseFlightCount();

    /**
     * @brief Adds an airport to the network.
     * @param airport The AirportVertex object to add.
     * @return True if the airport was successfully added, false if the airport already exists.
     */
    bool addAirport(std::shared_ptr<AirportVertex> airport);

    /**
     * @brief Adds an airline to the network.
     * @param airline The Airline object to add.
     * @return True if the airline was successfully added, false if the airline already exists.
     */
    bool addAirline(std::shared_ptr<Airline> airline);

    /**
     * @brief Adds a flight between two airports in the network.
     * @param source The code of the source airport.
     * @param target The code of the target airport.
     * @param airline The code of the airline for the flight.
     */
    void addFlight(const std::string& source, const std::string& target, const std::string& airline);

    /**
     * @brief Resets the 'visited' flag for all airports in the network.
     */
    void resetFlags();

    /**
     * @brief Gets the out-degree of a specific airport in the network.
     * @param airportCode The code of the airport.
     * @return The out-degree of the airport (number of outgoing flights).
     *         Returns -1 if the airport does not exist in the network.
     */
    int outDegree(const std::string& airportCode) const;

    /**
     * @brief Finds a specific airport vertex in the network by its code.
     * @param info The code of the airport to find.
     * @return A shared pointer to the AirportVertex if found, nullptr otherwise.
     */
    std::shared_ptr<AirportVertex> findVertex(const std::string &info);

    /**
     * @brief Finds a specific airport vertex in the network by its name.
     * @param name The name of the airport to find.
     * @return A shared pointer to the AirportVertex if found, nullptr otherwise.
     */
    std::shared_ptr<AirportVertex> findAirportByName(const std::string& name);

    /**
     * @brief Gets the vector of flights departing from a specific airport in the network.
     * @param airportCode The code of the airport.
     * @return A constant reference to the vector of Flight objects.
     *         Returns an empty vector if the airport does not exist in the network.
     */
    const std::vector<Flight>& getFlightsFromAirport(const std::string& airportCode) const;

    /**
     * @brief Finds all airports in a specific city.
     * @param city The name of the city.
     * @return A set of shared pointers to AirportVertex objects in the specified city.
     */
    std::vector<std::shared_ptr<AirportVertex>> airportsInCity(const std::string &city);

    void clearData();
};

#endif //FLIGHTMANAGEMENT_NETWORK_H
