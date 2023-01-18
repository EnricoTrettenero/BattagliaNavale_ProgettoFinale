/**
 * @file Ship.h
 * @author TODO
 * @brief This abstract class represents a generic Ship
 *
 */

#ifndef BATTAGLIANAVALE_LIB_SHIP_SHIP_H_
#define BATTAGLIANAVALE_LIB_SHIP_SHIP_H_

#include <string>
#include <utility>
#include <vector>
#include "../def/Utility.h"

class ship
{
public:

    //plain enum representing the orientation of the ship
    enum orientation
    {
    VERTICAL, HORIZONTAL
    };

    /**
    * @brief getter
    *
    * @return unsigned int representing the dimension of the ship
    */
    unsigned int dim() const { return dim_; }

    /**
    * @brief getter
    *
    * @return const coordinate representing the centre of the ship
    */
    const battleships::coordinate &centre() const { return centre_; }

    /**
    * @brief getter
    *
    * @return the orientation of the ship
    */
    orientation getOrientation() const { return orientation_; }

    /**
    * @brief getter
    *
    * @return const vector<char> representing the armor of the ship, format: "CCcCC", "E", "sSS"
    */
    const std::vector<char> &armor() const { return armor_; }

    /**
    * @brief virtual function representing the action of the ship
    *
    * @param c representing the target coordinate of the action
    * @return vector<pair<char,coordinate>>, which is a vector containing
    * pairs <specific action represented by a char, the target coordinate>
    *
    */
    virtual std::vector<std::pair<char, battleships::coordinate>> action(battleships::coordinate c) = 0;

    /**
    * @brief tells if the portion of the ship has been hit and lowers the char of the position
    *
    * @param position representing the position on the vector<char> of the armor
    * @throw invalid_argument if the position exceeds the vector length
    * @return true if the portion of the ship has been successfully hit
    * @return true if the portion of the ship hasn't been successfully hit
    */
    bool hit(int position);

    /**
    * @brief change the centre of the ship
    *
    * @param new_centre representing the new centre of the ship
    */
    void set_centre_(battleships::coordinate new_centre) { centre_ = new_centre; }

    /**
    * @brief set the armor of the ship to full health
    */
    void repair_armor();

    /**
    * @brief virtual destructor for ship need for abstract class
    */
    virtual ~ship();

private:

    //unsigned int representing the dimension of the ship
    unsigned int dim_;

    //coordinate representing the centre of the ship
    battleships::coordinate centre_;

    //enum orientation representing the orientation of the ship (vertical/horizontal)
    enum orientation orientation_;

    //vector<char> representing the armor of the ship, format: "CcCCc", "sSS", "E"
    std::vector<char> armor_;

    //char representing the char of the ship
    char shipChar_; //TODO

protected:

    /**
    * @brief Construct a new ship
    *
    * @param shipChar
    * @param armor
    * @param dim
    * @param centre
    * @param orientation
    * ...each one representing the corresponding data member
    */
    ship(char shipChar,
       std::vector<char> armor,
       unsigned int dim,
       const battleships::coordinate &centre,
       orientation orientation)
      : shipChar_{shipChar}, armor_(std::move(armor)), dim_(dim), centre_(centre), orientation_(orientation) {}
    //TODO

    /**
    * @brief Construct a new ship
    *
    * @param shipChar
    * @param armor
    * @param dim
    * ...each one representing the corresponding data member
    * @param bow representing the coordinate of the bow of the ship
    * @param stern representing the coordinate of the stern of the ship
    */
    ship(char shipChar,
       std::vector<char> armor,
       int dim,
       const battleships::coordinate &bow,
       const battleships::coordinate &stern);
};

#endif //BATTAGLIANAVALE_LIB_SHIP_SHIP_H_
