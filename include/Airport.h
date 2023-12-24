//
// Created by admin1 on 19-12-2023.
//

#ifndef FLIGHTMANAGEMENT_AIRPORT_H
#define FLIGHTMANAGEMENT_AIRPORT_H
#include <string>


class Airport{
private:
    std::string code;
    std::string name;
    std::string city;
    std::string country;
    double latitude;
    double longitude;
public:
    Airport(const std::string &code, const std::string &name, const std::string &city, const std::string &country,
            double latitude, double longitude);


    const std::string &getCode() const;

    const std::string &getName() const;

    const std::string &getCity() const;

    const std::string &getCountry() const;

    double getLatitude() const;

    double getLongitude() const;


    // Setter methods
    void setCode(const std::string &code);

    void setName(const std::string &name);

    void setCity(const std::string &city);

    void setCountry(const std::string &country);

    void setLatitude(double latitude);

    void setLongitude(double longitude);

};

#endif //FLIGHTMANAGEMENT_AIRPORT_H
