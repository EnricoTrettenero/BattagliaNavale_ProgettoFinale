/**
 * @file Player.h
 * @author TODO
 * @brief This abstract class represents a generic player (human or bot)
 * @date 2023-01-17
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef BATTAGLIANAVALE_LIB_PLAYER_H_
#define BATTAGLIANAVALE_LIB_PLAYER_H_
#include <string>
class player
{
 protected:
  std::string name_;
 public:
  static constexpr int kComputerChar = 'c';
  static constexpr int kHumanChar = 'p';
  virtual std::string doAction(std::string input) = 0;
  virtual std::string to_string() = 0;
  explicit player(const std::string &name);
  virtual ~player();
};

#endif //BATTAGLIANAVALE_LIB_PLAYER_H_
