//
// Created by vale on 27/12/22.
//

#ifndef BATTAGLIANAVALE__SUPPORT_H_
#define BATTAGLIANAVALE__SUPPORT_H_

#include "../def/Utility.h"
#include "Ship.h"
class support : public ship
{
  static constexpr int kSupportDim = 3;
  static constexpr int kSupportChar = 'E';
 public:
  bool action(battleships::coordinate c) override;
 public:
  support(const battleships::coordinate &center, orientation orientation);

};

#endif //BATTAGLIANAVALE__SUPPORT_H_
