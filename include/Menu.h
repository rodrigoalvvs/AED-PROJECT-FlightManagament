//
// Menu Class
//
// This class represents the menu for SkyNavigator, providing various options and functionalities.
//

#ifndef FLIGHTMANAGEMENT_MENU_H
#define FLIGHTMANAGEMENT_MENU_H

#include "NetworkController.h"
#include <iostream>
#include <vector>
#include <memory>

/**
 * @class Menu
 * @brief Represents the menu for SkyNavigator, providing various options and functionalities.
 */
class Menu {
private:
    NetworkController* controller; ///< Pointer to the NetworkController managing the network data.
    bool running;                  ///< Flag indicating whether the menu is running.

public:
    /**
     * @brief Constructor for the Menu class.
     * Initializes the NetworkController and sets the running flag to true.
     */
    Menu();

    /**
     * @brief Destructor for the Menu class.
     * Deletes the NetworkController.
     */
    ~Menu();

    /**
     * @brief Runs the main menu loop until the user chooses to exit.
     */
    void run();

private:
    /**
     * @brief Displays the main menu options and handles user input.
     */
    void displayMainMenu();

    /**
     * @brief Displays the statistics menu with various statistical options.
     */
    void displayStatisticsMenu();

    /**
     * @brief Displays global statistics about the network.
     */
    void displayGlobalStats();

    /**
     * @brief Displays statistics related to outbound flights from a specific airport.
     */
    void displayAirportOut();

    /**
     * @brief Displays city/airline statistics based on user choice.
     */
    void displayCityAirlineStats();

    /**
     * @brief Displays statistics related to countries and airports.
     */
    void displayCountriesStats();

    /**
     * @brief Displays destination statistics for a specific airport.
     */
    void displayDestinationStats();

    /**
     * @brief Displays reachable destinations based on user input.
     */
    void displayReachableDestinations();

    /**
     * @brief Displays statistics for the maximum trip with the most stops.
     */
    void displayMaximumtrip();

    /**
     * @brief Displays the top airports with the highest air traffic.
     */
    void displayTopAirports();

    /**
     * @brief Displays essential airports identified using articulation points.
     */
    void displayEssentialAirports();

    /**
     * @brief Displays the number of flights per city.
     */
    void displayFlightsPerCity();

    /**
     * @brief Displays the number of flights per airline.
     */
    void displayFlightsPerAirline();

    /**
     * @brief Displays countries reachable from a specific airport.
     */
    void displayCountriesAirport();

    /**
     * @brief Displays countries reachable from a specific city.
     */
    void displayCountriesCity();

    /**
     * @brief Displays the user interface to search for the best flight option.
     */
    void displayBestFlightOption();

    /**
     * @brief Displays the user interface to search for the best flight option with filters.
     */
    void displayBestFlightOptionFiltered();

    /**
     * @brief Gets user input for airport selection based on various criteria.
     * @return A vector of shared pointers to selected airports.
     */
    std::vector<std::shared_ptr<AirportVertex>> getAirport();

    /**
     * @brief Gets user input for search filters.
     * @return A SearchFilter object representing the user's selected filters.
     */
    SearchFilter getFilters();
};

#endif //FLIGHTMANAGEMENT_MENU_H
