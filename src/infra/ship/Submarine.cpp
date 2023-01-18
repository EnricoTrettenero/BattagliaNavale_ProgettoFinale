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
    std::vector<std::pair<char, battleships::coordinate>>
        output = std::vector<std::pair<char, battleships::coordinate>>();
    int radius = 5;
    output.emplace_back('M', center());
    output.emplace_back('M', c);

    for (int i = 0; i < radius; ++i)
    {
        for (int j = 0; j < radius; ++j)
        {
            if (c.x() + i - radius / 2 < 0 || c.x() + i - radius / 2 > 11 || c.y() + j - radius / 2 < 0
                || c.y() + j - radius / 2 > 11) {}
            else
                output.emplace_back('E', battleships::coordinate(c.x() + i - radius / 2 + 1,
                                                                                c.y() + j - radius / 2 + 'A'));
        }
    }
    return output;
}
