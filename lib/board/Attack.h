/**
 * @file Attack.h
 * @author TODO
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

    //matrix of ints that represents the turn board
    int turnMatrix[kDimBoard][kDimBoard]{};

    //static constexpr ints that represent both human and bot chars
    static constexpr int kComputerChar = 'c';
    static constexpr int kHumanChar = 'p';

public:
    /**
    * @brief insert a X on the board if a enemy board on the enemy defense board is hit
    *
    * @param battleships::coordinate which represents the coordinate on the enemy defense board
    */
    void hit(battleships::coordinate xy);

    /**
    * @brief insert a 0 on the board if a no enemy board on the enemy defense board is hit
    *
    * @param battleships::coordinate which represents the coordinate on the enemy defense board
    */
    void water(battleships::coordinate xy);

    /**
    * @brief insert a Y on the board if the submarine has found a enemy ship
     * on the enemy defense board
    *
    * @param battleships::coordinate which represents the coordinate on the enemy defense board
    */
    void find(battleships::coordinate xy);

    /**
    * @brief reset the board
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
