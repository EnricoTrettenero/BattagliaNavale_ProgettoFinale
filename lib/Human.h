//
// Created by Enry on 28/12/2022.
//

#ifndef BATTAGLIANAVALE_LIB_HUMAN_H_
#define BATTAGLIANAVALE_LIB_HUMAN_H_
#include "Player.h"
class human : public player
{
 public:

  virtual std::string doMove(std::string input) = 0;
};
#endif //BATTAGLIANAVALE_LIB_HUMAN_H_
