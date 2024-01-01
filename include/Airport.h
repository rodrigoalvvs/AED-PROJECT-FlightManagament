//
// Created by admin1 on 19-12-2023.
//
#ifndef FLIGHTMANAGEMENT_AIRPORT_H
#define FLIGHTMANAGEMENT_AIRPORT_H

#include <string>

/**
 * @class Airport
 * @brief Represents an airport with associated information.
 */
class Airport {
private:
    std::string code;       /**< The code of the airport. */
    std::string name;       /**< The name of the airport. */
    std::string city;       /**< The city where the airport is located. */
    std::string country;    /**< The country where the airport is located. */
    double latitude;        /**< The latitude of the airport. */
    double longitude;       /**< The longitude of the airport. */

public:
    /**
     * @brief Constructor for the Airport class.
     * @param code The code of the airport.
     * @param name The name of the airport.
     * @param city The city where the airport is located.
     * @param country The country where the airport is located.
     * @param latitude The latitude of the airport.
     * @param longitude The longitude of the airport.
     */
    Airport(const std::string &code, const std::string &name, const std::string &city,
            const std::string &country, double latitude, double longitude);

    /**
     * @brief Getter for the airport code.
     * @return The code of the airport.
     */
    const std::string &getCode() const;

    /**
     * @brief Getter for the name of the airport.
     * @return The name of the airport.
     */
    const std::string &getName() const;

    /**
     * @brief Getter for the city where the airport is located.
     * @return The city of the airport.
     */
    const std::string &getCity() const;

    /**
     * @brief Getter for the country where the airport is located.
     * @return The country of the airport.
     */
    const std::string &getCountry() const;

    /**
     * @brief Getter for the latitude of the airport.
     * @return The latitude of the airport.
     */
    double getLatitude() const;

    /**
     * @brief Getter for the longitude of the airport.
     * @return The longitude of the airport.
     */
    double getLongitude() const;

    // Setter methods

    /**
     * @brief Setter for the airport code.
     * @param code The new code to set.
     */
    void setCode(const std::string &code);

    /**
     * @brief Setter for the name of the airport.
     * @param name The new name to set.
     */
    void setName(const std::string &name);

    /**
     * @brief Setter for the city where the airport is located.
     * @param city The new city to set.
     */
    void setCity(const std::string &city);

    /**
     * @brief Setter for the country where the airport is located.
     * @param country The new country to set.
     */
    void setCountry(const std::string &country);

    /**
     * @brief Setter for the latitude of the airport.
     * @param latitude The new latitude to set.
     */
    void setLatitude(double latitude);

    /**
     * @brief Setter for the longitude of the airport.
     * @param longitude The new longitude to set.
     */
    void setLongitude(double longitude);
};

#endif //FLIGHTMANAGEMENT_AIRPORT_H