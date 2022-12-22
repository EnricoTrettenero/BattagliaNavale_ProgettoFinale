cmake_minimum_required(VERSION 3.24)
project(BattagliaNavale)

set(CMAKE_CXX_STANDARD 14)

add_executable(BattagliaNavale src/battaglianavale.cpp lib/def/Ship.h lib/def/Utility.h)
