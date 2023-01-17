//
// Created by Enry on 22/12/2022.
//
#include <iostream>
#include <memory>
#include "../lib/ship/Battleship.h"
#include "../lib/board/Attack.h"
#include "../lib/board/Defense.h"
#include "../lib/Player.h"
#include "../lib/Human.h"
#include "../lib/Ai.h"
#include "../lib/Game.h"

using namespace std;
int mainf(int argc, char *argv[])
{
    if (argc < 3)
    {
        std::cout << "Error: 2 arguments are required." << std::endl;
        return 1;
    }
    char arg1 = argv[1][0];
    char arg2 = argv[2][0];
    if (arg1 != player::kComputerChar && arg1 != player::kHumanChar)
    {
        std::cout << "Error: First argument should be 'c' or 'p'." << std::endl;
        return 1;
    }
    if (arg2 != player::kComputerChar && arg2 != player::kHumanChar)
    {
        std::cout << "Error: Second argument should be 'c' or 'p'." << std::endl;
        return 1;
    }

    unique_ptr<player> p1;
    if (arg1 == player::kComputerChar) { p1 = make_unique<ai>("Computer 1"); }
    else { p1 = make_unique<human>("Umano 1"); }

    unique_ptr<player> p2;
    if (arg2 == player::kComputerChar) { p2 = make_unique<ai>("Computer 2"); }
    else { p2 = make_unique<human>("Umano 2"); }

    game g = game(std::move(p1), std::move(p2), "output.txt");
    g.startNewGame();

    return 0;
}
