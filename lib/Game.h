/**
 * @file Player.h
 * @author TODO
 * @brief This class represents a game of "Battaglia Navale".
 * It only has one public method, startNewGame(), used to start the game.
 * An istance of Game can be used to play one and only one game,
 * to play more other istances of Game must be created.
 *
 */

#ifndef BATTAGLIANAVALE_LIB_GAME_H_
#define BATTAGLIANAVALE_LIB_GAME_H_

#include <memory>
#include <fstream>
#include "Player.h"
#include "board/Attack.h"
#include "board/Defense.h"

class game
{
public:

    //static constexpr int representing the max number of each ship
    static constexpr int kNumberBattleship = 3;
    static constexpr int kNumberSupport = 3;
    static constexpr int kNumberSubmarine = 2;

    //static constexpr int representing the max number turns in the game
    static constexpr int maxTurn = 100;

    /**
    * @brief construct a new game with two players and a fileName with output
    *
    * @param p1 representing player1, p2 representing player2, fileName representing name for the output file
    */
    explicit game(std::unique_ptr<player> p1, std::unique_ptr<player> p2, const std::string &fileName);

    /**
    * @brief starts a new game and prints the log of all moves at the end of the game
    */
    void startNewGame();

protected:

    //contains the name of the output log file
    std::string fileName_;

    //players for the game, unique_ptr because the players are created outside game
    std::unique_ptr<player> p1_, p2_;

    //attack boards for both the players
    attack attackBoardP1_, attackBoardP2_;

    //defense boards for both the players
    defense defenseBoardP1_, defenseBoardP2_;

    /**
    * @brief fill the boards for the player
    *
    * @param p representing player that requested the fill
    * @param d representing the defense board of the player
    * @param a representing the attack board of the player
    */
    void fillPlayerBoards(std::unique_ptr<player> &p, defense &d, attack &a);

    /**
    * @brief take the list of moves that one ship tries to do on the boards
    * and apply that moves via defense and attack function members,
    *
    * @param vec = vector of pair <char,coordinate>: 1) char representing the type of action
    * (M=move, E=Scan, C=fire, S=repair) 2) coordinate representing where execute the command
    * @param ally_defense personal player defense board
    * @param enemy_defense enemy player defense board
    * @param ally_attack personal player attack board
    */
    void make_action(const std::vector<std::pair<char, battleships::coordinate>> &vec,
                   defense &ally_defense,
                   defense &enemy_defense,
                   attack &ally_attack);

    /**
    * @brief starts the game, after the boards have already been filled with ships
    */
    void play();

    /**
    * @brief do a single turn with various control for special moves and moves_error for the player p
    *
    * @param p player playing that turn
    * @param d personal player defense board
    * @param enemyD enemy player defense board
    * @param a personal player attack board
    */
    void playTurn(std::unique_ptr<player> &p, defense &d, attack &a, defense &enemyD);

    /**
    * @brief ends the game
    *
    * @param p representing winner player
    */
    void endGame(std::unique_ptr<player> &p);

    /**
    * @brief check if the player has lost
    *
    * @param d personal player defense board where to check
    */
    bool hasLost(defense &d);

    /**
    * @brief convert an input string to a coordinate
    *
    * @param s representing input string
    * @throws throw invalid argument if the string isn't valid
    * @return the coordinate
    */
    battleships::coordinate getCoordinate(const std::string &s);

    /**
    * @brief receive the input string from player and convert in an valid pair of "coordinate coordinate"
    *
    * @param s representing input string
    * @throws throw invalid argument if the string isn't valid
    * @return the pair<coordinate,coordinate>
    */
    std::pair<battleships::coordinate, battleships::coordinate> getShipData(const std::string &s);

    //bool which represents the flip-flop way to control the turn, true = p1 turn | false = p2 turn
    bool turn;

    //counts the number of current turn
    int turnCounter;

    //log cache before print on file, use to prevent open file for the all duration of game
    std::string output_;

    /**
    * @brief protected constructor used only on derivative class ReplayGame
    */
    game();

    //utilities

    /**
    * @brief Template function that insert a specific type of ship in the p player defense board
    * @param kNumber number of ships of that type required
    * @param p player owning the board
    * @param d personal player defense board
    * @param type representing the type of the ship
    */
    template<typename T>
    void fillShip(int kNumber,std::unique_ptr<player> &p, defense &d,const std::string& type);
};

#include "Game.hpp"

#endif //BATTAGLIANAVALE_LIB_GAME_H_
