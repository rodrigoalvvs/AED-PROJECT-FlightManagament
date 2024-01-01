cmake_minimum_required(VERSION 3.22)
project(flightManagement)

set(CMAKE_CXX_STANDARD 11)

add_executable(flightManagement main.cpp
        include/Flight.h
        include/AirportVertex.h
        include/Network.h
        include/Airline.h
        include/NetworkController.h
        src/NetworkController.cpp
        src/Airline.cpp
        src/AirportVertex.cpp
        src/Flight.cpp
        src/Network.cpp
        include/Airport.h
        src/Airport.cpp
        include/Menu.h
        src/Menu.cpp
        include/SearchFilter.h
        src/SearchFilter.cpp
)
