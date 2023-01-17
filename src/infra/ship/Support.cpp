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
)
{}
std::vector<std::pair<char, battleships::coordinate>> support::action(battleships::coordinate c)
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
            if (!(c.x() + i - radius / 2 < 0 || c.x() + i - radius / 2 > 11 || c.y() + j - radius / 2 < 0
                || c.y() + j - radius / 2 > 11))
            {
                if (getOrientation() == HORIZONTAL)
                {
                    if (battleships::coordinate(c.x() + i - radius / 2 + 1, c.y() + j - radius / 2 + 'A') != center()
                        && battleships::coordinate(c.x() + i - radius / 2 + 1, c.y() + j - radius / 2 + 'A')
                            != battleships::coordinate(center().x(), center().y_ch())
                        && battleships::coordinate(c.x() + i - radius / 2 + 1, c.y() + j - radius / 2 + 'A') !=
                            battleships::coordinate(center().x()+2, center().y_ch()))
                    {
                        output.emplace_back('S', battleships::coordinate(c.x() + i - radius / 2 + 1,
                                                                         c.y() + j - radius / 2 + 'A'));
                    }
                } else
                {
                    if (battleships::coordinate(c.x() + i - radius / 2 + 1, c.y() + j - radius / 2 + 'A') != center()
                        && battleships::coordinate(c.x() + i - radius / 2 + 1, c.y() + j - radius / 2 + 'A') !=
                            battleships::coordinate(center().x() +1, center().y_ch()-1)
                        && battleships::coordinate(c.x() + i - radius / 2 + 1, c.y() + j - radius / 2 + 'A') !=
                            battleships::coordinate(center().x() + 1, center().y_ch()+1))
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

