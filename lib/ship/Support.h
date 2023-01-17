/**
 * @file Support.h
 * @author TODO
 * @brief This class represents a support ship
 * @date 2023-01-17
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef BATTAGLIANAVALE_LIB_SHIP_SUPPORT_H_
#define BATTAGLIANAVALE_LIB_SHIP_SUPPORT_H_

#include "../def/Utility.h"
#include "Ship.h"
class support : public ship
{

  static constexpr int kSupportDim = 3;
 public:
  static std::string className() { return "support"; }
  virtual std::vector<std::pair<char, battleships::coordinate>> action(battleships::coordinate c) override;

  static constexpr int kSupportChar = 'S';
  //static constexpr char red[] = "\033[42;1m"; //molto più elegante ma c++11 non lo permette
  static constexpr auto &color() { return "\033[41m"; }
  static constexpr auto &colorHit() { return "\033[41;7m"; }
  support(const battleships::coordinate &bow, const battleships::coordinate &stern);

};

#endif //BATTAGLIANAVALE_LIB_SHIP_SUPPORT_H_
