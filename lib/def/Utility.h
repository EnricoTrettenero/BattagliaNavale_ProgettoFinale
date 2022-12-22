//
// Created by Enry on 22/12/2022.
//

#ifndef BATTAGLIANAVALE_LIB_DEF_UTILITY_H_
#define BATTAGLIANAVALE_LIB_DEF_UTILITY_H_
#include <stdexcept>
namespace battleship
{

  class coordinate
  {
   private:
    int _x, _y;
   public:
    coordinate(int x, int y) : _x{x}, _y{y}
    {
        if (x < 0 || y < 0) throw std::invalid_argument("coordinate not valid");
    }
    int GetX() const
    {
        return _x;
    }
    void SetX(int x)
    {
        if (x < 0) throw std::invalid_argument("coordinate X not valid");
        _x = x;
    }
    int GetY() const
    {
        return _y;
    }
    void SetY(int y)
    {
        if (y < 0) throw std::invalid_argument("coordinate X not valid");
        _y = y;
    }

  };

};
#endif //BATTAGLIANAVALE_LIB_DEF_UTILITY_H_
