//
// Created by Enry on 09/01/2023.
//

#ifndef BATTAGLIANAVALE_LIB_REPLAY_H_
#define BATTAGLIANAVALE_LIB_REPLAY_H_
#include "Player.h"
#include <iostream>
#include <fstream>
class replay : public player
{
 public:
  std::string to_string() override;
  std::string doAction(std::string input) override;
  explicit replay(const std::string &name);
 private:
  std::ifstream file_;
};
#endif //BATTAGLIANAVALE_LIB_REPLAY_H_
