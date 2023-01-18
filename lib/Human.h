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
class human : public player //simply override the player function
{
 public:
/*
   * @brief read an input stream on console for do the moves
   * @param input = string for communicate with player
   * @return = string from player input
   */
  std::string doAction(std::string input) override;
/*
   * @brief call player constructor with the player name
   * @param name = player name
   */
  explicit human(const std::string &name);
};

#endif //BATTAGLIANAVALE_LIB_HUMAN_H_
