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
#include "../lib/Game.h"
using namespace std;
int main()
{
   unique_ptr<player> p1 = make_unique<human>();
   unique_ptr<player> p2 = make_unique<human>();
    game g = game(std::move(p1),std::move(p2));
  return 0;
}
