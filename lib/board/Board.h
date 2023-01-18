/**
 * @file Board.h
 * @author TODO
 * @brief This abstract class represents a generic board
 *
 */

#ifndef BATTAGLIANAVALE_LIB_BOARD_H_
#define BATTAGLIANAVALE_LIB_BOARD_H_

#include <ostream>
#include <vector>

class board
{
 public:

  //static constexr int that represents the board dimension
  static constexpr int kDimBoard = 12;

  //vector<vector<char>> that represents the matrix
  std::vector<std::vector<char>> matrix() const; //restituisce un vector di char chiamato matrix

  /**
  * @brief print the board
  *
  * @return a string representing the board
  */
  std::string to_string() const;
/**
    * @brief print the board without colors
    *
    * @return a string representing the board without colors
    */
  std::string to_stringNoColors() const;
  /**
  * @brief takes two string and concatenates them one beside the other
  *
  * @return a string representing the two paired strings
  */
  static std::string concat2string(const std::string &str1, const std::string &str2);

 protected:

  //matrix of chars that represents the board
  char _matrix[kDimBoard][kDimBoard];

  //overloading of operator<<
  friend std::ostream &operator<<(std::ostream &os, const board &b);

 private:

  //static constexr int representing the distance between a char and the other when printing
  static constexpr int kDimForTable = 3;
  static constexpr int kLeftSpace = (kDimForTable - 1) / 2;
  static constexpr int kRightSpace = (kDimForTable - 1) % 2 + 1;

  /**
  * TODO
  */
  static const std::string &padWithSpace(std::string &s);

  /**
  * TODO
  */
  static std::string spaced(const std::string &s);

  /**
  * TODO
  */
  static void colorString(std::string &s);
};
#endif //BATTAGLIANAVALE_LIB_BOARD_H_
