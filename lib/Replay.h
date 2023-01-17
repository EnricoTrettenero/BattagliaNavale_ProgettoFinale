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
  std::string doInsert(std::string input) override;
  replay(const std::string &name_1,
         const std::string &name,
         const std::string &nextMoves);

 private:
  std::string nextMoves_;

};
#endif //BATTAGLIANAVALE_LIB_REPLAY_H_
