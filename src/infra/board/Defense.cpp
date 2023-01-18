//
// Created by vale on 27/12/22.
//

#include <iostream>
#include "../../../lib/board/Defense.h"

defense::defense() : board()
{
    //for each slot of the matrix...
    for (auto &i : _matrix)
    {
        //...set the char of the slot to '*'
        for (char &j : i) { j = '*'; }
    }

    //create the vector containing the ships
    ships = std::vector<std::unique_ptr<ship>>();
}

bool defense::setShip(std::unique_ptr<ship> s)
{
    //check if there is space on the board for the insertion
    for (int i = 0; i < s->dim(); ++i)
    {
        if (s->getOrientation() == ship::HORIZONTAL)
        {
            //check if the space needed for a horizontal insertion is free
            if ((s->center().x() + i - s->dim() / 2) < 0 || s->center().x() + i - s->dim() / 2 > kDimBoard - 1
                || _matrix[s->center().y()][s->center().x() + i - s->dim() / 2] != '*')
                return false; //if it's not free return false

        } else if (s->getOrientation() == ship::VERTICAL)
        {
            //check if the space needed for a vertical insertion is free
            if ((s->center().y() + i - s->dim() / 2) < 0 || s->center().y() + i - s->dim() / 2 > kDimBoard - 1
                || _matrix[s->center().y() + i - s->dim() / 2][s->center().x()] != '*')
                return false; //if it's not free return false
        } else
            throw std::invalid_argument("orientation not valid");
    }
    for (int i = 0; i < s->dim(); ++i)
    {
        if (s->getOrientation() == ship::HORIZONTAL)
        {
            //insert the horizontal ship on the board with the corresponding chars
            _matrix[s->center().y()][s->center().x() + i - s->dim() / 2] = s->armor()[i];
        } else if (s->getOrientation() == ship::VERTICAL)
        {
            //insert the horizontal ship on the board with the corresponding chars
            _matrix[s->center().y() + i - s->dim() / 2][s->center().x()] = s->armor()[i];
        } else throw std::invalid_argument("orientation not valid");
    }

    //insert the ship in the vector holding the ships
    ships.push_back(std::move(s));
    return true;
}

std::vector<std::pair<char, battleships::coordinate>> defense::useShip(battleships::coordinate xyShip,
                                                                       battleships::coordinate xyTarget)
{
    //for each ship
    for (const auto &ship : ships)
        if (ship->center() == xyShip) //if the centre of the ships corresponds with the coordinate xyShip
            return ship->action(xyTarget); //return the action of the ship in that position
    throw std::invalid_argument("ships not found");
}

bool defense::fire(battleships::coordinate xy)
{
    //if the slot is not empty
    if (_matrix[xy.y()][xy.x()] != '*')
    {
        for (int i = 0; i < ships.size(); ++i)
        {
            for (int j = 0; j < ships.at(i)->dim(); ++j)
            {
                if (ships.at(i)->getOrientation() == ship::HORIZONTAL)
                {
                    //if the coordinate xy corresponds to a portion of the horizontal ship
                    if (ships.at(i)->center().y() == xy.y()
                        && ships.at(i)->center().x() - ships.at(i)->dim() / 2 + j == xy.x())
                    {
                        //lower the char on the board and on the armor because it has been hit
                        _matrix[ships.at(i)->center().y()][ships.at(i)->center().x() - ships.at(i)->dim() / 2 + j] =
                            tolower(_matrix[ships.at(i)->center().y()][ships.at(i)->center().x()
                                - ships.at(i)->dim() / 2 + j]);
                        if (ships.at(i)->hit(j))
                            sunk(i);
                        return true;
                    }
                } else
                {
                    //if the coordinate xy corresponds to a portion of the vertical ship
                    if (ships.at(i)->center().x() == xy.x()
                        && ships.at(i)->center().y() - ships.at(i)->dim() / 2 + j == xy.y())
                    {
                        //lower the char on the board and on the armor because it has been hit
                        _matrix[ships.at(i)->center().y() - ships.at(i)->dim() / 2 + j][ships.at(i)->center().x()] =
                            tolower(_matrix[ships.at(i)->center().y() - ships.at(i)->dim() / 2
                                + j][ships.at(i)->center().x()]);
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
            _matrix[ships.at(index)->center().y()][ships.at(index)->center().x() - ships.at(index)->dim() / 2 + i] =
                '*';
    else
        for (int i = 0; i < ships.at(index)->dim(); ++i)
            _matrix[ships.at(index)->center().y() - ships.at(index)->dim() / 2 + i][ships.at(index)->center().x()] =
                '*';
    auto i = ships.begin() + index;
    ships.at(index).reset();
    ships.erase(i);
    shipCounter--;
}
bool defense::isShip(battleships::coordinate xy) //coordinate self-check validity
{
    return _matrix[xy.y()][xy.x()] != '*';
}
std::vector<battleships::coordinate> defense::isShip(battleships::coordinate xy,
                                                     unsigned int radius) //radius must be and odd number
{
    std::vector<battleships::coordinate> output = std::vector<battleships::coordinate>();
    for (int i = 0; i < radius; ++i)
    {
        for (int j = 0; j < radius; ++j)
        {
            if (xy.x() + j - radius / 2 < 0 || xy.x() + j - radius / 2 > kDimBoard - 1 || xy.y() + i - radius / 2 < 0
                || xy.y() + i - radius / 2 > kDimBoard - 1)
            {
                //out of range
            } else if (_matrix[xy.y() + i - radius / 2][xy.x() + j - radius / 2] != '*')
            {
                output.emplace_back(xy.x() + j - radius / 2 + 1, xy.y() + i - radius / 2 + 'A');
            }
        }
    }
    return output; //copy
}

bool defense::move(battleships::coordinate init_xy, battleships::coordinate final_xy)
{
    if (isShip(init_xy))
    {
        for (auto &i : ships)
        {
            if (i->center() == init_xy)
            {
                for (int j = 0; j < i->dim(); ++j)
                {
                    if (i->getOrientation() == ship::HORIZONTAL)
                    {
                        if ((final_xy.x() + j - i->dim() / 2) < 0 || final_xy.x() + j - i->dim() / 2 > kDimBoard - 1) return false;
                            if(_matrix[final_xy.y()][final_xy.x() + j - i->dim() / 2] != '*')
                            {
                                return false;
                                for (int k = 0; k < i->dim(); ++k)
                                {
                                    if(!(final_xy.y()==init_xy.y()&&final_xy.x() + j - i->dim() / 2==init_xy.x()+k-i->dim()/2))
                                        return false;
                                }
                            }//assume all ship is odd

                    } else
                    {
                        if ((final_xy.y() + j - i->dim() / 2) < 0 || final_xy.y() + j - i->dim() / 2 > kDimBoard - 1) return false;

                            if(_matrix[final_xy.y() + j - i->dim() / 2][final_xy.x()] != '*') //assume all ship is odd
                            {
                                return false;
                                for (int k = 0; k < i->dim(); ++k)
                                {
                                    if(!(final_xy.y() + j - i->dim() / 2==init_xy.y()+k-i->dim()/2 &&final_xy.x() ==init_xy.x()))
                                        return false;
                                }
                            }
                    }
                }
                i->set_center_(final_xy);
                if (i->getOrientation() == ship::HORIZONTAL)
                {
                    for (int j = 0; j < i->dim(); ++j)
                        _matrix[init_xy.y()][init_xy.x() - i->dim() / 2 + j] =
                            '*';
                } else
                {
                    for (int j = 0; j < i->dim(); ++j)
                        _matrix[init_xy.y() - i->dim() / 2 + j][init_xy.x()] =
                            '*';
                }

                for (int j = 0; j < i->dim(); ++j)
                {
                    if (i->getOrientation() == ship::HORIZONTAL)
                    {
                        _matrix[final_xy.y()][final_xy.x() + j - i->dim() / 2] = i->armor()[j];//assume all ship is odd
                    } else
                    {
                        _matrix[final_xy.y() + j - i->dim() / 2][final_xy.x()] = i->armor()[j];
                    }
                }

                return true;
            }
        }
    }
    return false;
}

void defense::repair_ship(battleships::coordinate xy)
{
    if (_matrix[xy.y()][xy.x()] != '*')
        for (const auto &ship : ships)
        {
            if (ship->getOrientation() == ship::HORIZONTAL)
            {
                for (int i = 0; i < ship->dim(); ++i)
                {
                    if (ship->center().y() == xy.y() && ship->center().x() - ship->dim() / 2 + i == xy.x())
                    {

                        ship->repair_armor();
                        for (int j = 0; j < ship->dim(); ++j)
                        {
                            _matrix[ship->center().y()][ship->center().x() - ship->dim() / 2 + j] =
                                toupper(_matrix[ship->center().y()][ship->center().x() - ship->dim() / 2 + j]);
                        }
                    }
                }
            } else
            {
                for (int i = 0; i < ship->dim(); ++i)
                {
                    if (ship->center().x() == xy.x()
                        && ship->center().y() - ship->dim() / 2 + i == xy.y())
                    {

                        ship->repair_armor();
                        for (int j = 0; j < ship->dim(); ++j)
                        {
                            _matrix[ship->center().y() - ship->dim() / 2 + j][ship->center().x()] =
                                toupper(_matrix[ship->center().y() - ship->dim() / 2 + j][ship->center().x()]);
                        }
                    }
                }
            }
        }
}

bool defense::isDamaged(battleships::coordinate xy)
{
    if (_matrix[xy.y()][xy.x()] != '*')
        return islower(_matrix[xy.y()][xy.x()]);
    return false;
}

int defense::getShipCount() const { return shipCounter; }