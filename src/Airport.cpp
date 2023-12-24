//
// Created by admin1 on 19-12-2023.
//

#include "../include/Airport.h"


const std::string &Airport::getCode() const {
    return this->code;
}

const std::string &Airport::getName() const {
    return this->name;
}

const std::string &Airport::getCity() const {
    return this->city;
}

const std::string &Airport::getCountry() const {
    return this->country;
}

double Airport::getLatitude() const {
    return this->latitude;
}

double Airport::getLongitude() const {
    return this->longitude;
}

void Airport::setCode(const std::string &code_) {
    this->code = code_;
}

void Airport::setName(const std::string &name_) {
    this->name = name_;
}

void Airport::setCity(const std::string &city_) {
    this->city = city_;
}

void Airport::setCountry(const std::string &country_) {
    this->country = country_;
}

void Airport::setLatitude(double latitude_) {
    this->latitude = latitude_;
}

void Airport::setLongitude(double longitude_) {
    this->longitude = longitude_;
}

Airport::Airport(const std::string &code, const std::string &name, const std::string &city, const std::string &country,
                 double latitude, double longitude) : code(code), name(name), city(city), country(country),
                                                      latitude(latitude), longitude(longitude) {}
