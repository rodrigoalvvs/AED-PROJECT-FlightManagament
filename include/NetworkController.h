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
#include "SearchFilter.h"

/**
 * @class NetworkController
 * @brief Manages operations and queries on the flight network.
 */
class NetworkController{
private:
    Network network; /**< The underlying network managed by the controller. */

public:
    /**
     * @brief Constructs a NetworkController object.
     *
     * This constructor initializes a NetworkController object by creating a new Network
     * object and loading data into it using the `loadData` function.
     */
    NetworkController();

    /**
     * @brief Loads data into the network.
     *
     * This function is responsible for loading data into the network. It sequentially
     * calls three functions: `loadAirports`, `loadAirlines`, and `loadFlights` to populate
     * the network with information about airports, airlines, and flights.
     */
    void loadData();


    /**
    * @brief Loads flight data from a CSV file and adds flights to the network.
    *
    * This function reads flight information from a CSV file and adds corresponding
    * flights to the network. The CSV file should have columns: source, target, and airline.
    */
    void loadFlights();

    /**
     * @brief Loads airport data from a CSV file and adds airports to the network.
     *
     * This function reads airport information from a CSV file and adds corresponding
     * airports to the network. The CSV file should have columns: code, name, city,
     * country, latitude, and longitude.
     */
    void loadAirports();
    /**
     * @brief Loads airline data from a CSV file and adds airlines to the network.
     *
     * This function reads airline information from a CSV file and adds corresponding
     * airlines to the network. The CSV file should have columns: code, name, callsign,
     * and country.
     */
    void loadAirlines();


    // 3.i
    /**
     * @brief Get the total number of airports in the network.
     * @return The number of airports.
     */
    int airportCount();

    /**
     * @brief Get the total number of flights in the network.
     * @return The number of flights.
     */
    int flightCount();


    // 3.ii
    /**
     * @brief Get the total number of flights departing from a specific airport.
     * @param airportCode The code of the airport.
     * @return The number of flights departing from the specified airport.
     */
    int flightCountFromAirport(const std::string& airportCode) const;

    /**
     * @brief Get the number of distinct airlines operating at a specific airport.
     * @param airportCode The code of the airport.
     * @return The number of distinct airlines at the specified airport.
     */
    int distinctAirlinesInAirport(const std::string& airportCode) const;

    // 3.iii
    /**
     * @brief Get the total number of flights in a specific city.
     * @param city The name of the city.
     * @return The total number of flights in the specified city.
     */
    int flightsPerCity(const std::string& city);

    /**
     * @brief Get the total number of flights operated by a specific airline in the network.
     * @param airline The airline code.
     * @return The total number of flights operated by the specified airline.
     */
    int flightsPerAirline(const std::string& airline);

    /**
     * @brief Perform a depth-first search to count the flights for a specific airline.
     * @param vertex The starting vertex for the DFS.
     * @param counter Reference to the counter variable.
     * @param match The airline code to match.
     */
    void airlineDFS(std::shared_ptr<AirportVertex> vertex, int& counter, const std::string& match);


    // 3.iv
    /**
     * @brief Get the number of distinct countries from a specific airport.
     * @param airportCode The code of the airport.
     * @return The number of distinct countries from the specified airport.
     *         Returns -1 if the airport is not found.
     */
    int distinctCountriesFromAirport(const std::string& airportCode);
    /**
     * @brief Get the number of distinct countries from all airports in a specific city.
     * @param city The name of the city.
     * @return The number of distinct countries from all airports in the specified city.
     */
    int distinctCountriesFromCity(const std::string& city);
    /**
     * @brief Count the number of distinct countries from a vector of airports.
     * @param airports The vector of airports.
     * @return The total number of distinct countries from the provided airports.
     */
    int countDistinctCountries(const std::vector<std::shared_ptr<AirportVertex>>& airports);

    // 3.v
    /**
     * @brief Get the number of reachable airports from a specific airport.
     * @param airportCode The code of the airport.
     * @return The number of reachable airports from the specified airport.
     */
    int airportsReachable(const std::string& airportCode);

    /**
     * @brief Get the number of reachable cities from a specific airport.
     * @param airportCode The code of the airport.
     * @return The number of reachable cities from the specified airport.
     */
    int citiesReachable(const std::string& airportCode);

    /**
     * @brief Get the number of reachable countries from a specific airport.
     * @param airportCode The code of the airport.
     * @return The number of reachable countries from the specified airport.
     */
    int countriesReachable(const std::string& airportCode);

    /**
     * @brief Find the reachable airports from a specific airport.
     * @param airportCode The code of the airport.
     * @return A vector containing the reachable airports from the specified airport.
     *
     * * @complexity
     *      - Time complexity: O(V * (V + E)), where V is the number of airports        and E is the number of flights.
     */
    std::vector<std::shared_ptr<AirportVertex>> reachable(const std::string& airportCode);

    /**
     * @brief Depth-first search to find reachable airports from a given vertex.
     * @param vertex The starting vertex for the DFS.
     * @param reachable Vector to store the reachable airports.
     */
    void reachableDFS(std::shared_ptr<AirportVertex> vertex, std::vector<std::shared_ptr<AirportVertex>>& reachable);


    // 3.vi
    /**
     * @brief Get the number of reachable airports from a specific airport with a maximum number of stops.
     * @param airportCode The code of the airport.
     * @param nStops The maximum number of stops allowed.
     * @return The number of reachable airports from the specified airport.
     */
    int airportsReachableNStops(const std::string& airportCode, int nStops);
    /**
     * @brief Get the number of reachable cities from a specific airport with a maximum number of stops.
     * @param airportCode The code of the airport.
     * @param nStops The maximum number of stops allowed.
     * @return The number of reachable cities from the specified airport.
     */
    int citiesReachableNStops(const std::string& airportCode, int nStops);

    /**
     * @brief Get the number of reachable countries from a specific airport with a maximum number of stops.
     * @param airportCode The code of the airport.
     * @param nStops The maximum number of stops allowed.
     * @return The number of reachable countries from the specified airport.
     */
    int countriesReachableNStops(const std::string& airportCode, int nStops);

    /**
     * @brief Get the list of reachable airports from a specific airport with a maximum number of stops.
     * @param airportCode The code of the airport.
     * @param nStops The maximum number of stops allowed.
     * @return A vector containing the reachable airports from the specified airport.
     *
     * @complexity
     *     - Time Complexity: O(N), where N is the maximum number of stops.
     */
    std::vector<std::shared_ptr<AirportVertex>> reachableWithNStops(const std::string& airportCode, int nStops);

    /**
     * @brief Depth-first search to find reachable airports from a given vertex with a maximum number of stops.
     * @param vertex The starting vertex for the DFS.
     * @param counter Reference to a counter for counting reachable airports.
     * @param nStops The maximum number of stops allowed.
     * @param reachable Vector to store the reachable airports.
     */
    void reachableWithNStopsDFS(std::shared_ptr<AirportVertex> vertex, int& counter, int nStops, std::vector<std::shared_ptr<AirportVertex>>& reachable);

    // 3.vii
    /**
     * @brief Get the longest trips with their distances in terms of stops.
     *
     * This function performs a breadth-first search from each airport to find the longest trip(s)
     * in terms of stops (distance). It returns a pair containing a vector of longest trips,
     * where each trip is represented by a pair of airport codes (source and destination)
     *
     *
     *
     * @return A pair containing a vector of longest trips and the maximum number of stops.
     *
     *
     * @complexity
     *      - Time complexity: O(V * (V + E)), where V is the number of airports        and E is the number of flights.
     */
    std::pair<std::vector<std::pair<std::string, std::string>>, int> getLongestTripWithDistance();

    // 3.viii
    /**
     * @brief Get the top airports based on the number of flights.
     *
     * This function retrieves the top airports based on the number of flights. It uses a priority
     * queue (max heap) to efficiently track the airports with the highest number of flights.
     *
     * @param k The number of top airports to retrieve.
     * @return A vector of pairs where each pair contains the airport code and its corresponding
     *         number of flights, sorted by the number of flights in descending order.
     *
     * @complexity
     *     - Time Complexity: O(V * log(V)), where V is the number of vertices (airports) in the network.
     */
    std::vector<std::pair<std::string, int>> topAirports(int k);

    // 3. ix (Articulation points)
    /**
     * @brief Find articulation airports in the network.
     *
     * This function identifies articulation airports in the network using depth-first search (DFS).
     * Articulation airports are critical points whose removal can increase the number of connected
     * components in the network.
     *
     * @return An unordered set of airport codes representing the articulation airports.
     *
     * @complexity
 *     - Time Complexity: O(V + E), where V is the number of vertices (airports) and E is the number of edges (flights) in the network.
     */
    std::unordered_set<std::string> articulationAirports();


    /**
     * @brief Perform depth-first search to identify articulation airports.
     *
     * This function is a helper function used by `articulationAirports()` to perform depth-first
     * search and identify articulation airports.
     *
     * @param vertex The current vertex being processed.
     * @param s A stack used to keep track of visited vertices.
     * @param result An unordered set to store the identified articulation airports.
     * @param i A counter to assign unique numbers to vertices during DFS.
     */
    void dfs_art(std::shared_ptr<AirportVertex> vertex, std::stack<std::string>& s, std::unordered_set<std::string>& result, int& i);

    /**
     * @brief Check if an element is present in the stack.
     *
     * This template function checks whether a given element is present in the provided stack.
     *
     * @tparam T The type of elements in the stack.
     * @param stack The stack to be checked.
     * @param info The element to be checked for presence in the stack.
     * @return true if the element is found in the stack, false otherwise.
     */
    template<class T>
    bool inStack(std::stack<T> stack, T info);


    // 4.
    /**
     * @brief Finds an airport vertex based on its airport code.
     * @param code The airport code.
     * @return A shared pointer to the found airport vertex, or nullptr if not found.
     */
    std::shared_ptr<AirportVertex> findAirportByCode(const std::string& code);
    /**
     * @brief Finds an airport vertex based on its name.
     * @param name The name of the airport.
     * @return A shared pointer to the found airport vertex, or nullptr if not found.
     */
    std::shared_ptr<AirportVertex> findAirportByName(const std::string& name);
    /**
     * @brief Finds all airports located in a given city.
     * @param city The name of the city.
     * @return A vector of shared pointers to airports in the specified city.
     */
    std::vector<std::shared_ptr<AirportVertex>> findAirportsInCity(const std::string& city);

    /**
     * @brief Finds airports near a specified geographical point (latitude, longitude).
     * @param latitude The latitude of the point.
     * @param longitude The longitude of the point.
     * @return A vector of shared pointers to airports near the specified point.
     * @complexity
     *     - Time Complexity: O(V * log(V)), where V is the number of vertices (airports) in the network.
     */
    std::vector< std::shared_ptr<AirportVertex>> findAirportsNearPoint(double latitude, double longitude);

    /**
     * @brief Computes the geographical distance between two points given their coordinates.
     * @param latitude The latitude of the first point.
     * @param longitude The longitude of the first point.
     * @param second The second airport vertex.
     * @return The distance in kilometers between the two points.
     */
    double computeDistance(double latitude, double longitude, std::shared_ptr<AirportVertex>);

    /**
     * @brief Finds the best flight options between two airports based on certain criteria, using breadth-first search.
     * @param source The source airport.
     * @param destination The destination airport.
     * @param filter The search filter criteria.
     * @param result A vector to store the result paths.
     * @return A vector of vectors of flights representing the best flight options.
     */
    std::vector<std::vector<Flight>> findBestFlightOption(std::shared_ptr<AirportVertex> source, std::shared_ptr<AirportVertex> destination, SearchFilter filter, std::vector<std::vector<Flight>>& result);

    /**
     * @brief Gets all possible flight paths between multiple source and destination airport pairs based on certain criteria.
     *
     * This function finds the best flight options between each source and destination pair using breadth-first search.
     * The resulting paths are stored in a vector of vectors of flights.
     *
     * @param sources A vector of shared pointers to source airports.
     * @param destinations A vector of shared pointers to destination airports.
     * @param filter The search filter criteria.
     * @return A vector of vectors of flights representing the possible flight paths.
     */
    std::vector<std::vector<Flight>> getPaths(const std::vector<std::shared_ptr<AirportVertex>> & sources,const std::vector<std::shared_ptr<AirportVertex>> & destinations,const  SearchFilter& filter);


    // 5.
    /**
     * @brief Checks if a value is present in an unordered set.
     *
     * This function checks if the given value is present in the provided unordered set.
     *
     * @param set The unordered set to check.
     * @param value The value to check for in the set.
     * @return True if the value is present in the set, false otherwise.
     */
    bool inSet(std::unordered_set<std::string>, const std::string&);

    /**
     * @brief Checks if a flight path satisfies the given search filter criteria.
     *
     * This function checks if a flight path satisfies the search filter criteria, including airlines to use,
     * cities to stop in, limiting the number of airlines, and more.
     *
     * @param path The vector of flights representing the flight path.
     * @param filter The search filter criteria.
     * @return True if the flight path satisfies the filter criteria, false otherwise.
     */
    bool checkFilters(const std::vector<Flight>& path, SearchFilter filter);

};

#endif //FLIGHTMANAGEMENT_NETWORKCONTROLLER_H
