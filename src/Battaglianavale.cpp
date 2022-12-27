//
// Created by Enry on 22/12/2022.
//
#include <iostream>
#include "../lib/ship/Battleship.h"
using namespace std;

int main()
{
  battleships::coordinate d(2, 'B');
  battleship b{d, ship::VERTICAL};
  battleships::coordinate c{2,'B'};
  return 0;
}
