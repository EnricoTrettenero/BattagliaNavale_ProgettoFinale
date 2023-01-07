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

bool battleship::action(battleships::coordinate c, defense ally_defense, defense enemy_defense, attack enemy_attack)
{
    return false;  //TODO
}
