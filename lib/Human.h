/**
 * @file Human.h
 * @author TODO
 * @brief This class represents a human player
 * @date 2023-01-17
 *
 * @copyright Copyright (c) 2022
 *
 */

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
