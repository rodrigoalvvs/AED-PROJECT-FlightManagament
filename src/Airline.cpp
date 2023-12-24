//
// Created by admin1 on 19-12-2023.
//

#include "../include/Airline.h"


Airline::Airline(const std::string &code_, const std::string &name_, const std::string &callsign_, const std::string &country_) : code(code_) , name(name_), callsign(callsign_), country(country_){}

const std::string &Airline::getCallsign() {
    return this->callsign;
}

const std::string &Airline::getCode() const {
    return this->code;
}

const std::string &Airline::getName() const {
    return this->name;
}

const std::string &Airline::getCountry() const {
    return this->country;
}

void Airline::setCode(const std::string &code_) {
    this->code = code_;
}

void Airline::setCallsign(const std::string &callsign_) {
    this->callsign = callsign_;
}

void Airline::setName(const std::string &name_) {
    this->name = name_;
}

void Airline::setCountry(const std::string &country_) {
    this->country = country_;
}
