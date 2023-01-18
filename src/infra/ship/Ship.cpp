//
// Created by Enry on 29/12/2022.
//

#include <algorithm>
#include <utility>
#include "../../../lib/ship/Ship.h"

bool ship::hit(int position) //true if health=0, position reference the position on the array
{
    //if the position is not valid throw invalid_argument
    if (position < 0 || position > dim_ - 1) throw std::invalid_argument("hit position not valid");

    //lower the char of the armor of the ship in the position
    armor_.at(position) = char(tolower((unsigned char) armor_.at(position)));

    //TODO COMMENT
    return std::all_of(armor_.begin(), armor_.end(), [](char i)
    { return islower(i); });
}

void ship::repair_armor()
{
    //set the armor of the ship to full health
    for (int i = 0; i < dim(); i++)
    {
        armor_[i] = toupper(armor_[i]);
    }
}

ship::ship(char shipChar,
           std::vector<char> armor,
           int dim,
           const battleships::coordinate &bow,
           const battleships::coordinate &stern)
{

    shipChar_ = shipChar;
    armor_ = std::move(armor);

    //if the dimension deduced by stern and bow is not odd throw invalid_argument
    if ((bow.x() + stern.x()) % 2 != 0 || (bow.y() + stern.y()) % 2 != 0)
        throw std::invalid_argument("ships must have odd dimension");

    //set the centre of the ship to the midpoint between bow and stern
    int x = (bow.x() + 1 + stern.x() + 1) / 2;
    char y = char((bow.y_ch() + stern.y_ch()) / 2);
    battleships::coordinate centre(x, y);

    centre_ = centre;
    dim_ = dim;

    //set the orientation of the ship,
    if (bow.x() == stern.x())
    {
        orientation_ = VERTICAL;
        //if the dimension deduced by stern and bow is not in range throw invalid_argument
        if (std::abs(bow.y_ch() - stern.y_ch())+1 != dim){
            throw std::invalid_argument("ships must have correct coordinates");
        }
    } else if (bow.y() == stern.y())
    {
        orientation_ = HORIZONTAL;
        //if the dimension deduced by stern and bow is not in range throw invalid_argument
        if ((std::abs(bow.x()- stern.x())+1) != dim)
        {
            throw std::invalid_argument("ships must have correct coordinates");
        }
    } else throw std::invalid_argument("ships must have correct coordinates");
}

ship::~ship() = default;