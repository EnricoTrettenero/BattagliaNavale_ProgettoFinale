//
// Created by Enry on 22/12/2022.
//

#ifndef BATTAGLIANAVALE_LIB_DEF_SHIP_H_
#define BATTAGLIANAVALE_LIB_DEF_SHIP_H_

#include "Utility.h"
class Ship
{
 public:
    virtual bool action(battleship::coordinate c)=0;
 private:
  char *armor;
  unsigned int length;
  battleship::coordinate position;

};
#endif //BATTAGLIANAVALE_LIB_DEF_SHIP_H_
