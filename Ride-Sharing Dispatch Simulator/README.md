Enrollment No=2403031590306
AI&DS-4

                                                          



# Ride-Sharing Dispatch Simulator

## Overview

This is a simple C++ console-based project that simulates a ride-sharing dispatch system. It matches riders with drivers based on proximity (nearest driver first) and driver rating (higher rating is preferred when distances are equal). 
The project demonstrates the use of **queues** and **priority queues** in C++.

## Features

* Add drivers with location and rating.
* Add rider requests (pickup and drop-off locations).
* Dispatch riders to the nearest available driver using a priority queue.
* Maintain and display ride history.
* Show lists of drivers, pending riders, and completed rides.

## Data Structures Used

* **Queue (`std::queue`)**: Used for maintaining the rider request queue in FIFO order.
* **Priority Queue (`std::priority_queue`)**: Used to find the nearest available driver for a rider.
* **Vector (`std::vector`)**: Used for storing ride history.
* **Unordered Map (`std::unordered_map`)**: Used to manage driver records by ID.

## How to Run

1. Save the code in a file named `src.cpp`.
2. Open a terminal and compile the program:

   bash
   g++ -std=c++17 -O2 ridesim.cpp -o ridesim
3. Run the executable:

   bash
   ./ridesim
   
4. Use the interactive menu to add drivers, add riders, dispatch rides, and view details.

## Example Menu Options

1) Add Driver** → Add a new driver with name, location, and rating.
2) Add Rider** → Add a new rider request.
3) Dispatch** → Match a rider with the nearest available driver.
4) Show Drivers** → View driver details.
5) Show Riders** → View the pending rider queue.
6) Show History** → View completed ride history.
0) Exit** → Quit the program.

---

This project is intended as a learning exercise for data structures and simulation in C++.
