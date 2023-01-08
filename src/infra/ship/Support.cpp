//
// Created by vale on 27/12/22.
//

#include "../../../lib/ship/Support.h"

support::support(const battleships::coordinate &center, orientation orientation) : ship(
    kSupportChar,
    std::vector<char>(kSupportDim, kSupportChar),
    kSupportDim,
    center,
    orientation
) {}
std::vector<std::pair<std::string, battleships::coordinate>> support::action(battleships::coordinate c)
{
    return std::vector<std::pair<std::string, battleships::coordinate>>();
}

