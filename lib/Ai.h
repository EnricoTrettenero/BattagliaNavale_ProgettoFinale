//
// Created by Enry on 28/12/2022.
//

#ifndef BATTAGLIANAVALE_LIB_AI_H_
#define BATTAGLIANAVALE_LIB_AI_H_
#include "Player.h"
class ai : public player
{
 public:
  std::string to_string() override;
  std::string doMove(std::string input) override;
  explicit ai(const std::string &name);
};
#endif //BATTAGLIANAVALE_LIB_AI_H_
