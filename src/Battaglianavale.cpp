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
using namespace std;

int main()
{
    defense d = defense();
    unique_ptr<ship> s = make_unique<battleship>(battleships::coordinate(10,'B'),ship::VERTICAL);
    cout<<d.setShip(std::move(s));
    unique_ptr<ship> ss = make_unique<support>(battleships::coordinate(10,'F'),ship::HORIZONTAL);
    cout<<d.setShip(std::move(ss));
    unique_ptr<ship> sm = make_unique<submarine>(battleships::coordinate(12,'G'),ship::HORIZONTAL);
    cout<<d.setShip(std::move(sm));
    cout<<endl<<d<<endl;
  return 0;
}
