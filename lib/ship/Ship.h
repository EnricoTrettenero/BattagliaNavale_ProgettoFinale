//
// Created by Enry on 22/12/2022.
//

#ifndef BATTAGLIANAVALE_LIB_SHIP_SHIP_H_
#define BATTAGLIANAVALE_LIB_SHIP_SHIP_H_

#include <string>
#include <utility>
#include <vector>
#include "../def/Utility.h"

class ship
{
 public:
  enum orientation
  {
    VERTICAL, HORIZONTAL
  };

  //getters
  unsigned int dim() const { return dim_; }
  const battleships::coordinate &center() const { return center_; }
  orientation getOrientation() const { return orientation_; }
  const std::vector<char> &armor() const { return armor_; }

  //virtual method
  virtual std::vector<std::pair<char, battleships::coordinate>> action(battleships::coordinate c) = 0;

  //utilities
  bool hit(int position);
  void set_center_(battleships::coordinate new_center) { center_ = new_center; }
  void repair_armor();

  virtual ~ship(); //https://stackoverflow.com/questions/69081119/that-is-abstract-but-has-non-virtual-destructor-the-delete-is-causing-an-error
 private:

  unsigned int dim_;
  battleships::coordinate center_;
  enum orientation orientation_;
  std::vector<char> armor_;
  char shipChar_;

 protected:
  ship(char shipChar,
       std::vector<char> armor,
       unsigned int dim,
       const battleships::coordinate &center,
       orientation orientation)
      : shipChar_{shipChar}, armor_(std::move(armor)), dim_(dim), center_(center), orientation_(orientation) {}

  ship(char shipChar, std::vector<char> armor, const battleships::coordinate &bow, const battleships::coordinate &stern);
};

#endif //BATTAGLIANAVALE_LIB_SHIP_SHIP_H_
