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
//   unique_ptr<player> p1 = make_unique<human>("1");
//   unique_ptr<player> p2 = make_unique<human>("1");
//    game g = game(std::move(p1),std::move(p2),"output.txt");

//    unique_ptr<ship>s = make_unique<battleship>(battleships::coordinate(5,'F'),ship::VERTICAL);
//    defense d = defense();
//    d.setShip(std::move(s));
//    cout<<d<<endl;
    defense d = defense();
    cout << d << endl;
    d.setShip(move(make_unique<battleship>(battleships::coordinate(5, 'C'), battleship::HORIZONTAL)));
    cout << d.to_string() << endl;
    auto t = d.useShip(battleships::coordinate(5, 'C'), battleships::coordinate(10, 'C'));
    cout << d.fire(battleships::coordinate(4, 'C'));
    cout << d.fire(battleships::coordinate(5, 'C'));
    cout << d.fire(battleships::coordinate(3, 'C'));
    cout << d.fire(battleships::coordinate(6, 'C'));
    // cout<<d.fire(battleships::coordinate(7,'C'));
    d.move(battleships::coordinate(5, 'C'), battleships::coordinate(10, 'F'));
    d.setShip(move(make_unique<submarine>(battleships::coordinate(5, 'C'), battleship::HORIZONTAL)));
    d.setShip(move(make_unique<submarine>(battleships::coordinate(12, 'L'), battleship::HORIZONTAL)));

    cout << endl << d << endl;
    cout << d.isShip(battleships::coordinate(5, 'C'));
    cout << d.isShip(battleships::coordinate(1, 'A'));
    auto r = d.isShip(battleships::coordinate(7, 'E'), 5);
   cout<< d.isDamaged(battleships::coordinate(8, 'F'));
    d.repair_ship(battleships::coordinate(8, 'F'));
    cout<<d.isDamaged(battleships::coordinate(8, 'F'));
    cout << d << endl;
    return 0;
}
