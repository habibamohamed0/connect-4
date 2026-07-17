# Console Connect 4 (C++)

## Overview
This is a console-based implementation of the classic game Connect 4, built entirely in C++. 

**Note:** This was my Semester 1 introductory programming project. The goal of this project was to establish a strong foundation in core programming concepts without relying on advanced libraries or high-level automated functions. 

All the logic implemented, including the grid structure, turn-taking, and win-draw calculations, were built using simple step-by-step logic and explicit constraint steps.

## Features
*   **Two Game Modes:** Play locally against another human (PvP) or against a randomized Computer opponent (PvE).
*   **Manual Win Detection:** Custom algorithms using `do-while` loops to manually verify horizontal, vertical, and diagonal win states across a 2D array.
*   **Robust Input Validation:** Prevents game crashes by catching invalid data types (e.g., entering letters instead of numbers) and preventing players from selecting full columns.
*   **Dynamic Console UI:** The terminal actively updates and redraws the 6x7 grid after every valid turn.

## Technologies Used
*   **Language:**  C++
*   **Libraries:**  <iostream>, <cstdlib>, <ctime> (Standard libraries only)



  
## How to Play
 1.Compile the `connect4 game (team undefined).cpp` file using any standard C++ compiler (e.g., g++).

 2.Run the executable in your terminal.

 3.Select your game mode and input a number between 1 and 7 to drop your piece into the corresponding column.


## **Reflections & Future Improvements**
Looking back at this Semester 1 code, there are a few areas I would optimize today:

*   Extracting the redundant nested for loops used for printing the board into a single, reusable displayBoard() function.

*   Upgrading the computer opponent from random column selection to a defensive algorithm that actively blocks the player from connecting four pieces.
