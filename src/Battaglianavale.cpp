//
// Created by Enry on 22/12/2022.
//
#include <iostream>
#include "../lib/ship/Battleship.h"
#include "../lib/board/Attack.h"
#include "../lib/board/Defense.h"
#include "../lib/ship/Support.h"
#include "../lib/ship/Submarine.h"
using namespace std;

int main()
{
    defense d = defense();
    battleship s = battleship(battleships::coordinate(10,'B'),ship::VERTICAL);
    cout<<d.setShip(s );
    support ss = support(battleships::coordinate(10,'F'),ship::HORIZONTAL);
    cout<<d.setShip(ss);
    submarine sm = submarine(battleships::coordinate(12,'G'),ship::HORIZONTAL);
    cout<<d.setShip(sm);
    cout<<endl<<d<<endl;
  return 0;
}
