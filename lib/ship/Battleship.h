/**
 * @file Battleship.h
 * @author TODO
 * @brief This class represents a battleship
 * @date 2023-01-17
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef BATTAGLIANAVALE_LIB_SHIP_BATTLESHIP_H_
#define BATTAGLIANAVALE_LIB_SHIP_BATTLESHIP_H_

#include "Ship.h"
class battleship : public ship
{

  static constexpr int kBattleshipDim = 5;

 public:
  battleship(const battleships::coordinate &bow, const battleships::coordinate &stern);
  static std::string className() { return "battleship"; }
  virtual std::vector<std::pair<char, battleships::coordinate>> action(battleships::coordinate c) override;
  static constexpr int kBattleshipChar = 'C';
  //static constexpr char color[] = "\033[42;1m"; //molto più elegante ma c++11 non lo permette
  static constexpr auto &color()
  { return "\033[42m"; }
  static constexpr auto &colorHit()
  { return "\033[42;7m"; }
};

#endif //BATTAGLIANAVALE_LIB_SHIP_BATTLESHIP_H_
