cmake_minimum_required(VERSION 3.24)
project(BattagliaNavale)

set(CMAKE_CXX_STANDARD 17)

add_executable(BattagliaNavale src/Battaglianavale.cpp lib/ship/Ship.h lib/def/Utility.h lib/ship/Submarine.h lib/ship/Battleship.h lib/ship/Support.h src/ship/Support.cpp src/ship/Submarine.cpp src/ship/Battleship.cpp)