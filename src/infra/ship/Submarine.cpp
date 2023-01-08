//
// Created by vale on 27/12/22.
//

#include "../../../lib/ship/Submarine.h"
submarine::submarine(const battleships::coordinate &center, orientation orientation) : ship(
    kSubmarineChar,
    std::vector<char>(kSubmarineDim, kSubmarineChar),
    kSubmarineDim,
    center,
    orientation
) {}
std::vector<std::pair<char, battleships::coordinate>> submarine::action(battleships::coordinate c)
{
    std::vector<std::pair<char, battleships::coordinate>> output = std::vector<std::pair<char, battleships::coordinate>>();
    int radius = 2;
    output.emplace_back(std::make_pair('M',center()));
    output.emplace_back(std::make_pair('M',c));

    for (int i = 0; i < radius; ++i)
    {
        for (int j = 0; j < radius; ++j)
        {
            if (c.x() + i - radius / 2 < 0 || c.x() + i - radius / 2 > 11 || c.y() + j - radius / 2 < 0
                || c.y() + j - radius / 2 > 11)
                throw std::invalid_argument("radius error");
            else
                output.emplace_back(std::make_pair('E', battleships::coordinate(c.x() + i - radius / 2 + 1,
                                                                                        c.y() + j - radius / 2 + 'A')));
        }
    }
    return output;
}
