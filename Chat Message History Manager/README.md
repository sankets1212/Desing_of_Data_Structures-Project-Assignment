AI&DS-4
Enrollment No-2403031590306

# Chat Message History Manager

## Overview

This project is a simple C++ console-based application that simulates a chat message history system. It stores incoming messages, allows sending them, and supports undo/redo functionality for sent messages. The project demonstrates the use of **queue**, **stack**, and timestamp tracking.

## Features

Receive Messages**: Add incoming messages into a queue.
Send Messages**: Move messages from the inbox (queue) to the sent history.
Undo Last Message**: Undo the most recently sent message using a stack.
Redo Last Message**: Redo the most recently undone message.
View Inbox**: Display all messages waiting in the inbox.
View Sent History**: Show all messages that have been successfully sent along with timestamps.

## Data Structures Used

Queue (`std::queue`)**: Stores incoming messages in FIFO order.
Stack (`std::stack`)**: Manages undo and redo actions (LIFO order).
Vector (`std::vector`)**: Keeps track of the overall sent message history.

## How to Run

1. Save the code in a file named `src.cpp`.
2. Open a terminal and compile the program:

   bash
   g++ -std=c++17 -O2 chatmgr.cpp -o chatmgr
   
3. Run the program:

   bash
   ./chatmgr
  
4. Use the interactive menu to:

   * Receive new messages.
   * Send messages.
   * Undo or redo sent messages.
   * View inbox and history.

## Example Menu Options

1) Receive Message** → Enter a new incoming message.
2) Send Message** → Send the earliest message in the inbox.
3) Undo** → Undo the last sent message.
4) Redo** → Redo the last undone message.
5) Show Inbox** → Show queued messages.
6) Show History** → Show sent messages with timestamps.
0) Exit** → Quit the program.

---

This project is intended as a learning exercise for implementing queues, stacks, and undo/redo logic in C++.
