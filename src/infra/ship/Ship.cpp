//
// Created by Enry on 29/12/2022.
//

#include <algorithm>
#include <utility>
#include "../../../lib/ship/Ship.h"

bool ship::hit(int position) //true if health=0, position reference the position on the array
{
    if (position < 0 || position > dim_ - 1) throw std::invalid_argument("hit position not valid");

    armor_.at(position) = char(tolower((unsigned char) armor_.at(position)));
    return std::all_of(armor_.begin(), armor_.end(), [](char i)
    { return islower(i); });
}

void ship::repair_armor()
{
    for (int i = 0; i < dim(); i++)
    {
        armor_[i] = toupper(armor_[i]);
    }
}
ship::ship(char shipChar,
           std::vector<char> armor,
           const battleships::coordinate &bow,
           const battleships::coordinate &stern)
{
    shipChar_ = shipChar;
    armor_ = std::move(armor);
    if ((bow.x() + stern.x()) % 2 != 0 || (bow.y() + stern.y()) % 2 != 0) throw std::invalid_argument("ships must have odd dimension");
    int x = (bow.x() + stern.x()) / 2;
    char y = char((bow.y() + stern.y()) / 2);
    battleships::coordinate center(x, y);
    center_ = center;
    if (bow.x() == stern.x())
    {
        orientation_ = VERTICAL;
        dim_ = bow.x() - stern.x();
    } else if (bow.y() == stern.y())
    {
        orientation_ = HORIZONTAL;
        dim_ = bow.y() - stern.y();
    } else throw std::invalid_argument("ships must have correct coordinates");

}

ship::~ship() = default;