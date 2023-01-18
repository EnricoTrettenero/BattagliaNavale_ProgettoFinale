/**
 * @file Board.h
 * @author Davide Redana
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

    //board dimension
    static constexpr int kDimBoard = 12;

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
    * @brief takes two boards and concatenates them one beside the other
    *
    * @return a string representing the two paired boards
    */
    static std::string concat2string(const std::string &str1, const std::string &str2);

    /**
    * @brief destructor standard
    */
    ~board() = default;
    protected:

    //matrix of chars that represents the board
    char _matrix[kDimBoard][kDimBoard];

    //overloading of operator<<
    friend std::ostream &operator<<(std::ostream &os, const board &b);

    private:

    //distance between a char and the other when printing
    static constexpr int kDimForTable = 3;
    static constexpr int kLeftSpace = (kDimForTable - 1) / 2;
    static constexpr int kRightSpace = (kDimForTable - 1) % 2 + 1;

    /**
    * @brief center the string s in according to the matrix length
    * @param s = input string
    * @return input string with padded space
    */
    static const std::string &padWithSpace(std::string &s);

    /**
    * @brief insert space in the string for optimal board output
    * @param s = input string
    * @return input string with padded space
    */
    static std::string spaced(const std::string &s);

    /**
    * @brief add the color on the string for the ships
    * @param s = input string
    */
    static void colorString(std::string &s);
};
#endif //BATTAGLIANAVALE_LIB_BOARD_H_
