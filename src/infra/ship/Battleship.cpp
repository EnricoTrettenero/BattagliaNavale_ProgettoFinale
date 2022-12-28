//
// Created by vale on 27/12/22.
//

#include "../../../lib/ship/Battleship.h"
battleship::battleship(const battleships::coordinate &center, ship::orientation orientation) : ship(
    'C',
    std::vector<char>(kBattleshipDim, 'C'),
    kBattleshipDim,
    center,
    orientation) {}

bool battleship::action(battleships::coordinate c)
{
  return false;  //TODO
}
