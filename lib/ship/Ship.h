//
// Created by Enry on 22/12/2022.
//

#ifndef BATTAGLIANAVALE_LIB_DEF_SHIP_H_
#define BATTAGLIANAVALE_LIB_DEF_SHIP_H_

#include <string>
#include <utility>
#include <vector>
#include "../def/Utility.h"
class ship
{
 public:
  enum orientation { VERTICAL, HORIZONTAL };

  unsigned int dim() const { return dim_; }
  const battleships::coordinate &center() const { return center_; }
  orientation getOrientation() const { return orientation_; }
  const std::vector<char> &armor() const { return armor_; }

 private:
  virtual bool action(battleships::coordinate c) = 0;
  unsigned int dim_;
  battleships::coordinate center_;
  enum orientation orientation_;
  std::vector<char> armor_;

 protected:
  ship(char shipChar,std::vector<char> armor, unsigned int dim, const battleships::coordinate &center, orientation orientation)
      : shipChar_{shipChar}, armor_(std::move(armor)), dim_(dim), center_(center), orientation_(orientation) {}
  char shipChar_;
};
#endif //BATTAGLIANAVALE_LIB_DEF_SHIP_H_
