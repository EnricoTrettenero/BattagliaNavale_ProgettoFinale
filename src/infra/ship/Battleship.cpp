//
// Created by vale on 27/12/22.
//

#include "../../../lib/ship/Battleship.h"
battleship::battleship(const battleships::coordinate &center, ship::orientation orientation) : ship(
    kBattleshipChar,
    std::vector<char>(kBattleshipDim, kBattleshipChar),
    kBattleshipDim,
    center,
    orientation
) {}
std::vector<std::pair<std::string, battleships::coordinate>> battleship::action(battleships::coordinate c)
{
    return std::vector<std::pair<std::string, battleships::coordinate>>();
}

