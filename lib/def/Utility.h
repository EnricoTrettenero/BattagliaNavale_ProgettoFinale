//
// Created by Enry on 22/12/2022.
//

#ifndef BATTAGLIANAVALE_LIB_DEF_UTILITY_H_
#define BATTAGLIANAVALE_LIB_DEF_UTILITY_H_
#include <stdexcept>
#include <ostream>
#include "../board/Board.h"
namespace battleships
{

namespace colors{
static constexpr auto& reset() { return "\033[0m"; }
}

class coordinate
{
 private:
  static constexpr int kDim = board::kDimBoard - 1;

  int x_;
  char y_;

 public:
  static constexpr int kMinX = 1;
  static constexpr int kMinY = 65; //ascii code for A
  //constructor
  coordinate(int x, char y) : x_{x}, y_{y}
  {
      if (x < kMinX || x > kMinX + kDim) throw std::invalid_argument("coordinate x not valid");
      if (y < kMinY || y > kMinY + kDim) throw std::invalid_argument("coordinate y not valid");
  }

  //getter
  int x() const { return x_ - kMinX; }
  int y() const { return y_ - kMinY; }
  char y_ch() const { return y_; }


  //operators overload
  friend std::ostream &operator<<(std::ostream &os, const coordinate &coordinate)
  {
      os << "(" << coordinate.x_ << ", " << coordinate.y_ << ")";
      return os;
  }
  bool operator==(const coordinate &input) const
  {
      return this->x() == input.x() && this->y() == input.y();
  }
  bool operator!=(const coordinate &input) const
  {
      return this->x() != input.x() || this->y() != input.y();
  }

  coordinate &operator=(coordinate new_coord)
  {
      this->x_ = new_coord.x();
      this->y_ = new_coord.y_ch();
      return *this;
  }

  explicit coordinate()
  {

  }
};

}
#endif //BATTAGLIANAVALE_LIB_DEF_UTILITY_H_
