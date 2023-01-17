//
// Created by Enry on 28/12/2022.
//

#ifndef BATTAGLIANAVALE_LIB_HUMAN_H_
#define BATTAGLIANAVALE_LIB_HUMAN_H_
#include "Player.h"
class human : public player
{
 public:
  std::string to_string() override;
  std::string doAction(std::string input) override;
  explicit human(const std::string &name);
};

#endif //BATTAGLIANAVALE_LIB_HUMAN_H_
