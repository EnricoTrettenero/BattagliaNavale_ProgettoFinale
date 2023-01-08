//
// Created by vale on 27/12/22.
//

#ifndef BATTAGLIANAVALE_LIB_GAME_H_
#define BATTAGLIANAVALE_LIB_GAME_H_
#include <memory>
#include "Player.h"
#include "board/Attack.h"
#include "board/Defense.h"
class game
{
 public:
  static constexpr int kNumberBattleship = 3;
  static constexpr int kNumberSupport = 3;
  static constexpr int kNumberSubmarine = 2;
  explicit game(std::unique_ptr<player> p1, std::unique_ptr<player> p2);
 private:
  std::unique_ptr<player> p1_, p2_;
  attack attackBoardP1_, attackBoardP2_;
  defense defenseBoardP1_, defenseBoardP2_;
  void filler(std::unique_ptr<player> &p, defense &d, attack &a);
  void make_action(const std::vector<std::pair<char,battleships::coordinate>>& vec, defense ally_defense, defense enemy_defense, attack ally_attack);

  bool turn;
  int turnCounter;
  std::pair<battleships::coordinate,ship::orientation> getShipData(const std::string &s);

};

#endif //BATTAGLIANAVALE_LIB_GAME_H_
