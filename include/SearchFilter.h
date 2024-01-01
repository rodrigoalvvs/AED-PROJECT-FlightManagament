//
// Created by admin1 on 01-01-2024.
//

#ifndef FLIGHTMANAGEMENT_SEARCHFILTER_H
#define FLIGHTMANAGEMENT_SEARCHFILTER_H

#include <unordered_set>
#include <string>


/**
 * @class SearchFilter
 * @brief Represents a set of filters for flight search operations.
 */
class SearchFilter{
private:
    int limitAirlines; /**< The limit on the number of airlines. Set to -1 to use as many as necessary. */
    bool filterAirlines; /**< Flag indicating whether to filter airlines. Set to false to not filter the airlines. */
    bool filterCities; /**< Flag indicating whether to filter cities. */
    std::unordered_set<std::string> airlinesToUse; /**< Set of airlines to be used as a filter. */
    std::unordered_set<std::string> citiesToStop; /**< Set of cities to be used as a filter. */

public:
    /**
     * @brief Default constructor for the SearchFilter class.
     */
    SearchFilter();

    /**
     * @brief Clears all filters in the SearchFilter object.
     */
    void clearFilter();

    /**
     * @brief Sets the limit on the number of distinct airlines to be used in the search.
     * @param limit The limit on the number of airlines.
     */
    void setAirlineLimit(int limit);
    /**
     * @brief Adds an airline to the set of airlines to be used as a filter.
     * @param airline The name of the airline to be added.
     */
    void addAirline(const std::string& airline);
    /**
     * @brief Adds a city to the set of cities to be used as a filter.
     * @param city The name of the city to be added.
     */
    void addCity(const std::string& city);

    /**
     * @brief Gets the limit on the number of airlines to be used in the search.
     * @return The limit on the number of airlines.
     */
    int getLimitAirlines() const;
    /**
     * @brief Checks if the airline filter is active.
     * @return True if the airline filter is active, false otherwise.
     */
    bool getFilterAirlines() const;
    /**
     * @brief Checks if the city filter is active.
     * @return True if the city filter is active, false otherwise.
     */
    bool getFilterCities() const;


    /**
     * @brief Gets the set of airlines to be used as a filter.
     * @return The set of airlines.
     */
    const std::unordered_set<std::string> & getAirlines() const;
    /**
     * @brief Gets the set of cities to be used as a filter.
     * @return The set of cities.
     */
    const std::unordered_set<std::string>& getCities() const;
};

#endif //FLIGHTMANAGEMENT_SEARCHFILTER_H
