//
// Created by Enry on 22/12/2022.
//
#include <iostream>
#include <memory>
#include "../lib/ship/Battleship.h"
#include "../lib/board/Attack.h"
#include "../lib/board/Defense.h"
#include "../lib/ship/Support.h"
#include "../lib/ship/Submarine.h"
#include "../lib/Player.h"
#include "../lib/Human.h"
#include "../lib/Ai.h"
#include "../lib/Game.h"
#include "../lib/ReplayGame.h"

using namespace std;
int mainf()
{
    game g = game(make_unique<ai>("player1"), make_unique<ai>("player2"),"input.txt");
    g.startNewGame();

    return 0;
}
