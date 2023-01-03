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

bool support::action(battleships::coordinate c)
{
    //std::vector<battleships::coordinate> isShip(battleships::coordinate xy,unsigned int radius);
    //bool setShip(std::unique_ptr<ship> s);




    return false;
}
