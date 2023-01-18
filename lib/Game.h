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

  static constexpr int kNumberBattleship = 3;
  static constexpr int kNumberSupport = 3;
  static constexpr int kNumberSubmarine = 2;
  static constexpr int maxTurn = 100;
  /**
   * @brief initialized a new game with two player(abstract class) and a fileName with output
   *
   * @param p1 = player1, p2= player2, fileName= name for the output file
   */
  explicit game(std::unique_ptr<player> p1, std::unique_ptr<player> p2, const std::string &fileName);
  /**
  * @brief start a new game and print the log of all moves at the end of the game
  *
  *
  */
  void startNewGame();
 protected:
  /**
  * @param contain the name of the output log file
  */
  std::string fileName_;
  /**
 * @param contain the player for the game, unique_ptr because the player where created outside game
 */
  std::unique_ptr<player> p1_, p2_;
  /**
 * @param attack board for the players
 */
  attack attackBoardP1_, attackBoardP2_;
  /**
 * @param defense board for the players
 */
  defense defenseBoardP1_, defenseBoardP2_;
 /**
 * @brief fill the boards for the player
 * @param p=player to request the move, d=defense board of that player, a=attack board of that player
 */
  void fillPlayerBoards(std::unique_ptr<player> &p, defense &d, attack &a);
  /**
 * @brief take the list of moves that one ship (of defense request by player) try to do on the boards and apply that moves
 * via the defense and attack function members,
 * @param vec = vector of pair <char,coordinate> where char represent the type of action (M=move,E=Scan,C=fire,S=repair) and the
 * coordinate where execute the command, ally_defense = personal player board, enemy_defense = enemy player board, attack = personal player board
 */

  void make_action(const std::vector<std::pair<char, battleships::coordinate>> &vec,
                   defense &ally_defense,
                   defense &enemy_defense,
                   attack &ally_attack);
  /**
 * @brief start play game, request the boards are already full with ships
 *
 */
  void play();
  /**
* @brief do a single turn with various control for special moves and moves_error for the player p
*
* @param p = player of that turn, d = p defense board, a= p attack board, enemyD = enemy of p board defense
*/
  void playTurn(std::unique_ptr<player> &p, defense &d, attack &a, defense &enemyD);
  /**
* @brief end the game
* @param p = winner player
*/
  void endGame(std::unique_ptr<player> &p);
  /**
* @brief check if player has lost
* @param d = defense of player to check
*/
  bool hasLost(defense &d);
  /**
* @brief convert an input string to coordinate
* @param s = input string
   * @throws throw invalid argument if the string isn't valid
*/
  battleships::coordinate getCoordinate(const std::string &s);
  /**
 * @brief receive the input string from player and convert in an valid moved of "coordinate coordinate"
 * @param s = input string
    * @throws throw invalid argument if the string isn't valid
 */
  std::pair<battleships::coordinate, battleships::coordinate> getShipData(const std::string &s);
  /**
*
* @param turn = represent the flip-flop method to control the turn, true = p1 turn | false = p2 turn
*/
  bool turn;
  /**
* @param turnCounter = count the number of moves valid
*/
  int turnCounter;
  /**
* @param output_ = log cache before print on file, use to prevent open file for the all duration of game
*/
  std::string output_;
  /**
* @brief protected constructor for only use on derivative class like ReplayGame
*/
    game();

  //utilities

  /**
* @brief Template function that insert an certain type of ship in the player p board
   * @param kNumber=number of that type of ship, p = player that own the board, d = player p board, type = type of ship
*/
  template<typename T>
  void fillShip(int kNumber,std::unique_ptr<player> &p, defense &d,const std::string& type);
};

#include "Game.hpp"

#endif //BATTAGLIANAVALE_LIB_GAME_H_
