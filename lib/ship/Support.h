/**
 * @file Support.h
 * @author Valentin Necula
 * @brief This class represents a support ship
 *
 */

#ifndef BATTAGLIANAVALE_LIB_SHIP_SUPPORT_H_
#define BATTAGLIANAVALE_LIB_SHIP_SUPPORT_H_

#include "../def/Utility.h"
#include "Ship.h"

class support : public ship
{

public:

    /**
    * @brief Construct a new support
    *
    * @param bow representing the coordinate of the bow of the ship
    * @param stern representing the coordinate of the stern of the ship
    */
    support(const battleships::coordinate &bow, const battleships::coordinate &stern);

    /**
    * @brief tell the name of the type of the ship
    *
    * @return a string containing the name of the type of the ship
    */
    static std::string className() { return "support"; }

    /**
    * @brief override function representing the action of the ship
    *
    * @param c representing the target coordinate of the action
    * @return vector<pair<char,coordinate>>, which is a vector containing
    * pairs <specific action represented by a char, the target coordinate>
    * ...in this case we have only two types of action: move to a target
    * coordinate and heal a ally ship if in radius
    */
    std::vector<std::pair<char, battleships::coordinate>> action(battleships::coordinate c) override;

    //static constexpr int representing the char symbol of the ship
    static constexpr int kSupportChar = 'S';

    //static constexpr auto used for colors
    static constexpr auto &color()
    { return "\033[41m"; }
    static constexpr auto &colorHit()
    { return "\033[41;7m"; }

private:

    //static constexpr int representing the dimension of ship
    static constexpr int kSupportDim = 3;
};

#endif //BATTAGLIANAVALE_LIB_SHIP_SUPPORT_H_
