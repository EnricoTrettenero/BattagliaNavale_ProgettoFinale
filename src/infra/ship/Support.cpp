//
// Created by vale on 27/12/22.
//

#include "../../../lib/ship/Support.h"
support::support(const battleships::coordinate &bow,
                 const battleships::coordinate &stern) : ship(
    kSupportChar,
    std::vector<char>(kSupportDim, kSupportChar),
    kSupportDim,
    bow,
    stern
) {}

std::vector<std::pair<char, battleships::coordinate>> support::action(battleships::coordinate c)
{
    std::vector<std::pair<char, battleships::coordinate>>
        output = std::vector<std::pair<char, battleships::coordinate>>();
    int radius = 3;
    output.emplace_back('M', center());
    output.emplace_back('M', c);

    for (int i = 0; i < radius; ++i)
    {
        for (int j = 0; j < radius; ++j)
        {
            if (!(c.x() + i - radius / 2 < 0 || c.x() + i - radius / 2 > 11 || c.y() + j - radius / 2 < 0
                || c.y() + j - radius / 2 > 11))
            {
                if (getOrientation() == HORIZONTAL)
                {
                    if (!(j==1&&(i==0||i==1||i==2)))
                    {
                        output.emplace_back('S', battleships::coordinate(c.x() + i - radius / 2 + 1,
                                                                         c.y() + j - radius / 2 + 'A'));
                    }
                } else
                {
                    if (!(i==1&&(j==0||j==1||j==2)))
                    {
                        output.emplace_back('S', battleships::coordinate(c.x() + i - radius / 2 + 1,
                                                                         c.y() + j - radius / 2 + 'A'));
                    }
                }
            }
        }
    }
    return output;
}

