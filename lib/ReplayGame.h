/**
 * @file Replay.h
 * @author TODO
 * @brief TODO.
 * @date 2023-01-17
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef BATTAGLIANAVALE_LIB_REPLAYGAME_H_
#define BATTAGLIANAVALE_LIB_REPLAYGAME_H_
#include "Game.h"
#include "Replay.h"
class replaygame : public game
{
 public:
  /*
   * @brief replayGame constructor
   * @param inputFile = name of file for read the moves
   */
  explicit replaygame(const std::string& inputFile);
  /*
   * @brief do the replay = started the game with 2 replay player and do the moves from the file
   * @return = vector of string where each string is a couple of defense and attack for print on file or consolle
   */
  const std::vector<std::string> & startReplay();
 private:
  /*
   * @param filename_ = name of file
   */
    std::string fileName_;
  /*
* @param p1Moves = vector of p1 moves, p2Moves =vector of p2 moves from file, printFinal_ = vector of all board at every turn of game
   *
*/
    std::vector<std::string> p1Moves, p2Moves, printFinal_;
    /*
     * @brief = simil to game::replay with some modification to do the replay
     */
    void playReplay();

};

#endif //BATTAGLIANAVALE_LIB_REPLAYGAME_H_
