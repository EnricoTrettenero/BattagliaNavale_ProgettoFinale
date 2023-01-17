/**
 * @file Board.h
 * @author TODO
 * @brief This abstract class represents a generic board
 * @date 2023-01-17
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef BATTAGLIANAVALE_LIB_BOARD_H_
#define BATTAGLIANAVALE_LIB_BOARD_H_

#include <ostream>
#include <vector>
class board
{
public:

    //matrix that represents the board
    static constexpr int kDimBoard = 12; //rappresenta dim lati matrice
    std::vector<std::vector<char>> matrix() const; //restituisce un vector di char chiamato matrix

    /**
    * @brief check if the move is valid
    *
    * @param move a move from the human player
    * @return true if valid
    * @return false if invalid
    */

    std::string to_string() const;
    static std::string concat2string(const std::string &str1, const std::string &str2) ;

protected:
    char _matrix[kDimBoard][kDimBoard]; //creazione matrice di char
    friend std::ostream &operator<<(std::ostream &os, const board &b);

private:
    //dimensione degli spazi tra un carattere e l'altro quando si stampa (si consiglia come minimo 3, NUMERI DISPARI PLIS)
    static constexpr int kDimForTable = 3;
    static constexpr int kLeftSpace = (kDimForTable - 1) / 2;
    static constexpr int kRightSpace = (kDimForTable - 1) % 2 + 1;

    static const std::string &padWithSpace(std::string &s);
    static std::string spaced(const std::string &s);
    static void colorString(std::string &s);
};
#endif //BATTAGLIANAVALE_LIB_BOARD_H_
