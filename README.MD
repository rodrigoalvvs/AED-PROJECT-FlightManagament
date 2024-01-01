# SkyNavigator (AED 23/24)

This C++ project implements a Flight Management System that allows users to analyze and query information about airports, airlines, and flights within a network.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Usage](#usage)
- [Functionality](#functionality)
  - [1. Data Loading](#1-data-loading)
  - [2. Network Analysis](#2-network-analysis)
  - [3. Flight Information](#3-flight-information)
  - [4. Airport Search](#4-airport-search)
  - [5. Flight Path Analysis](#5-flight-path-analysis)
- [Contributing](#contributing)
- [License](#license)


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

- C++ compiler

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

After building the project, you can run the executable:

```bash
./flightManagement
```




## Installation

Provide instructions on how to install and set up your project. Include any dependencies that need to be installed and any configuration steps.

```bash
# Example installation steps
git clone https://github.com/your-username/your-project.git
cd your-project
make