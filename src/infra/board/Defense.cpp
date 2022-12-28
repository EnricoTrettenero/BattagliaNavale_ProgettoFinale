//
// Created by vale on 27/12/22.
//

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
bool defense::fire(battleships::coordinate xy) //TODO
{
    if (_matrix[xy.x()][xy.y()] != ' ')
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

                      // _matrix[ships.at(i)->center().x()]
                        if(ships.at(i)->hit(j))
                            sunk(ships.at(i)->center());
                    }
                } else
                {
                    if (ships.at(i)->center().y() == xy.y()
                        && ships.at(i)->center().x() - ships.at(i)->dim() / 2 + j == xy.x())
                    {

                    }
                }
            }
        }
    }
    return false;
}
void defense::sunk(battleships::coordinate xy)
{

}
