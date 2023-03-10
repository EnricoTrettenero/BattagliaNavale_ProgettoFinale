/**
 * @file Defence.cpp
 * @author Davide Redana
 *
 */

#include <iostream>
#include "../../../lib/board/Defense.h"

defense::defense() : board()
{
    //for each slot of the matrix...
    for (auto &i : _matrix)
    {
        //...set the char of the slot to '*'
        for (char &j : i) { j = kBoardChar; }
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
            if ((s->centre().x() + i - s->dim() / 2) < 0 || s->centre().x() + i - s->dim() / 2 > kDimBoard - 1
                || _matrix[s->centre().y()][s->centre().x() + i - s->dim() / 2] != kBoardChar)
                return false; //if it's not free return false

        } else if (s->getOrientation() == ship::VERTICAL)
        {
            //check if the space needed for a vertical insertion is free
            if ((s->centre().y() + i - s->dim() / 2) < 0 || s->centre().y() + i - s->dim() / 2 > kDimBoard - 1
                || _matrix[s->centre().y() + i - s->dim() / 2][s->centre().x()] != kBoardChar)
                return false; //if it's not free return false
        } else
            throw std::invalid_argument("orientation not valid");
    }
    for (int i = 0; i < s->dim(); ++i)
    {
        if (s->getOrientation() == ship::HORIZONTAL)
        {
            //insert the horizontal ship on the board with the corresponding chars
            _matrix[s->centre().y()][s->centre().x() + i - s->dim() / 2] = s->armor()[i];
        } else if (s->getOrientation() == ship::VERTICAL)
        {
            //insert the horizontal ship on the board with the corresponding chars
            _matrix[s->centre().y() + i - s->dim() / 2][s->centre().x()] = s->armor()[i];
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
        if (ship->centre() == xyShip) //if the centre of the ships corresponds with the coordinate xyShip
            return ship->action(xyTarget); //return the action of the ship in that position
    throw std::invalid_argument("ships not found");
}

bool defense::fire(battleships::coordinate xy)
{
    //if the slot is not empty
    if (_matrix[xy.y()][xy.x()] != kBoardChar)
    {
        for (int i = 0; i < ships.size(); ++i)
        {
            for (int j = 0; j < ships.at(i)->dim(); ++j)
            {
                if (ships.at(i)->getOrientation() == ship::HORIZONTAL)
                {
                    //if the coordinate xy corresponds to a portion of the horizontal ship
                    if (ships.at(i)->centre().y() == xy.y()
                        && ships.at(i)->centre().x() - ships.at(i)->dim() / 2 + j == xy.x())
                    {
                        //lower the char on the board and on the armor because it has been hit
                        _matrix[ships.at(i)->centre().y()][ships.at(i)->centre().x() - ships.at(i)->dim() / 2 + j] =
                            tolower(_matrix[ships.at(i)->centre().y()][ships.at(i)->centre().x()
                                - ships.at(i)->dim() / 2 + j]);
                        if (ships.at(i)->hit(j))
                            sunk(i);
                        return true;
                    }
                } else
                {
                    //if the coordinate xy corresponds to a portion of the vertical ship
                    if (ships.at(i)->centre().x() == xy.x()
                        && ships.at(i)->centre().y() - ships.at(i)->dim() / 2 + j == xy.y())
                    {
                        //lower the char on the board and on the armor because it has been hit
                        _matrix[ships.at(i)->centre().y() - ships.at(i)->dim() / 2 + j][ships.at(i)->centre().x()] =
                            tolower(_matrix[ships.at(i)->centre().y() - ships.at(i)->dim() / 2
                                + j][ships.at(i)->centre().x()]);
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
    //set the chars of the slots corresponding to the ship on the board to '*'
    if (ships.at(index)->getOrientation() == ship::HORIZONTAL)
        for (int i = 0; i < ships.at(index)->dim(); ++i)
            _matrix[ships.at(index)->centre().y()][ships.at(index)->centre().x() - ships.at(index)->dim() / 2 + i] =
                kBoardChar;
    else
        for (int i = 0; i < ships.at(index)->dim(); ++i)
            _matrix[ships.at(index)->centre().y() - ships.at(index)->dim() / 2 + i][ships.at(index)->centre().x()] =
                kBoardChar;
    auto i = ships.begin() + index;
    ships.at(index).reset(); //reset the unique_ptr in the "index" position of the vector
    ships.erase(i); //erase the element of the vector corresponding to the ship
    shipCounter--; //decrement the ship counter
}

bool defense::isShip(battleships::coordinate xy)
{
    return _matrix[xy.y()][xy.x()] != kBoardChar; //check if the slot xy in the board is empty
}

bool defense::move(battleships::coordinate init_xy, battleships::coordinate final_xy)
{
    //moving on its own is not allowed (would mean turning around and no rotation is admitted)
    if (init_xy == final_xy) return false;
    if (isShip(init_xy))
    {
        //find the ship
        for (auto &i : ships)
        {
            if (i->centre() == init_xy)
            {
                //check if new space is available
                for (int j = 0; j < i->dim(); ++j)
                {

                    if (i->getOrientation() == ship::HORIZONTAL)
                    {
                        //search horizontally
                        if ((final_xy.x() + j - i->dim() / 2) < 0
                            || final_xy.x() + j - i->dim() / 2 > kDimBoard - 1)
                            return false;
                        //if find !* don't necessary mean that is invalid for example the case of move+1 in horizontal way
                        if (_matrix[final_xy.y()][final_xy.x() + j - i->dim() / 2] != kBoardChar)
                        {
                            //check if !* si part of herself
                            if (!isPartOf(battleships::coordinate(final_xy.x() + j - i->dim() / 2 + 1, final_xy.y_ch()),
                                          i))
                                return false;
                        }

                    } else
                    {
                        if ((final_xy.y() + j - i->dim() / 2) < 0
                            || final_xy.y() + j - i->dim() / 2 > kDimBoard - 1)
                            return false;

                        if (_matrix[final_xy.y() + j - i->dim() / 2][final_xy.x()]
                            != kBoardChar) //assume all ship is odd
                        {
                            if (!isPartOf(battleships::coordinate(final_xy.x() + 1, final_xy.y_ch() + j - i->dim() / 2),
                                          i))
                                return false;
                        }
                    }
                }
                //set the centre of the ship to the new position
                i->set_centre_(final_xy);

                //reset the chars of the ship corresponding to the old position on the board
                if (i->getOrientation() == ship::HORIZONTAL)
                {
                    for (int j = 0; j < i->dim(); ++j)
                        _matrix[init_xy.y()][init_xy.x() - i->dim() / 2 + j] =
                            kBoardChar;
                } else
                {
                    for (int j = 0; j < i->dim(); ++j)
                        _matrix[init_xy.y() - i->dim() / 2 + j][init_xy.x()] =
                            kBoardChar;
                }

                //set the chars of the ship corresponding to the new position on the board
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

                return true; //the operation succeeded
            }
        }
    }
    return false;
}

void defense::repair_ship(battleships::coordinate xy)
{
    //if the slot xy on the matrix is not empty...
    if (_matrix[xy.y()][xy.x()] != kBoardChar)
        for (const auto &ship : ships)
        {
            if (ship->getOrientation() == ship::HORIZONTAL)
            {
                for (int i = 0; i < ship->dim(); ++i)
                {
                    //find the ship
                    if (ship->centre().y() == xy.y() && ship->centre().x() - ship->dim() / 2 + i == xy.x())
                    {
                        //repair the armor of the ship fully
                        ship->repair_armor();

                        //reset the chars of the ship on the board to full health
                        for (int j = 0; j < ship->dim(); ++j)
                        {
                            _matrix[ship->centre().y()][ship->centre().x() - ship->dim() / 2 + j] =
                                toupper(_matrix[ship->centre().y()][ship->centre().x() - ship->dim() / 2 + j]);
                        }
                    }
                }
            } else
            {
                for (int i = 0; i < ship->dim(); ++i)
                {
                    //find the ship
                    if (ship->centre().x() == xy.x()
                        && ship->centre().y() - ship->dim() / 2 + i == xy.y())
                    {
                        //repair the armor of the ship fully
                        ship->repair_armor();

                        //reset the chars of the ship on the board to full health
                        for (int j = 0; j < ship->dim(); ++j)
                        {
                            _matrix[ship->centre().y() - ship->dim() / 2 + j][ship->centre().x()] =
                                toupper(_matrix[ship->centre().y() - ship->dim() / 2 + j][ship->centre().x()]);
                        }
                    }
                }
            }
        }
}

bool defense::isDamaged(battleships::coordinate xy)
{
    //if the slot of the matrix is not empty...
    if (_matrix[xy.y()][xy.x()] != kBoardChar)
        return islower(_matrix[xy.y()][xy.x()]); //return if that portion of a ship is damaged
    return false;
}

int defense::getShipCount() const { return shipCounter; }

bool defense::isPartOf(battleships::coordinate xy, std::unique_ptr<ship> &s)
{
    //tells if the coordinate corresponds to a portion of the ship
    for (int i = 0; i < s->dim(); ++i)
    {
        if (s->getOrientation() == ship::HORIZONTAL)
        {
            if (xy.x() == s->centre().x() + i - s->dim() / 2 && xy.y() == s->centre().y())
                return true;
        } else
        {
            if (xy.x() == s->centre().x() && xy.y() == s->centre().y() + i - s->dim() / 2)
                return true;
        }
    }
    return false;
}
const std::vector<std::unique_ptr<ship>> &defense::getShips() const { return ships; }
