/**
 * @file Battleship.h
 * @author Valentin Necula
 * @brief This class represents a battleship
 *
 */

#ifndef BATTAGLIANAVALE_LIB_SHIP_BATTLESHIP_H_
#define BATTAGLIANAVALE_LIB_SHIP_BATTLESHIP_H_

#include "Ship.h"

class battleship : public ship
{

public:

    /**
    * @brief Construct a new battleship
    *
    * @param bow representing the coordinate of the bow of the ship
    * @param stern representing the coordinate of the stern of the ship
    */
    battleship(const battleships::coordinate &bow, const battleships::coordinate &stern);

    /**
    * @brief tell the name of the type of the ship
    *
    * @return a string containing the name of the type of the ship
    */
    static std::string className() { return "battleship"; }

    /**
    * @brief override function representing the action of the ship
    *
    * @param c representing the target coordinate of the action
    * @return vector<pair<char,coordinate>>, which is a vector containing
    * pairs <specific action represented by a char, the target coordinate>
    * ...in this case we have only one type of action: hit a enemy ship
    * on a target coordinate
    */
    std::vector<std::pair<char, battleships::coordinate>> action(battleships::coordinate c) override;

    //static constexpr int representing the char symbol of the ship
    static constexpr int kBattleshipChar = 'C';

    //static constexpr auto used for colors
    static constexpr auto &color()
    { return "\033[42m"; }
    static constexpr auto &colorHit()
    { return "\033[42;7m"; }

private:

    //static constexpr int representing the dimension of ship
    static constexpr int kBattleshipDim = 5;
};

#endif //BATTAGLIANAVALE_LIB_SHIP_BATTLESHIP_H_
