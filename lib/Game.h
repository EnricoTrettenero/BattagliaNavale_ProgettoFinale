//
// Created by vale on 27/12/22.
//

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
  explicit game(std::unique_ptr<player> p1, std::unique_ptr<player> p2, const std::string &fileName);
 private:
  std::unique_ptr<player> p1_, p2_;
  attack attackBoardP1_, attackBoardP2_;
  defense defenseBoardP1_, defenseBoardP2_;
  void fillPlayerBoards(std::unique_ptr<player> &p, defense &d, attack &a);
  void make_action(const std::vector<std::pair<char, battleships::coordinate>> &vec,
                   defense &ally_defense,
                   defense &enemy_defense,
                   attack &ally_attack);
  void play();
  void playTurn(std::unique_ptr<player> &p, defense &d, attack &a, defense &enemyD);
  void endGame(std::unique_ptr<player> &p);
  bool hasLost(std::unique_ptr<player> &p, defense &d);
  battleships::coordinate getCoordinate(const std::string &s);
  bool turn;
  int turnCounter;
  std::ofstream file_;
  std::pair<battleships::coordinate, ship::orientation> getShipData(const std::string &s);

  //utilities
  void fillHumanBattleships(std::unique_ptr<player> &p, defense &d);
  void fillHumanSupport(std::unique_ptr<player> &p, defense &d);
  void fillHumanSubmarine(std::unique_ptr<player> &p, defense &d);


  template<typename T>
  void fillShip(int kNumber,std::unique_ptr<player> &p, defense &d,std::string type);
};

#include "Game.hpp"

#endif //BATTAGLIANAVALE_LIB_GAME_H_
