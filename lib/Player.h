/**
 * @file Player.h
 * @author TODO
 * @brief This abstract class represents a generic player (human or bot)
 *
 */

#ifndef BATTAGLIANAVALE_LIB_PLAYER_H_
#define BATTAGLIANAVALE_LIB_PLAYER_H_

#include <string>

class player
{

public:

    //static constexpr ints that represent both bot and human chars
    static constexpr int kComputerChar = 'c'; //TODO USED?
    static constexpr int kHumanChar = 'p';

    /**
    * @brief return the move that player decides to do
    *
    * @param input string to communicate with the player
    * @return the string for the move
    */
    virtual std::string doAction(std::string input) = 0;

    /**
    * @brief print the name of the player
    *
    * @return a string with the name of the player the board
    */
    std::string to_string() const;

    /**
    * @brief constructs a player
    *
    * @param name containing the string with the name of the player
    */
    explicit player(const std::string &name);

    /**
    * @brief virtual destructor for player, needed because player is an abstract class
    */
    virtual ~player();

protected:

    //string representing player name
    std::string name_;
};

#endif //BATTAGLIANAVALE_LIB_PLAYER_H_
