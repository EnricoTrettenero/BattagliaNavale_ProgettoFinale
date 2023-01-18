/**
 * @file Replay.h
 * @author TODO
 * @brief TODO
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
     * @param mode = true print with color, false without color
    * @return = vector of string where each string is a couple of defense and attack for print on file or consolle
    */
    const std::vector<std::string> & startReplay(bool mode);

private:

    // name of the file
    std::string fileName_;

    // 1) vector of p1 moves, 2) vector of p2 moves, 3) vector of each board at any turn of the game
    std::vector<std::string> p1Moves, p2Moves, printFinal_;

    /*
     * @brief start a new replay and print the log of all moves
    */
    void playReplay();

    //mode = print with or without colors
    bool mode_;
};

#endif //BATTAGLIANAVALE_LIB_REPLAYGAME_H_
