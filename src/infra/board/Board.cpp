//
// Created by vale on 27/12/22.
//

#include "../../../lib/board/Board.h"
#include "../../../lib/def/Utility.h"
#include "../../../lib/ship/Battleship.h"
#include "../../../lib/ship/Submarine.h"
#include "../../../lib/ship/Support.h"
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
    output += lineWitNumber + "\n";

    for (int i = 0; i < board::kDimBoard; ++i)
    {
        std::string line(1, char(i + (battleships::coordinate::kMinY)));
        for (int j = 0; j < board::kDimBoard; ++j)
        {
            line += b.matrix()[i][j];
        }
        line = board::spaced(line);
        board::colorString(line);
        output += line + "\n";
    }
    return os << output;
}

void replaceAll(std::string &str, const std::string &from, const std::string &to)
{
    if (from.empty())
        return;
    size_t start_pos = 0;
    while ((start_pos = str.find(from, start_pos)) != std::string::npos)
    {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
    }
}

void board::colorString(std::string &s)
{
    std::string len = s.substr(kDimForTable); //remove the letters in front
    std::vector<std::pair<char, std::string>> colors{
        {char(battleship::kBattleshipChar), battleship::color()},
        {char(submarine::kSubmarineChar), submarine::color()},
        {char(support::kSupportChar), support::color()},
        {tolower(char(battleship::kBattleshipChar)), battleship::colorHit()},
        {tolower(char(submarine::kSubmarineChar)), submarine::colorHit()},
        {tolower(char(support::kSupportChar)), support::colorHit()}
    };
    std::string leftSpaces(kLeftSpace, ' ');
    std::string rightSpaces(kRightSpace, ' ');
    std::string color;
    for (const auto &a : colors)
    {
        color = a.second;
        std::string center = leftSpaces + a.first;
        center.append(rightSpaces);
        color.append(center);
        color.append(battleships::colors::reset());
        replaceAll(len, center, color);
    }
    s = s.substr(0, kDimForTable) + len;
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
        spacedString += std::string((kDimForTable - 1) / 2, ' ') + itr + std::string((kDimForTable - 1) % 2 + 1, ' ');
    }
    return spacedString;
}

const std::string &board::padWithSpace(std::string &s)
{
    int l = 1;
    std::string leftSpaces(kLeftSpace, ' ');
    std::string rightSpaces(kRightSpace, ' ');
    while (s.size() < kDimForTable)
    {
        if (l % 2 == 0)s.insert(0, leftSpaces);
        else s.append(rightSpaces);
        l++;
    }

//    if (kDimForTable > s.size()) s.insert(s.end(), kDimForTable - s.size(), ' ');
    return s;
}
