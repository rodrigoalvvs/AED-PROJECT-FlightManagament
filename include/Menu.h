//
// Created by admin1 on 28-12-2023.
//

#ifndef FLIGHTMANAGEMENT_MENU_H
#define FLIGHTMANAGEMENT_MENU_H


#include "NetworkController.h"

class Menu{
private:
    NetworkController* controller;
    bool running;

public:
    // Constructor
    Menu();
    ~Menu();
    void run();

    void displayMainMenu();
    void displayStatisticsMenu();

    // 3.
    void displayGlobalStats();
    void displayAirportOut();
    void displayCityAirlineStats();
    void displayFlightsPerCity();
    void displayCountriesStats();
    void displayDestinationStats();
    void displayReachableDestinations();
    void displayMaximumtrip();
    void displayTopAirports();
    void displayEssentialAirports();

    void displayFlightsPerAirline();

    void displayCountriesAirport();

    void displayCountriesCity();

    // 4.
    void displayBestFlightOption();

    void searchByCode();

    void searchByName();

    void searchByCity();

    void searchByCoo();

    std::vector<std::shared_ptr<AirportVertex>> getAirport();

    void displayBestFlightOptionFiltered();

    // 5.
    SearchFilter getFilters();
};

#endif //FLIGHTMANAGEMENT_MENU_H
