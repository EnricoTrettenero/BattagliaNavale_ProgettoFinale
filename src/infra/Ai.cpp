//
// Created by Enry on 08/01/2023.
//
#include <iostream>
#include "../../lib/Ai.h"
#include "../../lib/def/Utility.h"

std::string ai::doAction(std::string input)
{
    battleships::coordinate xyOrigin = battleships::coordinate(rand() % 12 + 1, rand() % 12 + 65);
    battleships::coordinate xyTarget = battleships::coordinate(rand() % 12 + 1, rand() % 12 + 65);

    return xyOrigin.to_string() + " " + xyTarget.to_string();

}
std::string ai::doInsert(std::string input)
{
    battleships::coordinate coordinate = battleships::coordinate(rand() % 12 + 1, rand() % 12 + 65);
    char orientation = rand() % 2 == 0 ? 'H' : 'V';
    return coordinate.to_string() + " " + orientation;
}
std::string ai::to_string()
{
    return "Ai: " + name_;
}
ai::ai(const std::string &name) : player(name)
{

    srand(time(nullptr));
}
