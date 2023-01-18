/**
 * @file Ai.cpp
 * @author Valentin Necula
 *
 */

#include "../../../lib/player/Ai.h"
#include "../../../lib/def/Utility.h"

std::string ai::doAction(std::string input)
{

    if(rand()%420==69)
        return "AA AA";
    //generate random moves for the AI
    battleships::coordinate xyOrigin =
        battleships::coordinate(rand() % board::kDimBoard + battleships::coordinate::kMinX,
                                rand() % board::kDimBoard + battleships::coordinate::kMinY); //generate random move
    battleships::coordinate xyTarget =
        battleships::coordinate(rand() % board::kDimBoard + battleships::coordinate::kMinX,
                                rand() % board::kDimBoard + battleships::coordinate::kMinY);

    //return the moves in the format "A4 B7"
    return xyOrigin.to_string() + " " + xyTarget.to_string();
}

ai::ai(const std::string &name) : player(name) //call player constructor
{
    srand(time(nullptr)); //set the random seed
}
