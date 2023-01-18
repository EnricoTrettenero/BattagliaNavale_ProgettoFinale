/**
 * @file Replay.h
 * @author TODO
 * @brief TODO
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

    /**
    * @brief return move via vector of strings moves (precedent player moves) //TODO
    *
    * @param input useless string derivative from player
    * @return the string with the move
    */
    std::string doAction(std::string input) override;

    /**
    * @brief calls player constructor with the player name
    *
    * @param name representing the player name,
    * @param moves representing the vector with moves
    */
    explicit replay(const std::string &name, const std::vector<std::string>& moves);

private:

    // array of string where each string is a valid player move taken from the log file on replayGame
    std::vector<std::string> moves_;

    // current position on moves_
    int position;
};

#endif //BATTAGLIANAVALE_LIB_REPLAY_H_
