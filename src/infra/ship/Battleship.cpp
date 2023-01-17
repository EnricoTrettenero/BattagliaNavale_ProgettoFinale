//
// Created by vale on 27/12/22.
//

#include "../../../lib/ship/Battleship.h"
battleship::battleship(const battleships::coordinate &bow,
                       const battleships::coordinate &stern) : ship(
    kBattleshipChar,
    std::vector<char>(kBattleshipDim, kBattleshipChar),
    kBattleshipDim,
    bow,
    stern
) {}

std::vector<std::pair<char, battleships::coordinate>> battleship::action(battleships::coordinate c)
{
    std::vector<std::pair<char, battleships::coordinate>>
        output = std::vector<std::pair<char, battleships::coordinate>>();
    output.emplace_back('C', c);
    return output;
}

