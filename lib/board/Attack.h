/**
 * @file Attack.h
 * @author Davide Redana
 * @brief This class represents the attack board
 *
 */

#ifndef BATTAGLIANAVALE_LIB_BOARD_ATTACK_H_
#define BATTAGLIANAVALE_LIB_BOARD_ATTACK_H_

#include "Board.h"
#include "../def/Utility.h"

class attack : public board
{
private:

    //matrix of ints that represents the turn board for the special move AA number
    int turnMatrix[kDimBoard][kDimBoard]{};


public:
  static constexpr int kFindChar = 'Y';
  static constexpr int kWaterChar = 'O';
  static constexpr int kHitChar = 'X';
  //static constexpr auto used for colors
  static constexpr auto &colorFind()
  { return "\033[44;7m"; }
  static constexpr auto &colorWater()
  { return "\033[44m"; }
  static constexpr auto &colorHit()
  { return "\033[101m"; }
    /**
    * @brief insert a X on the board (happens when a enemy board on the enemy defense board is hit)
    *
    * @param battleships::coordinate which represents the coordinate on the enemy defense board
    */
    void hit(battleships::coordinate xy);

    /**
    * @brief insert a 0 on the board (happens when no enemy board on the enemy defense board is hit)
    *
    * @param battleships::coordinate which represents the coordinate on the enemy defense board
    */
    void water(battleships::coordinate xy);

    /**
    * @brief insert a Y on the board (happens when the submarine has found a enemy ship)
     * on the enemy defense board
    *
    * @param battleships::coordinate which represents the coordinate on the enemy defense board
    */
    void find(battleships::coordinate xy);

    /**
    * @brief reset the turn board (call with AA command)
    */
    void reset();

    /**
    * @brief reset the chars inserted before the indicated turn
    *
    * @param turn before the which we reset the chars on the board
    */
    void reset(int turn);

    //add 1 to every cell of turnMatrix
    void nextTurn();

    /**
    * @brief Construct a new attack board
    */
    attack();

};

#endif //BATTAGLIANAVALE_LIB_BOARD_ATTACK_H_
