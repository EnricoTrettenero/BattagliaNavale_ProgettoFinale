//
// Created by vale on 27/12/22.
//

#ifndef BATTAGLIANAVALE_SRC_SUBMARINE_H_
#define BATTAGLIANAVALE_SRC_SUBMARINE_H_

#include "Ship.h"
class submarine : public ship
{
  static constexpr int kSubmarineDim = 3;
  static constexpr char kSubmarineChar = 'S';
 public:
  bool action(battleships::coordinate c) override;
 public:
  submarine(const battleships::coordinate &center, orientation orientation);

};

#endif //BATTAGLIANAVALE_SRC_SUBMARINE_H_
