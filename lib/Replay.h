//
// Created by Enry on 09/01/2023.
//

#ifndef BATTAGLIANAVALE_LIB_REPLAY_H_
#define BATTAGLIANAVALE_LIB_REPLAY_H_
#include "Player.h"
#include <iostream>
#include <fstream>
#include <vector>
class replay : public player
{
 public:
  std::string to_string() override;
  std::string doAction(std::string input) override;
  explicit replay(const std::string &name, const std::vector<std::string>& moves);

 private:
  std::vector<std::string> moves_;
  int position;
};
#endif //BATTAGLIANAVALE_LIB_REPLAY_H_
