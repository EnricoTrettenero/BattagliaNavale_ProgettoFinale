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
  explicit replaygame(const std::string& inputFile);
  const std::vector<std::string> & startReplay();
 private:
    std::string fileName_;
    std::vector<std::string> p1Moves;
    std::vector<std::string> p2Moves;
    std::vector<std::string> printFinal_;
    void playReplay();

};

#endif //BATTAGLIANAVALE_LIB_REPLAYGAME_H_
