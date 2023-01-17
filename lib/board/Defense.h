/**
 * @file Defense.h
 * @author TODO
 * @brief This class represents the defense board
 * @date 2023-01-17
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef BATTAGLIANAVALE_LIB_BOARD_DEFENSE_H_
#define BATTAGLIANAVALE_LIB_BOARD_DEFENSE_H_

#include "../ship/Ship.h"
#include <memory>
class defense : public board
{
 public:
  static constexpr int kMaxBoat = 8;

  bool isShip(battleships::coordinate xy); //true if the coordinate xy contains a ship
  std::vector<battleships::coordinate> isShip(battleships::coordinate xy, unsigned int radius); //
  bool fire(battleships::coordinate xy); //true if hit
  std::vector<std::pair<char, battleships::coordinate>> useShip(battleships::coordinate xyShip, battleships::coordinate xyTarget);
  defense();
  bool setShip(std::unique_ptr<ship> s);
  bool move(battleships::coordinate init_xy, battleships::coordinate final_xy);
  void repair_ship(battleships::coordinate xy);
  bool isDamaged(battleships::coordinate xy);
  int getShipCount() const;

 private:
  std::vector<std::unique_ptr<ship>> ships;
  void sunk(int index);
  int shipCounter = 8;
};

#endif //BATTAGLIANAVALE_LIB_BOARD_DEFENSE_H_
