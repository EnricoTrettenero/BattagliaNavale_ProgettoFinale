//
// Created by vale on 27/12/22.
//

#ifndef BATTAGLIANAVALE_LIB_SHIP_SUBMARINE_H_
#define BATTAGLIANAVALE_LIB_SHIP_SUBMARINE_H_

#include "Ship.h"
class submarine : public ship
{


 public:
  virtual std::vector<std::pair<char, battleships::coordinate>> action(battleships::coordinate c) override;
  static std::string className() { return "submarine"; }
  static constexpr int kSubmarineChar = 'E';
  //static constexpr char red[] = "\033[42;1m"; //molto più elegante ma c++11 non lo permette
  static constexpr auto &color()
  { return "\033[43m"; }
  static constexpr auto &colorHit()
  { return "\033[43;7m"; }
  submarine(const battleships::coordinate &bow,
            const battleships::coordinate &stern);
  static constexpr int kSubmarineDim = 1;

};

#endif //BATTAGLIANAVALE_LIB_SHIP_SUBMARINE_H_
