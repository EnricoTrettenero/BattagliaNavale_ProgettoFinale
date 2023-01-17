/**
 * @file Ai.h
 * @author TODO
 * @brief This class represents a bot player
 * @date 2023-01-17
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef BATTAGLIANAVALE_LIB_AI_H_
#define BATTAGLIANAVALE_LIB_AI_H_
#include "Player.h"
class ai : public player
{
 public:
  std::string to_string() override;
  std::string doAction(std::string input) override;
  explicit ai(const std::string &name);

};
#endif //BATTAGLIANAVALE_LIB_AI_H_
