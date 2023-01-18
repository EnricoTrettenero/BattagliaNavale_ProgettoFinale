/**
 * @file Human.h
 * @author TODO
 * @brief This class represents a human player
 *
 */

#ifndef BATTAGLIANAVALE_LIB_HUMAN_H_
#define BATTAGLIANAVALE_LIB_HUMAN_H_

#include "Player.h"

class human : public player
{

public:

    /**
    * @brief read an input stream on the console and do the moves
    * @param input string to communicate with the player
    *
    * @return string from player input
    */
    std::string doAction(std::string input) override;

    /**
    * @brief calls player constructor with the player name
    *
    * @param name representing the player name
    */
    explicit human(const std::string &name);
};

#endif //BATTAGLIANAVALE_LIB_HUMAN_H_
