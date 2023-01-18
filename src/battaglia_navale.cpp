/**
 * @file BattagliaNavale.cpp
 * @author Enrico Trettenero
 *
 */
#include <iostream>
#include <memory>
#include "../lib/ship/Battleship.h"
#include "../lib/board/Attack.h"
#include "../lib/board/Defense.h"
#include "../lib/player/Player.h"
#include "../lib/player/Human.h"
#include "../lib/player/Ai.h"
#include "../lib/Game.h"

using namespace std;
int main(int argc, char *argv[])
{
    cout << "Battleship Game" << endl;
    cout << R"(
                             ~~
		                  __/___
		           _____/______|
		   _______/_____\_______\_____
	  	   \             < < <    DVE |
		 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~)" << endl << endl;

    //first arg is the path
    if (argc < 2)
    {
        std::cout << "Error: 2 arguments are required." << std::endl;
        return 1;
    }
    char arg1 = argv[1][0]; //"Pc"
    char arg2 = argv[1][1]; //"pC"

    //validate argument
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

    //create player 1
    unique_ptr<player> p1;
    if (arg1 == player::kComputerChar) { p1 = make_unique<ai>("Computer 1"); }
    else { p1 = make_unique<human>("Umano 1"); }

    //create player 2
    unique_ptr<player> p2;
    if (arg2 == player::kComputerChar) { p2 = make_unique<ai>("Computer 2"); }
    else { p2 = make_unique<human>("Umano 2"); }

    //start the game
    game g = game(std::move(p1), std::move(p2), "output.txt");
    g.startNewGame();

    return 0;
}
