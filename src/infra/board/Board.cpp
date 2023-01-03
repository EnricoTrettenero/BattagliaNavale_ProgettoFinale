//
// Created by vale on 27/12/22.
//

#include "../../../lib/board/Board.h"

std::ostream &operator<<(std::ostream &os, const board &b)
{
    std::string output;
    for (int i = 0; i < board::kDimBoard; ++i)
    {
        for (int j = 0; j < board::kDimBoard; ++j)
        {
            output += b.matrix()[i][j];
        }
        output += "\n";
    }
    return os << output;
}

std::vector<std::vector<char>> board::matrix() const
{
    std::vector<std::vector<char>> v(kDimBoard);
    for (int i = 0; i < kDimBoard; ++i)
    {
        for (int j = 0; j < kDimBoard; ++j)
        {
            v[i].push_back(_matrix[i][j]);
        }
    }
    return v;
}