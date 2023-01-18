/**
 * @file Defense.h
 * @author TODO
 * @brief This class represents the defense board
 *
 */

#ifndef BATTAGLIANAVALE_LIB_BOARD_DEFENSE_H_
#define BATTAGLIANAVALE_LIB_BOARD_DEFENSE_H_

#include "../ship/Ship.h"
#include <memory>

class defense : public board
{
public:
    //static constexpr int representing the max number of boats
   // static constexpr int kMaxBoat = 8;

    /**
    * @brief tells if the coordinate contains a ship
    *
    * @param xy representing the coordinate
    * @return true if the coordinate xy contains a ship
    * @return false if the coordinate xy doesn't contain a ship
    */
    bool isShip(battleships::coordinate xy);

    /**
    * @brief tells which coordinates in the radius contain a ship
    *
    * @param xy representing the coordinate (centre of the radius)
    * @return a vector<coordinate> that contains all the coordinates
    * in the radius that contain a ship
    */
  //  std::vector<battleships::coordinate> isShip(battleships::coordinate xy, unsigned int radius);

    /**
    * @brief if there is a ship in the coordinate lowers the
    * char of the portion of that ship (means has been hit)
    *
    * @param xy representing the coordinate
    * @return true if a ship has been hit
    * @return false if a ship hasn't been hit
    */
    bool fire(battleships::coordinate xy);

    /**
    * @brief use the ship on the target
    *
    * @param xyShip representing the coordinate of the ship that will be used
    * @param xyTarget representing the target coordinate
    * @throw invalid_argument if no ship on the xyShip coordinate is found
    * @return a vector containing all the coordinates that will be affected by the action of the ship
    */
    std::vector<std::pair<char, battleships::coordinate>> useShip(battleships::coordinate xyShip, battleships::coordinate xyTarget);

    /**
    * @brief Construct a new defense board
    */
    defense();

    /**
    * @brief sets the ship on the board
    *
    * @param s representing the ship to be set
    * @return true if the ship has been successfully set
    * @return false if the ship hasn't been successfully set
    */
    bool setShip(std::unique_ptr<ship> s);

    /**
    * @brief move the ship from one coordinate to another
    *
    * @param init_xy the initial coordinate of the ship
    * @param final_xy the final coordinate of the ship
    * @return true if the ship has been successfully moved
    * @return false if the ship hasn't been successfully moved
    */
    bool move(battleships::coordinate init_xy, battleships::coordinate final_xy);

    /**
    * @brief repair the ship on the coordinate
    *
    * @param xy representing a portion of a ship (the whole ship will be healed)
    */
    void repair_ship(battleships::coordinate xy);

    /**
    * @brief tells if the ship is damaged on a specific coordinate
    *
    * @param xy representing the coordinate of the ship that could be damaged
    * @return true if the ship is damaged
    * @return false if the ship isn't damaged or there is no ship on the coordinate
    */
    bool isDamaged(battleships::coordinate xy);

    /**
    * @brief tells how many ships remain on the board
    *
    * @return an int representing the number of remaining ships
    */
    int getShipCount() const;

private:

    //vector<unique_ptr<ship>> representing the ships
    std::vector<std::unique_ptr<ship>> ships;

    /**
    * @brief destroys the ship
    *
    * @param index representing the position of the ship
    * on the vector<unique_ptr<ship>> that will be removed
    */
    void sunk(int index);
/**
    * @brief check if coordinate xy is part of ship s
    *
    * @param xy = coordinate to verify, s = ship to control
    * @return = true if is part else false
    */
    static bool isPartOf(battleships::coordinate xy, std::unique_ptr<ship>& s);
    //int counter representing the number of ships
    int shipCounter = 8;
};

#endif //BATTAGLIANAVALE_LIB_BOARD_DEFENSE_H_
