//
// Created by vale on 27/12/22.
//

#ifndef BATTAGLIANAVALE__BATTLESHIP_H_
#define BATTAGLIANAVALE__BATTLESHIP_H_

#include "Ship.h"
class battleship : public ship
{
  static constexpr int kBattleshipDim = 5;

 public:
  bool action(battleships::coordinate c, defense ally_defense, defense enemy_defense, attack enemy_attack) override;
  battleship(const battleships::coordinate &center, orientation orientation);
  static constexpr int kBattleshipChar = 'C';
  //static constexpr char color[] = "\033[42;1m"; //molto più elegante ma c++11 non lo permette
  static constexpr auto& color() { return "\033[42m"; }
  static constexpr auto& colorHit() { return "\033[42;7m"; }
};

#endif //BATTAGLIANAVALE__BATTLESHIP_H_
