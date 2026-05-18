# Student Grade Manager

A command-line student grade management system built in C++ using concepts from Phase 1 of my performance engineering roadmap.

## Features

- Loads student data from file on startup (falls back to default data on first run)
- Sorts students by average grade using a custom comparator
- Search for a student by full name
- Saves data back to file on every run
- Times the sort operation with chrono

## Concepts Used

- Structs with nested std::vector
- const references for all read-only parameters
- std::ranges::sort with custom comparator
- Pointer-based search returning nullptr for not found
- File persistence with std::ifstream and std::ofstream
- std::chrono timing

## Sample Output
Time = 11 microseconds
Student Name: Alice Chen
Student ID: 3
Average Grade: 91.5

## Environment
- Compiler: g++ with -std=c++20
- OS: Windows
- CPU: AMD Ryzen 5 Pro
