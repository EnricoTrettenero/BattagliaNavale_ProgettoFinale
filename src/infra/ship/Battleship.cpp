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
std::vector<std::pair<char, battleships::coordinate>> battleship::action(battleships::coordinate c)
{
    std::vector<std::pair<char, battleships::coordinate>> output = std::vector<std::pair<char, battleships::coordinate>>();
    output.emplace_back(std::make_pair('C', c));
    return output;
}

