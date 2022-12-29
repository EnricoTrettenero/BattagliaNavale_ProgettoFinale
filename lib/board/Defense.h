//
// Created by vale on 27/12/22.
//

#ifndef BATTAGLIANAVALE_LIB_BOARD_DEFENSE_H_
#define BATTAGLIANAVALE_LIB_BOARD_DEFENSE_H_

#include "../ship/Ship.h"
#include <memory>
class defense : public board
{
 public:
  static constexpr int kMaxBoat = 8;

  bool isShip(battleships::coordinate xy); //true if the coordinate xy contains a ship
  std::vector<battleships::coordinate> isShip(battleships::coordinate xy,unsigned int radius); //
  bool fire(battleships::coordinate xy); //true if hit
  bool useShip(battleships::coordinate xyShip, battleships::coordinate xyTarget);
  defense();
  bool setShip(std::unique_ptr<ship> s);
  bool move(battleships::coordinate init_xy, battleships::coordinate final_xy);

 private:
  std::vector<std::unique_ptr<ship>> ships;
  void sunk(int index);

};

#endif //BATTAGLIANAVALE_LIB_BOARD_DEFENSE_H_
