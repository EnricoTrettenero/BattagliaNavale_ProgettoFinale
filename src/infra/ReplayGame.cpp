//
// Created by Enry on 17/01/2023.
//
#include "../../lib/ReplayGame.h"
#include "../../lib/Replay.h"
#include "../../lib/Human.h"
#include <memory>
//constructor
replaygame::replaygame(const std::string &inputFile) : game(), fileName_{inputFile} //call the empty protected game constructor
{

}
//primary function method, return the vector of board of each turn throw exception if file not valid
const std::vector<std::string> &replaygame::startReplay()
{
    std::ifstream file(fileName_);
    if (!file.is_open()) throw std::invalid_argument("file not valid"); //check file
    std::string player1Name;
    std::string player2Name;
    std::getline(file, player1Name); //read player name
    std::getline(file, player2Name);
    int firstMoveCounter=0; //for determinate who start the game
    do
    { //read file moves
        std::string line;
        std::getline(file, line);
        if (!line.empty())
        {
            int position = line.find(':'); //find char separator (moves format: "nameplayer:B10 B10"
            std::string playerID = line.substr(0, position);
            if (playerID == player1Name) { p1Moves.push_back(line.substr(position + 1, line.size())); } //identify player and push his move
            else if (playerID == player2Name) { p2Moves.push_back(line.substr(position + 1, line.size())); }
            else { throw std::invalid_argument("log file not valid"); }

            //use for find who do the first move
            if(firstMoveCounter==(kNumberSupport+kNumberBattleship+kNumberSubmarine)*2)
            {
                turn = playerID == player1Name;
            }
            ++firstMoveCounter;

        }
    } while (!file.eof());
    file.close();
    //create replay player
    p1_ = std::make_unique<replay>(player1Name, p1Moves);
    p2_ = std::make_unique<replay>(player2Name, p2Moves);
    //call filler board
    fillPlayerBoards(p1_, defenseBoardP1_, attackBoardP1_);
    fillPlayerBoards(p2_, defenseBoardP2_, attackBoardP2_);
    //start play modify for replay
    playReplay();

    return printFinal_;
}
//alternative versione of game::replay
void replaygame::playReplay()
{
    turnCounter = 0;
    output_ = ""; //no needed
    while (turnCounter < maxTurn)
    { //same as Game
        if (turn)
        {
            printFinal_.push_back(board::concat2string(defenseBoardP1_.to_string(), attackBoardP1_.to_string()));
            playTurn(p1_, defenseBoardP1_, attackBoardP1_, defenseBoardP2_);
            if (hasLost(defenseBoardP2_)) endGame(p1_);
        } else
        {
            printFinal_.push_back(board::concat2string(defenseBoardP2_.to_string(), attackBoardP2_.to_string()));
            playTurn(p2_, defenseBoardP2_, attackBoardP2_, defenseBoardP1_);
            if (hasLost(defenseBoardP1_)) endGame(p2_);
        }
        turn = !turn;
        turnCounter++;
    }

}