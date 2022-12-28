//
// Created by vale on 27/12/22.
//

#include "../../../lib/ship/Support.h"

support::support(const battleships::coordinate &center, orientation orientation) : ship(
    'E',
    std::vector<char>(kSupportDim, 'E'),
    kSupportDim,
    center,
    orientation
) {}

bool support::action(battleships::coordinate c)
{
  return false;
}
