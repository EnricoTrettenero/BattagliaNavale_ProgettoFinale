cmake_minimum_required(VERSION 3.24)
project(BattagliaNavale)

set(CMAKE_CXX_STANDARD 14)

add_executable(BattagliaNavale src/battaglia_navale.cpp lib/ship/Ship.h lib/def/Utility.h lib/ship/Submarine.h lib/ship/Battleship.h lib/ship/Support.h src/infra/ship/Support.cpp src/infra/ship/Submarine.cpp src/infra/ship/Battleship.cpp src/infra/Game.cpp lib/Game.h src/infra/player/Player.cpp lib/player/Player.h src/infra/board/Board.cpp lib/board/Board.h src/infra/board/Attack.cpp lib/board/Attack.h src/infra/board/Defense.cpp lib/board/Defense.h lib/player/Human.h lib/player/Ai.h src/infra/ship/Ship.cpp src/infra/player/Human.cpp src/infra/player/Ai.cpp lib/player/Replay.h src/infra/player/Replay.cpp lib/Game.hpp src/replay.cpp lib/ReplayGame.h src/infra/ReplayGame.cpp)