//
// Created by vale on 27/12/22.
//

#include "../../../lib/board/Defense.h"
defense::defense() : board()
{
    for (auto & i : _matrix)
    {
        for (char & j : i)
        {
            j = '*';
        }
    }
    ships = std::vector<std::unique_ptr<ship>>();
}
bool defense::setShip(std::unique_ptr<ship> s)
{
    //check space on board
    for (int i = 0; i < s->dim(); ++i)
    {
        if (s->getOrientation() == ship::HORIZONTAL)
        {
            if ((s->center().y() + i - s->dim() / 2)<0||s->center().y() + i - s->dim() / 2>11||_matrix[s->center().x() ][s->center().y()+ i - s->dim() / 2] != '*') //assume all ship is odd

                return false;
        } else
        {
            if ((s->center().x() + i - s->dim() / 2)<0||s->center().x() + i - s->dim() / 2>11||_matrix[s->center().x() + i - s->dim() / 2][s->center().y()] != '*') //assume all ship is odd
                return false;
        }
    }
    for (int i = 0; i < s->dim(); ++i)
    {
        if (s->getOrientation() == ship::HORIZONTAL)
        {
            _matrix[s->center().x() ][s->center().y()+ i - s->dim() / 2] = s->armor()[i];//assume all ship is odd
        } else
        {
            _matrix[s->center().x() + i - s->dim() / 2][s->center().y()] = s->armor()[i];
        }
    }
    ships.push_back(std::move(s)); //siummm
    return true;
}
