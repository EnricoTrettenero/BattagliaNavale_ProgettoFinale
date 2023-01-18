//
// Created by vale on 27/12/22.
//

#include "../../../lib/ship/Submarine.h"
submarine::submarine(const battleships::coordinate &bow,
                     const battleships::coordinate &stern) : ship(
    kSubmarineChar,
    std::vector<char>(kSubmarineDim, kSubmarineChar),
    kSubmarineDim,
    bow,
    stern
) {}

std::vector<std::pair<char, battleships::coordinate>> submarine::action(battleships::coordinate c)
{
    //create the vector<pair<char,coordinate>> that will be returned
    std::vector<std::pair<char, battleships::coordinate>>
        output = std::vector<std::pair<char, battleships::coordinate>>();
    int radius = 5; //radius of the submarine action

    //the first two pairs will be for the move
    output.emplace_back(std::make_pair('M', center())); //action: "M"=move from coordinate centre...
    output.emplace_back(std::make_pair('M', c)); //...action: "M"=move to coordinate c

    for (int i = 0; i < radius; ++i)
    {
        for (int j = 0; j < radius; ++j)
        {
            //if radius goes out of range of the board do nothing
            if (c.x() + i - radius / 2 < 0 || c.x() + i - radius / 2 > 11 || c.y() + j - radius / 2 < 0
                || c.y() + j - radius / 2 > 11) {}

            //emplace_back the pairs needed for the exploration
            else
                output.emplace_back(std::make_pair('E', battleships::coordinate(c.x() + i - radius / 2 + 1,
                                                                                c.y() + j - radius / 2 + 'A')));
        }
    }
    return output;
}
