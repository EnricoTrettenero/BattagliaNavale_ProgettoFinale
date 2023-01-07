//
// Created by vale on 27/12/22.
//

#ifndef BATTAGLIANAVALE_SRC_SUBMARINE_H_
#define BATTAGLIANAVALE_SRC_SUBMARINE_H_

#include "Ship.h"
class submarine : public ship
{
  static constexpr int kSubmarineDim = 1;

 public:
  bool action(battleships::coordinate c, defense ally_defense, defense enemy_defense, attack ally_attack) override;
  static constexpr int kSubmarineChar = 'S';
  //static constexpr char red[] = "\033[42;1m"; //molto più elegante ma c++11 non lo permette
  static constexpr auto& color() { return "\033[43m"; }
  static constexpr auto& colorHit() { return "\033[43;7m"; }
 public:
  submarine(const battleships::coordinate &center, orientation orientation);

};

#endif //BATTAGLIANAVALE_SRC_SUBMARINE_H_
