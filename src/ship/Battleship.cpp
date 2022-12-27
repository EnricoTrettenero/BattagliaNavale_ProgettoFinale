//
// Created by vale on 27/12/22.
//

#include "../../lib/ship/Battleship.h"
battleship::battleship(const battleships::coordinate &center, ship::orientation orientation) : ship(
    std::vector(kBattleshipDim, kBattleshipChar),
    kBattleshipDim,
    center,
    orientation
) {}

bool battleship::action(battleships::coordinate c)
{
  return false;  //TODO
}
