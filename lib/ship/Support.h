//
// Created by vale on 27/12/22.
//

#ifndef BATTAGLIANAVALE_LIB_SHIP_SUPPORT_H_
#define BATTAGLIANAVALE_LIB_SHIP_SUPPORT_H_

#include "../def/Utility.h"
#include "Ship.h"
class support : public ship
{
  static constexpr int kSupportDim = 3;
 public:
  virtual std::vector<std::pair<char,battleships::coordinate>> action(battleships::coordinate c) override;

  static constexpr int kSupportChar = 'S';
  //static constexpr char red[] = "\033[42;1m"; //molto più elegante ma c++11 non lo permette
  static constexpr auto& color() { return "\033[41m"; }
  static constexpr auto& colorHit() { return "\033[41;7m"; }
 public:
  support(const battleships::coordinate &center, orientation orientation);

};

#endif //BATTAGLIANAVALE_LIB_SHIP_SUPPORT_H_
