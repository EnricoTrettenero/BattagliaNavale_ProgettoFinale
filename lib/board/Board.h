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

  static constexpr int kDimBoard = 12; //rappresenta dim lati matrice
  std::vector<std::vector<char>> matrix() const; //restituisce un vector di char chiamato matrix
 protected:
  char _matrix[kDimBoard][kDimBoard]; //creazione matrice di char
  friend std::ostream &operator<<(std::ostream &os, const board &b);
 private:
  static constexpr int kDimForTable = 3; //dimensione degli spazi tra un carattere e l'altro quando si stampa (si consiglia come minimo 2 )
  static const std::string &padWithSpace(std::string &s);
  static std::string spaced(const std::string& s);
};
#endif //BATTAGLIANAVALE_LIB_BOARD_H_
