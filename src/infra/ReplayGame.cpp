//
// Created by Enry on 17/01/2023.
//
#include "../../lib/ReplayGame.h"
#include "../../lib/Replay.h"
#include "../../lib/Human.h"
#include <memory>
replaygame::replaygame(const std::string &inputFile) : game(), fileName_{inputFile}
{

}
const std::vector<std::string> &replaygame::startReplay()
{
    std::ifstream file(fileName_);
    if (!file.is_open()) throw std::invalid_argument("file not valid");
    std::string player1Name;
    std::string player2Name;
    std::getline(file, player1Name);
    std::getline(file, player2Name);

    do
    {
        std::string line;
        std::getline(file, line);
        if (line != "")
        {
            int position = line.find(':');
            std::string playerID = line.substr(0, position);
            if (playerID == player1Name) { p1Moves.push_back(line.substr(position + 1, line.size())); }
            else if (playerID == player2Name) { p2Moves.push_back(line.substr(position + 1, line.size())); }
            else { throw std::invalid_argument("log file not valid"); }
        }
    } while (!file.eof());
    p1_ = std::make_unique<replay>(player1Name, p1Moves);
    p2_ = std::make_unique<replay>(player2Name, p2Moves);
    file.close();
    fillPlayerBoards(p1_, defenseBoardP1_, attackBoardP1_);
    fillPlayerBoards(p2_, defenseBoardP2_, attackBoardP2_);

    playReplay();

    return printFinal_;
}

void replaygame::playReplay()
{
    turnCounter = 0;
    turn = true;
    output_ = "";
    while (turnCounter < maxTurn)
    {

        if (turn)
        {
            printFinal_.push_back(board::concat2string(defenseBoardP1_.to_string(), attackBoardP1_.to_string()));
            playTurn(p1_, defenseBoardP1_, attackBoardP1_, defenseBoardP2_);
            if (hasLost(p2_, defenseBoardP2_))
                endGame(p1_);
        } else
        {
            printFinal_.push_back(board::concat2string(defenseBoardP2_.to_string(), attackBoardP2_.to_string()));
            playTurn(p2_, defenseBoardP2_, attackBoardP2_, defenseBoardP1_);
            if (hasLost(p1_, defenseBoardP1_))
                endGame(p2_);
        }
        turn = !turn;
        turnCounter++;
    }

}