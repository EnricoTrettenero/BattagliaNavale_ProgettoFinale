//
// Created by vale on 27/12/22.
//

#ifndef BATTAGLIANAVALE_LIB_BOARD_ATTACK_H_
#define BATTAGLIANAVALE_LIB_BOARD_ATTACK_H_

#include "Board.h"
#include "../def/Utility.h"
class attack : public board
{
 private:
  int turnMatrix[kDimBoard][kDimBoard]{};
  static constexpr int kComputerChar = 'c';
  static constexpr int kHumanChar = 'p';
 public:
  void hit(battleships::coordinate xy);
  void water(battleships::coordinate xy);
  void find(battleships::coordinate xy);
  void reset();
  void reset(int turn);
  void nextTurn(); //add 1 to every cell of turnMatrix
  attack();
};

#endif //BATTAGLIANAVALE_LIB_BOARD_ATTACK_H_
