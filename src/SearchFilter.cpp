//
// Created by admin1 on 01-01-2024.
//

#include "../include/SearchFilter.h"

SearchFilter::SearchFilter() {
    this->limitAirlines = -1;
    this->filterCities = false;
    this->filterAirlines = false;
    this->airlinesToUse.clear();
    this->citiesToStop.clear();
}

void SearchFilter::clearFilter() {
    this->limitAirlines = -1;
    this->filterCities = false;
    this->filterAirlines = false;
    this->airlinesToUse.clear();
    this->citiesToStop.clear();
}

void SearchFilter::addAirline(const std::string &airline) {
    this->airlinesToUse.insert(airline);
    this->filterAirlines = true;
}

void SearchFilter::addCity(const std::string &city) {
    this->citiesToStop.insert(city);
    this->filterCities = true;
}

int SearchFilter::getLimitAirlines() const {
    return this->limitAirlines;
}

bool SearchFilter::getFilterAirlines() const {
    return this->filterAirlines;
}

bool SearchFilter::getFilterCities() const {
    return this->filterCities;
}

const std::unordered_set<std::string> &SearchFilter::getAirlines() const {
    return this->airlinesToUse;
}

const std::unordered_set<std::string> &SearchFilter::getCities() const {
    return this->citiesToStop;
}

void SearchFilter::setAirlineLimit(int limit) {
    this->limitAirlines = limit;
}



