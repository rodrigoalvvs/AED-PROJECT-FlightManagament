//
// Airline Class
//
// This class represents an airline with attributes such as code, name, callsign, and country.
//

#ifndef FLIGHTMANAGEMENT_AIRLINE_H
#define FLIGHTMANAGEMENT_AIRLINE_H

#include <string>

/**
 * @class Airline
 * @brief Represents an airline with associated information.
 */


class Airline {
private:
    std::string code;       ///< The airline code.
    std::string name;       ///< The name of the airline.
    std::string callsign;   ///< The callsign of the airline.
    std::string country;    ///< The country in which the airline operates.

public:
    /**
     * @brief Constructor for the Airline class.
     * @param code_ The airline code.
     * @param name_ The name of the airline.
     * @param callsign_ The callsign of the airline.
     * @param country_ The country in which the airline operates.
     */
    Airline(const std::string& code_, const std::string& name_, const std::string& callsign_, const std::string& country_);

    /**
     * @brief Getter for the airline code.
     * @return The code of the airline.
     */
    const std::string &getCode() const;

    /**
     * @brief Getter for the callsign of the airline.
     * @return The callsign of the airline.
     */
    const std::string &getCallsign();

    /**
     * @brief Getter for the name of the airline.
     * @return The name of the airline.
     */
    const std::string &getName() const;

    /**
     * @brief Getter for the country in which the airline operates.
     * @return The country of the airline.
     */
    const std::string &getCountry() const;

    /**
     * @brief Setter for the airline code.
     * @param code The new code to set.
     */
    void setCode(const std::string &code);

    /**
     * @brief Setter for the name of the airline.
     * @param name The new name to set.
     */
    void setName(const std::string &name);

    /**
     * @brief Setter for the callsign of the airline.
     * @param callsign The new callsign to set.
     */
    void setCallsign(const std::string &callsign);

    /**
     * @brief Setter for the country in which the airline operates.
     * @param country The new country to set.
     */
    void setCountry(const std::string &country);
};

#endif //FLIGHTMANAGEMENT_AIRLINE_H
