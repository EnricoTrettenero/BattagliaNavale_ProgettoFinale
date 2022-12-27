cmake_minimum_required(VERSION 3.24)
project(BattagliaNavale)

set(CMAKE_CXX_STANDARD 17)

add_executable(BattagliaNavale src/Battaglianavale.cpp lib/ship/Ship.h lib/def/Utility.h lib/ship/Submarine.h lib/ship/Battleship.h lib/ship/Support.h src/infra/ship/Support.cpp src/infra/ship/Submarine.cpp src/infra/ship/Battleship.cpp src/infra/Game.cpp lib/Game.h src/infra/Player.cpp lib/Player.h src/infra/board/Board.cpp lib/board/Board.h src/infra/board/Attack.cpp lib/board/Attack.h src/infra/board/Defense.cpp lib/board/Defense.h)