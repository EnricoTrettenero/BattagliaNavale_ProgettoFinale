/**
 * @file Ai.h
 * @author TODO
 * @brief This class represents a bot player
 *
 */

#ifndef BATTAGLIANAVALE_LIB_AI_H_
#define BATTAGLIANAVALE_LIB_AI_H_
#include "Player.h"
class ai : public player
{
 public:
  /*
   * @brief generate random moves
   * @param input = string for communicate with player
   * @return = string with the move
   */
  std::string doAction(std::string input) override;
  /*
   * @brief call player constructor with the player name
   * @param name = player name
  * @return = string from player input
   */
  explicit ai(const std::string &name);

};
#endif //BATTAGLIANAVALE_LIB_AI_H_
