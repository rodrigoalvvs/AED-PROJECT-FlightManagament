//
// Created by admin1 on 28-12-2023.
//


#include <iostream>
#include "../include/Menu.h"

Menu::Menu() {
    this->controller = new NetworkController();
    this->running = true;
}

Menu::~Menu() {
    delete this->controller;
}

void Menu::run() {
    while(running){
        this->displayMainMenu();
    }

}
void Menu::displayMainMenu() {
    std::cout << "\033[1;36m==============================\033[0m\n"
                 "\033[1;36m      SkyNavigator\033[0m\n"
                 "\033[1;36m==============================\033[0m\n\n";
    std::cout << "3. Statistics for the network\n"
                 "4. Search best flight option\n"
                 "5. Search flight filtered\n"
                 "0. Exit\n==> Enter your choice: ";

    std::string option;
    std::getline(std::cin, option);
    try{
        std::stoi(option);
    }catch (const std::invalid_argument& e){
        std::cout << "\033[1;31mInvalid option!\033[0m\n";
        this->displayMainMenu();
    }
    switch (std::stoi(option)) {
        case 3:
            this->displayStatisticsMenu();
            break;
        case 4:
            this->displayBestFlightOption();
            break;
        case 5:
            // Add functionality for option 5 if needed
            this->displayBestFlightOptionFiltered();
            break;
        case 0:
            std::cout << "\033[1;34mSkyNavigator signing off. May your real-world journeys be as smooth as your virtual ones!\033[0m\n";
            this->running = false;
            break;
        default:
            std::cout << "\033[1;31mEnter a valid option!\033[0m\n";
    }
}

void Menu::displayStatisticsMenu() {
    while(true){
        std::cout << "\033[1;36m==============================\033[0m\n"
                     "\033[1;36m      Statisticts\033[0m\n"
                     "\033[1;36m==============================\033[0m\n\n";
        std::cout << "1.   Global Stats\n"
                     "2.  Airport Outbound Stats\n"
                     "3. City/Airline Stats\n"
                     "4.  Countries Stats\n"
                     "5.   Destination Stats\n"
                     "6.  Reachable Destinations\n"
                     "7. Maximum Trip Stats\n"
                     "8. Top Air Traffic Airport\n"
                     "9.  Essential Airports\n"
                     "0.   Back to Main Menu\n==> Enter your choice:";

        std::string option;
        std::getline(std::cin, option);

        try{
            std::stoi(option);
        }catch (const std::invalid_argument& e){
            std::cout << "\033[1;31mInvalid option!\033[0m\n";
            continue;
        }


        switch (std::stoi(option)) {
            case 1:
                this->displayGlobalStats();
                break;
            case 2:
                this->displayAirportOut();
                break;
            case 3:
                this->displayCityAirlineStats();
                break;
            case 4:
                this->displayCountriesStats();
                break;
            case 5:
                this->displayDestinationStats();
                break;
            case 6:
                this->displayReachableDestinations();
                break;
            case 7:
                this->displayMaximumtrip();
                break;
            case 8:
                this->displayTopAirports();
                break;
            case 9:
                this->displayEssentialAirports();
                break;
            case 0:
                return;
            default:
                std::cout << "Enter a valid option!\n";
                break;
        }
    }


}

void Menu::displayGlobalStats() {
    std::cout << "\033[1;36m==============================\033[0m\n"
                 "\033[1;36m   Global Statistics\033[0m\n"
                 "\033[1;36m==============================\033[0m\n\n";

    std::cout << "1. Total Number of Airports: " << this->controller->airportCount() << std::endl;
    std::cout << "2. Total Number of Flights: " << this->controller->flightCount() << std::endl;
    std::cout << "==>\033[1;34mAny key to continue:\033[0m ";

    std::string exitFlag;
    std::getline(std::cin, exitFlag);
}

void Menu::displayAirportOut() {
    while (true) {
        std::cout << "\033[1;36m==============================\033[0m\n"
                     "\033[1;36m  Airport Outbound Stats\033[0m\n"
                     "\033[1;36m==============================\033[0m\n";
        std::string airport;
        std::cout << "\033[1;33mEnter the name of the airport:\033[0m ";
        std::getline(std::cin, airport);

        std::shared_ptr<AirportVertex> airport_ = this->controller->findAirportByName(airport);
        if (airport_ == nullptr) {
            std::cout << "\033[1;31mInvalid airport name!\033[0m\n";
            continue;
        }

        std::cout << "Number of Flights Out of " << airport << ": " << this->controller->flightCountFromAirport(airport_->getAirportCode()) << std::endl;

        std::cout << "Number of Airlines from " << airport << ": " << this->controller->distinctAirlinesInAirport(airport_->getAirportCode()) << std::endl;
        std::cout << "\033[1;34mAny key to continue:\033[0m ";
        std::string option;
        std::getline(std::cin, option);
        return;
    }
}

void Menu::displayCityAirlineStats() {
    while (true) {
        std::cout << "\033[1;36m==============================\033[0m\n"
                     "\033[1;36m City/Airline Statistics\033[0m\n"
                     "\033[1;36m==============================\033[0m\n\n"
                     "1. Number of Flights per City\n"
                     "2. Number of Flights per Airline\n"
                     "0. Back to Statistics Menu\n\n"
                     "Enter your choice: ";
        std::string option;
        std::getline(std::cin, option);

        try{
            std::stoi(option);
        }catch (const std::invalid_argument& e){
            std::cout << "\033[1;31mInvalid option!\033[0m\n";
            continue;
        }

        switch (std::stoi(option)) {
            case 1:
                this->displayFlightsPerCity();
                break;
            case 2:
                this->displayFlightsPerAirline();
                break;
            case 0:
                return;
            default:
                continue;
        }
    }
}

void Menu::displayCountriesStats() {
    while (true) {
        std::cout << "\033[1;36m==============================\033[0m\n"
                     "\033[1;36m      Countries Stats\033[0m\n"
                     "\033[1;36m==============================\033[0m\n\n";
        std::cout << "1. Number of different countries that an airport flies to.\n";
        std::cout << "2. Number of different countries that you can go from a city.\n"
                     "0. Return to Statistics menu.\nYour choice: ";
        std::string option;
        std::getline(std::cin, option);

        try{
            std::stoi(option);
        }catch (const std::invalid_argument& e){
            std::cout << "\033[1;31mInvalid option!\033[0m\n";
            continue;
        }

        switch (std::stoi(option)) {
            case 1:
                this->displayCountriesAirport();
                break;
            case 2:
                this->displayCountriesCity();
                break;
            case 0:
                return;
            default:
                std::cout << "\033[1;31mInvalid option!\033[0m\n";
                break;
        }
    }
}

void Menu::displayDestinationStats() {
    while(true) {
        std::cout << "\033[1;36m==============================\033[0m\n"
                     "\033[1;36m   Destinations Stats\033[0m\n"
                     "\033[1;36m==============================\033[0m\n"
                     "\n\033[1;33mEnter the name of the airport:\033[0m ";

        std::string airport;
        std::getline(std::cin, airport);

        std::shared_ptr<AirportVertex> vertex = this->controller->findAirportByName(airport);
        if (vertex == nullptr) {
            std::cout << "\033[1;31mInvalid airport name!\033[0m\n";
            continue;
        }

        std::cout << "\033[1;32mAirports reachable:\033[0m " << this->controller->airportsReachable(vertex->getAirportCode()) << std::endl;
        std::cout << "\033[1;32mCities reachable:\033[0m " << this->controller->citiesReachable(vertex->getAirportCode()) << std::endl;
        std::cout << "\033[1;32mCountries reachable:\033[0m " << this->controller->countriesReachable(vertex->getAirportCode()) << std::endl;

        std::cout << "\n\033[1;34mAny key to continue:\033[0m ";
        std::string exitFlag;
        std::getline(std::cin, exitFlag);
        return;
    }
}

void Menu::displayReachableDestinations() {
    while(true) {
        std::cout << "\033[1;36m==============================\033[0m\n"
                     "\033[1;36m   Reachable Destinations\033[0m\n"
                     "\033[1;36m==============================\033[0m\n"
                     "\n\033[1;33mName of the airport to consult: \033[0m";

        std::string airport;
        std::getline(std::cin, airport);

        std::shared_ptr<AirportVertex> airport_ = this->controller->findAirportByName(airport);
        if (airport_ == nullptr) {
            std::cout << "\033[1;31mInvalid airport!\033[0m\n";
            continue;
        }

        std::string stops;
        std::cout << "\033[1;33mMaximum stops (lay-overs):\033[0m ";
        std::getline(std::cin, stops);

        try {
            int maxLays = std::stoi(stops);
            std::cout << "\033[1;32mDifferent Airports:\033[0m " << this->controller->airportsReachableNStops(airport_->getAirportCode(), maxLays) << "\n";
            std::cout << "\033[1;32mDifferent Cities:\033[0m " << this->controller->citiesReachableNStops(airport_->getAirportCode(), maxLays) << "\n";
            std::cout << "\033[1;32mDifferent Countries:\033[0m " << this->controller->countriesReachableNStops(airport_->getAirportCode(), maxLays) << "\n";

            std::cout << "\n\033[1;34mAny key to continue:\033[0m ";
            std::string option;
            std::getline(std::cin, option);
            return;
        } catch (const std::invalid_argument& e) {
            std::cout << "\033[1;31mInvalid number of stops!\033[0m\n";
            continue;
        }
    }
}

void Menu::displayMaximumtrip() {
    while(true){
        system("clear");

        std::cout << "\033[1;36m==============================\033[0m\n"
                     "\033[1;36m      Maximum Trip Stats\033[0m\n"
                     "\033[1;36m==============================\033[0m\n\n";

        std::pair<std::vector<std::pair<std::string, std::string>>, int> result = this->controller->getLongestTripWithDistance();

        if(result.second == 0) {
            std::cout << "\033[1;31mNo trips found!\033[0m\n\n";
        } else {
            std::cout << "\033[1;33mListed below are the pairs of source-destination that need the most amount of stops (\033[0m" << result.second << "\033[1;33m stops)\033[0m\n";
            for(const auto& pair: result.first){
                std::cout << "\033[1;32mFrom \033[0m" << pair.first << "\033[1;32m to \033[0m" << pair.second << std::endl;
            }
        }

        std::string exitFlag;
        std::cout << "\n\033[1;34mPress any key to continue...\033[0m";
        std::getline(std::cin, exitFlag);
        return;
    }
}

void Menu::displayTopAirports() {
    while (true) {
        std::cout << "\033[1;36m==============================\033[0m\n"
                     "\033[1;36m  Top Air Traffic Airport\033[0m\n"
                     "\033[1;36m==============================\033[0m\n\n";
        std::cout << "Display how many airports: ";
        std::string k;
        std::getline(std::cin, k);

        try {
            int counter = 1;
            for (std::pair<std::string, int> airport : this->controller->topAirports(std::stoi(k))) {
                std::cout << counter++ << " -> " << airport.first << " with " << airport.second << " flights!\n";
            }

            std::string exitFlag;
            std::cout << "\033[1;34mAny key to continue...\033[0m";
            std::getline(std::cin, exitFlag);
            return;
        } catch (const std::invalid_argument &e) {
            std::cout << "\033[1;31mInvalid number!\033[0m\n";
            continue;
        }
    }
}

void Menu::displayEssentialAirports() {
    std::cout << "\033[1;36m==============================\033[0m\n"
                 "\033[1;36m   Essential Airports\033[0m\n"
                 "\033[1;36m==============================\033[0m\n\n";

    int counter = 0;
    for (const std::string& airport : this->controller->articulationAirports()) {
        if(counter++ % 10 == 0){
            std::cout << std::endl;
        }
        std::cout << airport << " ";
    }

    std::cout << std::endl;
    std::cout << counter << " Airports are essential to our network!"<< std::endl;
    std::string exitFlag;
    std::cout << "\033[1;34mAny key to continue...\033[0m";
    std::getline(std::cin, exitFlag);
    return;
}

void Menu::displayFlightsPerCity() {
    std::cout << "\033[1;36m==============================\033[0m\n"
                 "\033[1;36m Number of Flights per City\033[0m\n"
                 "\033[1;36m==============================\033[0m\n\n"
                 "City to consult: ";

    std::string city;
    std::getline(std::cin, city);

    std::cout << city << ": " << this->controller->flightsPerCity(city) << " flights\n";

    std::string exitFlag;
    std::cout << "\033[1;34mAny key to continue:\033[0m ";
    std::getline(std::cin, exitFlag);
}

void Menu::displayFlightsPerAirline() {
    std::cout << "\033[1;36m====================================\033[0m\n"
                 "\033[1;36m Number of Flights per Airline\033[0m\n"
                 "\033[1;36m====================================\033[0m\n\n"
                 "Airline to consult: ";

    std::string airline;
    std::getline(std::cin, airline);

    std::cout << airline << ": " << this->controller->flightsPerAirline(airline) << " flights\n";

    std::string exitFlag;
    std::cout << "\033[1;34mAny key to continue:\033[0m ";
    std::getline(std::cin, exitFlag);
}
void Menu::displayCountriesAirport() {
    while (true) {
        std::cout << "\033[1;36m====================================\033[0m\n"
                     "\033[1;36m   Countries from Airport\033[0m\n"
                     "\033[1;36m====================================\033[0m\n\n"
                     "Airport to consult: ";
        std::string airport;
        std::getline(std::cin, airport);

        std::shared_ptr<AirportVertex> airport_ = this->controller->findAirportByName(airport);

        if (airport_ == nullptr) {
            std::cout << "\033[1;31mInvalid airport!\033[0m\n";
            continue;
        }

        std::cout << "Airport " << airport << " flies to " << this->controller->distinctCountriesFromAirport(airport_->getAirportCode()) << " different countries\n";

        std::cout << "\033[1;34mAny key to continue:\033[0m\n";
        std::string option;
        std::getline(std::cin, option);
        return;
    }
}

void Menu::displayCountriesCity() {
    while (true) {
        std::cout << "\033[1;36m====================================\033[0m\n"
                     "\033[1;36m      Countries from City\033[0m\n"
                     "\033[1;36m====================================\033[0m\n\n"
                     "City to consult: ";
        std::string city;
        std::getline(std::cin, city);

        std::cout << "From " << city << " you can fly to " << this->controller->distinctCountriesFromCity(city) << " different countries\n";

        std::cout << "\033[1;34mAny key to continue:\033[0m\n";
        std::string option;
        std::getline(std::cin, option);
        return;
    }
}

void Menu::displayBestFlightOption() {
    while (true) {
        std::cout << "\033[1;36m====================================\033[0m\n"
                     "\033[1;36m      Search Your Flight\033[0m\n"
                     "\033[1;36m====================================\033[0m\n\n";

        std::cout << "\033[1;34mFor the Source Airport:\033[0m\n";
        std::vector<std::shared_ptr<AirportVertex>> sources = this->getAirport();

        std::cout << "\033[1;34mFor the Destination Airport:\033[0m\n";
        std::vector<std::shared_ptr<AirportVertex>> destinations = this->getAirport();

        std::vector<std::vector<Flight>> paths = this->controller->getPaths(sources, destinations, SearchFilter());


        int counter = 1;
        for (const std::vector<Flight>& flight : paths) {
            std::cout << "Trip " << counter++;
            for (Flight flight1 : flight) {
                std::cout << " \033[1;33m--" << flight1.getAirlineCode() << "->\033[0m [\033[1;32m" << flight1.getDestination()->getName() << "\033[0m]";
            }
            std::cout << std::endl;
        }
        if (counter == 1) {
            std::cout << "\033[1;31mCouldn't find any flights! :/\033[0m\n";
        }

        std::string exitFlag;
        std::cout << "\033[1;34mAny key to continue..\033[0m";
        std::getline(std::cin, exitFlag);
        return;
    }
}

std::vector<std::shared_ptr<AirportVertex>> Menu::getAirport() {
    std::vector<std::shared_ptr<AirportVertex>> result;

    std::cout << "1. Airport code\n"
                 "2. Airport name\n"
                 "3. City name\n"
                 "4. Coordinates\nEnter your option:";
    std::string option;
    std::getline(std::cin, option);

    try{
        std::stoi(option);
    }catch (const std::invalid_argument& e){
        std::cout << "\033[1;31mInvalid option!\033[0m\n";
        return this->getAirport();
    }

    std::string airportCode;
    std::string airportName;
    std::string cityName;
    std::string latitude;
    std::string longitude;


    switch (std::stoi(option)) {
        case 1:
            std::cout << "Desired airport code: ";
            std::getline(std::cin, airportCode);
            result.push_back(this->controller->findAirportByCode(airportCode));
            return result;
        case 2:
            std::cout << "Desired airport name: ";
            std::getline(std::cin, airportName);
            result.push_back(this->controller->findAirportByName(airportName));
            return result;
        case 3:
            std::cout << "Desired city: ";
            std::getline(std::cin, cityName);
            return this->controller->findAirportsInCity(cityName);
        case 4:
            try{
                std::cout << "Latitude: ";
                std::getline(std::cin, latitude);
                std::cout << "Longitude: ";
                std::getline(std::cin, longitude);
                return this->controller->findAirportsNearPoint(std::stod(latitude), std::stod(longitude));

            } catch (const std::invalid_argument& e){
                std::cout << "Invalid coordinates!\n";
                return this->getAirport();
            }
        default:
            std::cout << "\033[1;31mInvalid option!\033[0m\n";
            return this->getAirport();
    }
}


SearchFilter Menu::getFilters(){
    SearchFilter newFilter;
    std::string limit;
    std::string city;
    std::string airline;
    std::unordered_set<std::string> airlines;
    std::unordered_set<std::string> cities;
    while(true){
        std::cout << "\033[1;34mFilters to add:\033[0m\n";
        std::cout << "1. Limit number of distinct Airlines\n";
        std::cout << "2. Limit Airlines to use\n3. Add city to stop\n4. Clear Filters\n0. Search\nEnter your choice: ";
        std::string option;
        std::getline(std::cin, option);




        try{
            std::stoi(option);
        }catch (const std::invalid_argument& e){
            std::cout << "\033[1;31mInvalid option!\033[0m\n";
            continue;
        }


        switch (std::stoi(option)) {
            case 1:
                std::cout << "How many distinct airlines would you like to use? ";
                std::getline(std::cin, limit);
                try{
                    newFilter.setAirlineLimit(std::stoi(limit));
                    break;
                } catch (const std::invalid_argument& e){
                    std::cout << "Enter a valid limit!\n";
                    break;
                }
            case 2:
                while(true){
                    std::cout << "Enter the airline to add (-1 to end): ";
                    std::getline(std::cin, airline);
                    if(airline == "-1") break;
                    newFilter.addAirline(airline);
                }
                break;
            case 3:
                while(true){
                    std::cout << "Enter the city to add (-1 to end): ";
                    std::getline(std::cin, city);
                    if(city == "-1") break;
                    newFilter.addCity(city);
                }
                break;
            case 4:
                newFilter.clearFilter();
                break;
            case 0:
                return newFilter;
            default:
                std::cout << "Invalid option!\n";
                break;
        }

    }
}
void Menu::displayBestFlightOptionFiltered() {
    while (true) {
        std::cout << "\033[1;36m====================================\033[0m\n"
                     "\033[1;36m      Search Your Flight\033[0m\n"
                     "\033[1;36m====================================\033[0m\n\n";

        std::cout << "\033[1;34mFor the Source Airport:\033[0m\n";
        std::vector<std::shared_ptr<AirportVertex>> sources = this->getAirport();

        std::cout << "\033[1;34mFor the Destination Airport:\033[0m\n";
        std::vector<std::shared_ptr<AirportVertex>> destinations = this->getAirport();

        std::vector<std::vector<Flight>> paths = this->controller->getPaths(sources, destinations, this->getFilters());

        int counter = 1;
        for (const std::vector<Flight>& flight : paths) {
            std::cout << "\033[1;32mTrip " << counter++ << ":\033[0m";
            for (Flight flight1 : flight) {
                std::cout << " \033[1;33m--" << flight1.getAirlineCode() << "->\033[0m [\033[1;32m" << flight1.getDestination()->getName() << "\033[0m]";
            }
            std::cout << std::endl;
        }
        if (counter == 1) {
            std::cout << "\033[1;31mCouldn't find any flights! :/\033[0m\n";
        }

        std::string exitFlag;
        std::cout << "\033[1;34mAny key to continue..\033[0m";
        std::getline(std::cin, exitFlag);
        return;
    }
}
