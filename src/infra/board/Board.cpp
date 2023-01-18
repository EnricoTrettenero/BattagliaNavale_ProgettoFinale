/**
 * @file Board.cpp
 * @author Davide Redana
 *
 */

#include <sstream>
#include "../../../lib/board/Board.h"
#include "../../../lib/def/Utility.h"
#include "../../../lib/ship/Battleship.h"
#include "../../../lib/ship/Submarine.h"
#include "../../../lib/ship/Support.h"
#include "../../../lib/board/Attack.h"

std::ostream &operator<<(std::ostream &os, const board &b)
{
    //print board
    return os << b.to_string();
}

//utility function for board output
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

//add color to string
void board::colorString(std::string &s)
{
    std::string len = s.substr(kDimForTable); //remove the letters in front
    std::vector<std::pair<char, std::string>> colors{
        {char(battleship::kBattleshipChar), battleship::color()},
        {char(submarine::kSubmarineChar), submarine::color()},
        {char(support::kSupportChar), support::color()},
        {char(attack::kWaterChar), attack::colorWater()},
        {char(attack::kFindChar), attack::colorFind()},
        {char(attack::kHitChar), attack::colorHit()},
        {tolower(char(battleship::kBattleshipChar)), battleship::colorHit()},
        {tolower(char(submarine::kSubmarineChar)), submarine::colorHit()},
        {tolower(char(support::kSupportChar)), support::colorHit()}
    }; //insert possible colors
    //add space to char
    std::string leftSpaces(kLeftSpace, ' ');
    std::string rightSpaces(kRightSpace, ' ');
    std::string color;
    //adding color
    for (const auto &a : colors)
    {
        color = a.second;
        std::string centre = leftSpaces + a.first;
        centre.append(rightSpaces);
        color.append(centre);
        color.append(battleships::colors::reset());
        replaceAll(len, centre, color);
    }
    s = s.substr(0, kDimForTable) + len;
}

//std::vector<std::vector<char>> board::matrix() const //TODO
//{
//    std::vector<std::vector<char>> v(kDimBoard);
//    for (int i = 0; i < kDimBoard; ++i)
//    {
//        for (int j = 0; j < kDimBoard; ++j)
//        {
//            v[i].push_back(_matrix[i][j]);
//        }
//    }
//    return v;
//}

//utility print, add space to string
std::string board::spaced(const std::string &s)
{
    std::string spacedString;
    for (char itr : s)
    {
        spacedString += std::string((kDimForTable - 1) / 2, ' ') + itr + std::string((kDimForTable - 1) % 2 + 1, ' ');
    }
    return spacedString;
}

//utility print, add padding
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
    return s;
}

//print the board with color
std::string board::to_string() const
{
    std::string output;
    std::string lineWitNumber(board::kDimForTable, ' '); //print first line with number
    for (int i = battleships::coordinate::kMinX; i <= board::kDimBoard; ++i)
    {
        std::string s = std::to_string(i);
        lineWitNumber += board::padWithSpace(s);
    }
    output += lineWitNumber + "\n";

    for (int i = 0; i < board::kDimBoard; ++i)
    {
        std::string line(1, char(i + (battleships::coordinate::kMinY)));
        for (int j = 0; j < board::kDimBoard; ++j) { line += _matrix[i][j]; }
        line = board::spaced(line);
        board::colorString(line); //add color
        output += line + "\n";
    }
    return output;
}

//print board without colors
std::string board::to_stringNoColors() const
{
    std::string output;
    std::string lineWitNumber(board::kDimForTable, ' ');
    for (int i = battleships::coordinate::kMinX; i <= board::kDimBoard; ++i)
    {
        std::string s = std::to_string(i);
        lineWitNumber += board::padWithSpace(s);
    }
    output += lineWitNumber + "\n";

    for (int i = 0; i < board::kDimBoard; ++i)
    {
        std::string line(1, char(i + (battleships::coordinate::kMinY)));
        for (int j = 0; j < board::kDimBoard; ++j) { line += _matrix[i][j]; }
        line = board::spaced(line);
        output += line + "\n";
    }
    return output;
}

//take 2 board and print on side
std::string board::concat2string(const std::string &str1, const std::string &str2)
{
    int i = 0;
    std::stringstream ss1(str1);
    std::stringstream ss2(str2);
    std::string output;
    while (i < str1.length())
    {
        std::string first, second;
        std::getline(ss1, first, '\n');
        std::getline(ss2, second, '\n');
        output += (first + "   " + second + '\n'); //concat the 2 line for each line of boards
        i += first.length() + 1;
    }
    return output;
}