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

  bool isShip(battleships::coordinate xy);
  std::vector<int> isShip(battleships::coordinate xy, int radius);
  bool fire(battleships::coordinate xy); //true if center
  bool useShip(battleships::coordinate xyShip, battleships::coordinate xyTarget);
  defense();
  bool setShip(std::unique_ptr<ship> s);

 private:
  std::vector<std::unique_ptr<ship>> ships;

};

#endif //BATTAGLIANAVALE_LIB_BOARD_DEFENSE_H_
