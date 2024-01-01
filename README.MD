# SkyNavigator (AED 23/24)

This C++ project implements a Flight Management System that allows users to analyze and query information about airports, airlines, and flights within a network.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)


## Introduction

The Flight Management System is a C++ project that provides functionalities for managing and querying a network of airports, airlines, and flights. The system is designed to load data from CSV files, perform various network analyses, and allow users to find optimal flight paths based on specific criteria.

## Features

- Load data about airports, airlines, and flights from CSV files.
- Analyze the network, including the number of airports, flights, and other statistics.
- Retrieve information about flights departing from a specific airport or operating in a particular city.
- Find the number of reachable airports, cities, and countries from a given airport.
- Discover the longest trips in terms of stops and distances.
- Identify articulation airports in the network.
- Search the best flight option according to user's needs, such as user's preferences regarding airlines and stops.


## Getting Started

### Prerequisites

- C++ compiler (minimum version: C++11)
- CMake (minimum version: 3.22)

### Installation

Clone the repository and compile the project using the following commands:

```bash
git clone https://github.com/rodrigoalvvs/flightManagement
cd flightManagement
```

To build the project:

```bash
mkdir build
cd build
cmake ..
make
```


## Usage

After building the project, you can run the executable:

```bash
./flightManagement
```


## Contributing

This project was developed by:

Rodrigo Alves (up202207478@fe.up.pt)

Nuno Mota (up202207549@fe.up.pt)

Duarte Padrão (up202206479@fe.up.pt)
