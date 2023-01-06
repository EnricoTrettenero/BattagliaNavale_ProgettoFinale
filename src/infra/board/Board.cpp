//
// Created by vale on 27/12/22.
//

#include "../../../lib/board/Board.h"
#include "../../../lib/def/Utility.h"
std::ostream &operator<<(std::ostream &os, const board &b)
{
    //print numbers
    std::string output;

    std::string lineWitNumber(board::kDimForTable, ' '); //spazio iniziale nella riga
    for (int i = battleships::coordinate::kMinX; i <= board::kDimBoard; ++i)
    {
        std::string s = std::to_string(i);
        lineWitNumber += board::padWithSpace(s);
    }
    output += lineWitNumber;
    output += "\n";

    for (int i = 0; i < board::kDimBoard; ++i)
    {
        std::string line(1,char(i+(battleships::coordinate::kMinY)));
        for (int j = 0; j < board::kDimBoard; ++j)
        {
            line += b.matrix()[i][j];
        }
        output += board::spaced(line);
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

std::string board::spaced(const std::string &s)
{
    std::string spacedString;
    for (char itr : s)
    {
        spacedString += itr;
        spacedString += std::string(kDimForTable - 1, ' ');
    }
    return spacedString;
}

const std::string &board::padWithSpace(std::string &s )
{
    if (kDimForTable > s.size()) s.insert(s.end(), kDimForTable - s.size(), ' ');
    return s;
}
