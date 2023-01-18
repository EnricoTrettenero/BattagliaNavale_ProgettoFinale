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

 public:
  static constexpr int kComputerChar = 'c'; //TODO USED?
  static constexpr int kHumanChar = 'p';

  /*
   * @brief = return the move that player decides to do
   * @param input = string for communicate with player
   * @return = return the string for the move
   */
  virtual std::string doAction(std::string input) = 0;
  /*
   * @brief = return the name of player
   * @return = string with name of player
   */
  std::string to_string() const;
  /*
   * @brief = constructor of player
   * @param name = string with name of player
   */
  explicit player(const std::string &name);
  /*
   * @brief = virtual destructor for player, needed because player is an abstract class
   */
  virtual ~player();

 protected:
  /*
   * @param name_ = string with player name
   */
  std::string name_;
};

#endif //BATTAGLIANAVALE_LIB_PLAYER_H_
