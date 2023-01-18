/**
 * @file Ai.h
 * @author Valentin Necula
 * @brief This class represents a bot player
 *
 */

#ifndef BATTAGLIANAVALE_LIB_AI_H_
#define BATTAGLIANAVALE_LIB_AI_H_

#include "Player.h"

class ai : public player
{

public:

    /**
    * @brief generates random moves for the AI
    *
    * @param input string to communicate with the player
    * @return string with the move
    */
    std::string doAction(std::string input) override;

    /**
    * @brief calls player constructor with the player name
    * @param name representing the player name
    */
    explicit ai(const std::string &name);
};

#endif //BATTAGLIANAVALE_LIB_AI_H_
