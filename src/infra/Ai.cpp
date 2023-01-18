//
// Created by Enry on 08/01/2023.
//
#include <iostream>
#include "../../lib/Ai.h"
#include "../../lib/def/Utility.h"

std::string ai::doAction(std::string input)
{
    battleships::coordinate xyOrigin = battleships::coordinate(rand() % 12 + 1, rand() % 12 + 65); //generate random move
    battleships::coordinate xyTarget = battleships::coordinate(rand() % 12 + 1, rand() % 12 + 65);

    return xyOrigin.to_string() + " " + xyTarget.to_string();
}
ai::ai(const std::string &name) : player(name) //call player constructor
{
    srand(time(nullptr)); //set the random seed
}
