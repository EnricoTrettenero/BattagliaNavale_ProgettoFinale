//
// Created by Enry on 28/12/2022.
//

#ifndef BATTAGLIANAVALE_LIB_AI_H_
#define BATTAGLIANAVALE_LIB_AI_H_
#include "Player.h"
class ai : public player
{
 public:
   std::string doMove(std::string input) override;

};
#endif //BATTAGLIANAVALE_LIB_AI_H_
