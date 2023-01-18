/**
 * @file Battleship.cpp
 * @author Valentin Necula
 *
 */

#include "../../../lib/ship/Battleship.h"

battleship::battleship(const battleships::coordinate &bow,
                       const battleships::coordinate &stern) : ship(
    kBattleshipChar,
    std::vector<char>(kBattleshipDim, kBattleshipChar),
    kBattleshipDim,
    bow,
    stern
) {}

std::vector<std::pair<char, battleships::coordinate>> battleship::action(battleships::coordinate c)
{
    //create the vector<pair<char,coordinate>> that will be returned
    std::vector<std::pair<char, battleships::coordinate>>
        output = std::vector<std::pair<char, battleships::coordinate>>();

    //insert 'C' as char representing the action "hit" and the target coordinate
    output.emplace_back('C', c);
    return output;
}

