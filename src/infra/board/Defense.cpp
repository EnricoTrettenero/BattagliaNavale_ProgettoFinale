//
// Created by vale on 27/12/22.
//

#include "../../../lib/board/Defense.h"
defense::defense()
{
    for (int i = 0; i < kDimBoard; ++i)
    {
        for (int j = 0; j < kDimBoard; ++j)
        {
            _matrix[i][j] = '*';
        }
    }
}
bool defense::setShip(ship &s)
{
    //check space on board
    for (int i = 0; i < s.dim(); ++i)
    {
        if (s.getOrientation() == ship::HORIZONTAL)
        {
            if ((s.center().y() + i - s.dim() / 2)<0||s.center().y() + i - s.dim() / 2>11||_matrix[s.center().x() ][s.center().y()+ i - s.dim() / 2] != '*') //assume all ship is odd

                return false;
        } else
        {
            if ((s.center().x() + i - s.dim() / 2)<0||s.center().x() + i - s.dim() / 2>11||_matrix[s.center().x() + i - s.dim() / 2][s.center().y()] != '*') //assume all ship is odd
                return false;
        }
    }
    for (int i = 0; i < s.dim(); ++i)
    {
        if (s.getOrientation() == ship::HORIZONTAL)
        {
            _matrix[s.center().x() ][s.center().y()+ i - s.dim() / 2] = s.armor()[i];//assume all ship is odd
        } else
        {
            _matrix[s.center().x() + i - s.dim() / 2][s.center().y()] = s.armor()[i];
        }
    }
    return true;
}
