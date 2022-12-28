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

class coordinate
{
 private:
  static constexpr int kDim = board::kDimBoard-1;
  static constexpr int kMinX = 1;
  static constexpr int kMinY = 65; //ascii code for A
  int x_;
  char y_;
 public:
  coordinate(int x, char y) : x_{x}, y_{y}
  {
    if (x < kMinX || x > kMinX + kDim) throw std::invalid_argument("coordinate x not valid");
    if (y < kMinY || y > kMinY + kDim) throw std::invalid_argument("coordinate y not valid");
  }

  int x() const { return x_-kMinX; }

  void setX(int x)
  {
    if (x < kMinX || x > kMinX + kDim) throw std::invalid_argument("coordinate X not valid");
    x_ = x;
  }

  int y() const { return y_-kMinY; }

  void setY(char y)
  {
    if (y < kMinY || y > kMinY + kDim) throw std::invalid_argument("coordinate Y not valid");
    y_ = y;
  }

  friend std::ostream &operator<<(std::ostream &os, const coordinate &coordinate)
  {
    os << "(" << coordinate.x_ << ", " << coordinate.y_ << ")";
    return os;
  }
  bool operator==(const coordinate& input) const
  {
      return this->x()==input.x()&&this->y()==input.y();
  }
  bool operator!=(const coordinate&input) const
  {
      return this->x()!=input.x()||this->y()!=input.y();
  }
};

};
#endif //BATTAGLIANAVALE_LIB_DEF_UTILITY_H_
