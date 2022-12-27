//
// Created by vale on 27/12/22.
//

#include "../../../lib/ship/Submarine.h"
submarine::submarine(const battleships::coordinate &center, orientation orientation) : ship(
    std::vector(kSubmarineDim, kSubmarineChar),
    kSubmarineDim,
    center,
    orientation
) {}

bool submarine::action(battleships::coordinate c)
{
  return false;  //TODO
}

