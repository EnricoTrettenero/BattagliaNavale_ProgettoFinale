//
// Created by vale on 27/12/22.
//

#ifndef BATTAGLIANAVALE__BATTLESHIP_H_
#define BATTAGLIANAVALE__BATTLESHIP_H_

#include "Ship.h"
class battleship : public ship
{
  static constexpr int kBattleshipDim = 5;
  static constexpr char kBattleshipChar = 'C';
 public:
  bool action(battleships::coordinate c) override;
 public:
  battleship(const battleships::coordinate &center, orientation orientation);
};

#endif //BATTAGLIANAVALE__BATTLESHIP_H_
