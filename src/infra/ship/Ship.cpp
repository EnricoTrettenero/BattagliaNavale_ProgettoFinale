//
// Created by Enry on 29/12/2022.
//

#include "../../../lib/ship/Ship.h"

bool ship::hit(int position) //true if health=0, position reference the position on the array
{
    if (position < 0 || position > dim_ - 1) throw std::invalid_argument("hit position not valid");

    armor_.at(position) = char(tolower((unsigned char) armor_.at(position)));
    return std::all_of(armor_.begin(), armor_.end(), [](char i)
    { return islower(i); });
}

ship::~ship() = default;