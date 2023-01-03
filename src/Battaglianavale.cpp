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
    cout<<d.setShip(std::move(make_unique<battleship>(battleships::coordinate(5,'E'),ship::HORIZONTAL)));
    cout<<endl<<d<<endl;
    cout<<d.isShip(battleships::coordinate(5,'C'))<<endl;
    cout<<d.isShip(battleships::coordinate(5,'B'))<<endl;
    cout<<d.isShip(battleships::coordinate(4,'E'))<<endl;
    cout<<d.move(battleships::coordinate(5,'E'),battleships::coordinate(7,'D'))<<endl;
    cout<<d.move(battleships::coordinate(7,'D'),battleships::coordinate(10,'H'))<<endl;
    cout<<d.move(battleships::coordinate(5,'E'),battleships::coordinate(7,'D'))<<endl;
    cout<<endl<<d<<endl;
//    auto tmp = d.isShip(battleships::coordinate(10,'F'),5);
//    for (int i = 0; i < tmp.size(); ++i)
//    {
//        cout<<tmp.at(i)<<endl;
//    }
//    cout<<d.fire(battleships::coordinate(12,'G'));
//    cout<<d.fire(battleships::coordinate(12,'B'));
//    cout<<d.fire(battleships::coordinate(10,'B'));
//    cout<<d.fire(battleships::coordinate(10,'F'));
//    cout<<endl<<d<<endl;


//attack a = attack();
//cout<<a<<endl;
//a.hit(battleships::coordinate(5,'F'));
//a.water(battleships::coordinate(7,'B'));
//a.find(battleships::coordinate(3,'D'));
//a.nextTurn();
//    a.find(battleships::coordinate(4,'D'));
//    a.nextTurn();
//    a.find(battleships::coordinate(5,'D'));
//    a.nextTurn();
//cout<<endl<<a<<endl;
//a.reset(1);
// cout<<endl<<a<<endl;
  return 0;
}
