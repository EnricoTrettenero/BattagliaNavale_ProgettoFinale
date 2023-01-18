/**
 * @file Submarine.h
 * @author TODO
 * @brief This class represents a submarine
 * @date 2023-01-17
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef BATTAGLIANAVALE_LIB_SHIP_SUBMARINE_H_
#define BATTAGLIANAVALE_LIB_SHIP_SUBMARINE_H_

#include "Ship.h"
class submarine : public ship
{

public:

    /**
    * @brief Construct a new submarine
    *
    * @param bow representing the coordinate of the bow of the ship
    * @param stern representing the coordinate of the stern of the ship
    */
    submarine(const battleships::coordinate &bow, const battleships::coordinate &stern);

    /**
    * @brief tell the name of the type of the ship
    *
    * @return a string containing the name of the type of the ship
    */
    static std::string className() { return "submarine"; }

    /**
    * @brief override function representing the action of the ship
    *
    * @param c representing the target coordinate of the action
    * @return vector<pair<char,coordinate>>, which is a vector containing
    * pairs <specific action represented by a char, the target coordinate>
    * ...in this case we have only two types of action: move to a target
    * coordinate and find the enemy ship if in radius
    */
    std::vector<std::pair<char, battleships::coordinate>> action(battleships::coordinate c) override;

    //static constexpr int representing the char symbol of the ship
    static constexpr int kSubmarineChar = 'E';

    //static constexpr auto used for colors TODO
    static constexpr auto &color()
    { return "\033[43m"; }
    static constexpr auto &colorHit()
    { return "\033[43;7m"; }

private:

    //static constexpr int representing the dimension of ship
    static constexpr int kSubmarineDim = 1;
};

#endif //BATTAGLIANAVALE_LIB_SHIP_SUBMARINE_H_
