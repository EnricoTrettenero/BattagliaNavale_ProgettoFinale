/**
 * @file Replay.h
 * @author TODO
 * @brief TODO.
 */

#ifndef BATTAGLIANAVALE_LIB_REPLAY_H_
#define BATTAGLIANAVALE_LIB_REPLAY_H_
#include "Player.h"
#include <iostream>
#include <fstream>
#include <vector>
class replay : public player
{
 public:
  /*
 * @brief return move via vector of strings moves (precedent player moves)
 * @param input = useless string derivative from player
   * @return = string with move
 */
  std::string doAction(std::string input) override;
  /*
   * @brief call player constructor with the player name
   * @param name = player name, moves = vector with moves
   */
  explicit replay(const std::string &name, const std::vector<std::string>& moves);

 private:
  /*
   * @param moves_ = array of string where each string is a valid player moves takes from file on replayGame
   */
  std::vector<std::string> moves_;
  /*
  * @param position = current position on moves_
  */
  int position;
};
#endif //BATTAGLIANAVALE_LIB_REPLAY_H_
