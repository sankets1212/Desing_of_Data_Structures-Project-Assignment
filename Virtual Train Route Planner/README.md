# 🚆 Virtual Train Route Planner (C++ Project)

## 📌 Overview
The **Virtual Train Route Planner** is a C++ project that simulates train route navigation.  
It allows users to move between stations **forward and backward** (using a doubly linked list) and explore **loop routes** (using a circular linked list).

---

## ✨ Features
- Add stations to a route.
- Navigate **forward/backward** in a train route.
- Display the entire train route with **current position highlighted**.
- Support for **circular routes** like metro loops.
- Traverse the circular route infinitely.

---

## 🏗️ Data Structures Used
- **Doubly Linked List** → for linear train routes (forward & backward navigation).
- **Circular Linked List** → for metro/city loop train routes.

---

## ▶️ How to Run
1. Save the code as `src.cpp`
2. Compile using:
   bash
   g++ src.cpp -o planner



## Example Output
===== Virtual Train Route Planner =====
Train Route: [Station A] Station B Station C Station D
Moved forward to: Station B
Moved forward to: Station C
Train Route: Station A Station B [Station C] Station D
Moved backward to: Station B
Train Route: Station A [Station B] Station C Station D

===== Circular Train Route (Metro Loop) =====
Circular Route: [Loop 1] Loop 2 Loop 3 Loop 4 Loop 1 Loop 2 Loop 3 Loop 4
Moved to station: Loop 2
Circular Route: Loop 1 [Loop 2] Loop 3 Loop 4
