/**
 * @file Utility.h
 * @author TODO
 * @brief Entities commonly used across the whole library
 *
 */

#ifndef BATTAGLIANAVALE_LIB_DEF_UTILITY_H_
#define BATTAGLIANAVALE_LIB_DEF_UTILITY_H_

#include <stdexcept>
#include <ostream>
#include "../board/Board.h"

namespace battleships
{
    //namespace used for resetting colors
    namespace colors
    {
        static constexpr auto &reset()
        { return "\033[0m"; }
    }

    //class that represents a coordinate
    class coordinate
    {

    public:

        //static constexpr ints used to represent the equivalent ASCII (65 ascii code for A)
        static constexpr int kMinX = 1;
        static constexpr int kMinY = 65;

        /**
        * @brief construct a new coordinate
        * @throw invalid_argument if not valid
        */
        coordinate(int x, char y) : x_{x}, y_{y}
        {
            if (x < kMinX || x > kMinX + kDim) throw std::invalid_argument("coordinate x not valid");
            if (y < kMinY || y > kMinY + kDim) throw std::invalid_argument("coordinate y not valid");
        }

        /**
        * @brief construct a empty coordinate
        */
        explicit coordinate() : x_{1}, y_{'A'}
        {

        }

        /**
        * @brief destructor for coordinate
        */
        ~coordinate() = default;

        /**
        * @brief getter
        *
        * @return int representing the x of the coordinate
        */
        int x() const
        { return x_ - kMinX; }

        /**
        * @brief getter
        *
        * @return int representing the y of the coordinate
        */
        int y() const
        { return y_ - kMinY; }

        /**
        * @brief getter
        *
        * @return char representing the y of the coordinate
        */
        char y_ch() const
        { return y_; }

        /**
        * @brief << operator overloading
        */
        friend std::ostream &operator<<(std::ostream &os, const coordinate &coordinate)
        {
            os << "(" << coordinate.x_ << ", " << coordinate.y_ << ")";
            return os;
        }

        /**
        * @brief == operator overloading
        */
        bool operator==(const coordinate &input) const
        {
            return this->x() == input.x() && this->y() == input.y();
        }

        /**
        * @brief != operator overloading
        */
        bool operator!=(const coordinate &input) const
        {
            return this->x() != input.x() || this->y() != input.y();
        }

        /**
        * @brief = operator overloading
        */
        coordinate &operator=(coordinate new_coord)
        {
            this->x_ = new_coord.x() + 1;
            this->y_ = new_coord.y_ch();
            return *this;
        }

        /**
        * @brief print the coordinate
        *
        * @return a string representing the coordinate, format: "A1"
        */
        std::string to_string() const
        {
            return  y_+std::to_string(x_);
        }

    private:

        //static constexpr int member used for arithmetic purposes
        static constexpr int kDim = board::kDimBoard - 1;

        //ints used to represent the (x,y) of the coordinate
        int x_;
        char y_;
    };
}

#endif //BATTAGLIANAVALE_LIB_DEF_UTILITY_H_
