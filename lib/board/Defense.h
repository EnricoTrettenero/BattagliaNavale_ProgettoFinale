//
// Created by vale on 27/12/22.
//

#ifndef BATTAGLIANAVALE_LIB_BOARD_DEFENSE_H_
#define BATTAGLIANAVALE_LIB_BOARD_DEFENSE_H_

#include "../ship/Ship.h"

class defense : public board
{
 public:
  static constexpr int kMaxBoat = 8;

  bool isShip(battleships::coordinate xy);
  std::vector<int> isShip(battleships::coordinate xy, int radius);
  bool fire(battleships::coordinate xy); //true if center
  bool useShip(battleships::coordinate xyShip, battleships::coordinate xyTarget);
  defense();
  bool setShip(ship& s);

 private:
  std::vector<ship> ships;

};

#endif //BATTAGLIANAVALE_LIB_BOARD_DEFENSE_H_
