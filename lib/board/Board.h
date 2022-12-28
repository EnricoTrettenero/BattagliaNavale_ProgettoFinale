//
// Created by vale on 27/12/22.
//

#ifndef BATTAGLIANAVALE_LIB_BOARD_H_
#define BATTAGLIANAVALE_LIB_BOARD_H_

#include <ostream>
#include <vector>
class board
{
 public:
  static constexpr int kDimBoard = 12;
[[nodiscard]] std::vector<std::vector<char>> matrix() const;
 protected:
  char _matrix[kDimBoard][kDimBoard];
  friend std::ostream& operator<<(std::ostream& os, const board& b);

};
#endif //BATTAGLIANAVALE_LIB_BOARD_H_
