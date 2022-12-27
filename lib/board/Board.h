//
// Created by vale on 27/12/22.
//

#ifndef BATTAGLIANAVALE_LIB_BOARD_H_
#define BATTAGLIANAVALE_LIB_BOARD_H_

class board
{
 public:
  static constexpr int kDimBoard = 12;
 private:
  static constexpr int kMaxBoat = 8;
  char matrix_[kDimBoard][kDimBoard];
};

#endif //BATTAGLIANAVALE_LIB_BOARD_H_
