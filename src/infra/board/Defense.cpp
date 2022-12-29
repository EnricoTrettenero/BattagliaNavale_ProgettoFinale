//
// Created by vale on 27/12/22.
//

#include <iostream>
#include "../../../lib/board/Defense.h"
defense::defense() : board()
{
    for (auto &i : _matrix)
    {
        for (char &j : i)
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
            if ((s->center().y() + i - s->dim() / 2) < 0 || s->center().y() + i - s->dim() / 2 > 11
                || _matrix[s->center().x()][s->center().y() + i - s->dim() / 2] != '*') //assume all ship is odd

                return false;
        } else
        {
            if ((s->center().x() + i - s->dim() / 2) < 0 || s->center().x() + i - s->dim() / 2 > 11
                || _matrix[s->center().x() + i - s->dim() / 2][s->center().y()] != '*') //assume all ship is odd
                return false;
        }
    }
    for (int i = 0; i < s->dim(); ++i)
    {
        if (s->getOrientation() == ship::HORIZONTAL)
        {
            _matrix[s->center().x()][s->center().y() + i - s->dim() / 2] = s->armor()[i];//assume all ship is odd
        } else
        {
            _matrix[s->center().x() + i - s->dim() / 2][s->center().y()] = s->armor()[i];
        }
    }
    ships.push_back(std::move(s)); //siummm
    return true;
}
bool defense::useShip(battleships::coordinate xyShip, battleships::coordinate xyTarget)
{
    for (const auto &ship : ships)
        if (ship->center() == xyShip)
            return ship->action(xyTarget);
    return false;
}
bool defense::fire(battleships::coordinate xy) //return true if hit
{
    if (_matrix[xy.x()][xy.y()] != '*')
    {
        for (int i = 0; i < ships.size(); ++i)
        {
            for (int j = 0; j < ships.at(i)->dim(); ++j)
            {
                if (ships.at(i)->getOrientation() == ship::HORIZONTAL)
                {
                    if (ships.at(i)->center().x() == xy.x()
                        && ships.at(i)->center().y() - ships.at(i)->dim() / 2 + j == xy.y())
                    {

                        _matrix[ships.at(i)->center().x()][ships.at(i)->center().y() - ships.at(i)->dim() / 2 + j] =
                            tolower(_matrix[ships.at(i)->center().x()][ships.at(i)->center().y()
                                - ships.at(i)->dim() / 2 + j]);
                        if (ships.at(i)->hit(j))
                            sunk(i);
                        return true;
                    }
                } else
                {
                    if (ships.at(i)->center().y() == xy.y()
                        && ships.at(i)->center().x() - ships.at(i)->dim() / 2 + j == xy.x())
                    {
                        _matrix[ships.at(i)->center().x() - ships.at(i)->dim() / 2 + j][ships.at(i)->center().y()] =
                            tolower(_matrix[ships.at(i)->center().x() - ships.at(i)->dim() / 2
                                + j][ships.at(i)->center().y()]);
                        if (ships.at(i)->hit(j))
                            sunk(i);
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
void defense::sunk(int index) //destroy the ship
{
    if (ships.at(index)->getOrientation() == ship::HORIZONTAL)
        for (int i = 0; i < ships.at(index)->dim(); ++i)
            _matrix[ships.at(index)->center().x()][ships.at(index)->center().y() - ships.at(index)->dim() / 2 + i] =
                '*';
    else
        for (int i = 0; i < ships.at(index)->dim(); ++i)
            _matrix[ships.at(index)->center().x() - ships.at(index)->dim() / 2 + i][ships.at(index)->center().y()] =
                '*';
    auto i = ships.begin() + index;
    ships.at(index).reset();
    ships.erase(i);
}
bool defense::isShip(battleships::coordinate xy) //coordinate self-check validity
{
    return _matrix[xy.x()][xy.y()] != '*';
}
std::vector<battleships::coordinate> defense::isShip(battleships::coordinate xy,
                                                     unsigned int radius) //radius must be and odd number
{
    std::vector<battleships::coordinate> output = std::vector<battleships::coordinate>();
    for (int i = 0; i < radius; ++i)
    {
        for (int j = 0; j < radius; ++j)
        {
            if (xy.x() + i - radius / 2 < 0 || xy.x() + i - radius / 2 > 11 || xy.y() + j - radius / 2 < 0
                || xy.y() + j - radius / 2 > 11)
                throw std::invalid_argument("radius error");
            if (_matrix[xy.x() + i - radius / 2][xy.y() + j - radius / 2] != '*')
                output.emplace_back(xy.x() + i - radius / 2 + 1, xy.y() + j - radius / 2 + 'A');
        }
    }
    return output; //copy
}

bool defense::move(battleships::coordinate init_xy, battleships::coordinate final_xy)
{
    if(isShip(init_xy))
    {
        for(auto & i : ships)
        {
            if(i->center() == init_xy)
            {
                i->set_center_(final_xy);
                for (int j = 0; j < i->dim(); ++j)
                {
                    if (i->getOrientation() == ship::HORIZONTAL)
                    {
                        if ((i->center().y() + j - i->dim() / 2) < 0 || i->center().y() + j - i->dim() / 2 > 11
                            || _matrix[i->center().x()][i->center().y() + j - i->dim() / 2] != '*') //assume all ship is odd
                            return false;
                    } else
                    {
                        if ((i->center().x() + j - i->dim() / 2) < 0 || i->center().x() + j - i->dim() / 2 > 11
                            || _matrix[i->center().x() + j - i->dim() / 2][i->center().y()] != '*') //assume all ship is odd
                            return false;
                    }
                }
                i->set_center_(init_xy);

                if(i->getOrientation() == ship::HORIZONTAL)
                {
                    for (int j = 0; j < i->dim(); ++j)
                        _matrix[i->center().x()][i->center().y() - i->dim() / 2 + j] =
                                '*';
                }
                else
                {
                    for (int j = 0; j < i->dim(); ++j)
                        _matrix[i->center().x() - i->dim() / 2 + j][i->center().y()] =
                                '*';
                }
                i->set_center_(final_xy);

                for (int j = 0; j < i->dim(); ++j)
                {
                    if (i->getOrientation() == ship::HORIZONTAL)
                    {
                        _matrix[i->center().x()][i->center().y() + j - i->dim() / 2] = i->armor()[j];//assume all ship is odd
                    } else
                    {
                        _matrix[i->center().x() + j - i->dim() / 2][i->center().y()] = i->armor()[j];
                    }
                }
                return true;
            }
        }
    }
    return false;
}

