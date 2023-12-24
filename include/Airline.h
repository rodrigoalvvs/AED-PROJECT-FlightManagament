//
// Created by admin1 on 19-12-2023.
//

#ifndef FLIGHTMANAGEMENT_AIRLINE_H
#define FLIGHTMANAGEMENT_AIRLINE_H

#include <string>

class Airline{
private:
    std::string code;
    std::string name;
    std::string callsign;
    std::string country;
public:
    // Constructor
    Airline(const std::string& code_, const std::string& name_, const std::string& callsign_, const std::string& country_);

    // Getter methods
    const std::string &getCode() const;
    const std::string &getCallsign();
    const std::string &getName() const;
    const std::string &getCountry() const;

    // Setter methods
    void setCode(const std::string &code);
    void setName(const std::string &name);
    void setCallsign(const std::string &callsign);
    void setCountry(const std::string &country);


};

#endif //FLIGHTMANAGEMENT_AIRLINE_H
