//
// Created by vale on 27/12/22.
//

#include "../../lib/Game.h"
#include "../../lib/ship/Battleship.h"
#include "../../lib/ship/Support.h"
#include "../../lib/ship/Submarine.h"
#include <string>
#include <iostream>
game::game(std::unique_ptr<player> p1, std::unique_ptr<player> p2) : p1_{std::move(p1)}, p2_{std::move(p2)}
{
    filler(p1_, defenseBoardP1_, attackBoardP1_);
    filler(p2_,defenseBoardP2_,attackBoardP2_);

}
void game::filler(std::unique_ptr<player> &p, defense &d, attack &a)
{
    for (int i = 0; i < kNumberBattleship; ++i) //insert battleships
    {
        bool error;
        do
        {
            error = false;
            try
            {
                std::pair<battleships::coordinate, ship::orientation> input = getShipData(p->doMove("input type 'coordinate orientation' insert Battleship no."+ std::to_string(i)));
                std::unique_ptr<ship> s = std::make_unique<battleship>(input.first,input.second);
                error = !d.setShip(std::move(s));
            }
            catch (std::invalid_argument &ex)
            {
                error = true;
            }
            std::cout<<d<<std::endl;
        } while (error);
    }
    for (int i = 0; i < kNumberBattleship; ++i) //insert support
    {
        bool error;
        do
        {
            error = false;
            try
            {
                std::pair<battleships::coordinate, ship::orientation>
                    input = getShipData(p->doMove("input type 'coordinate orientation' insert support no." + i));
                std::unique_ptr<ship> s = std::make_unique<support>(battleships::coordinate(10,'B'),ship::VERTICAL);
                error = !d.setShip(std::move(s));
            }
            catch (std::invalid_argument &ex)
            {
                error = true;
            }
        } while (error);
    }
    for (int i = 0; i < kNumberBattleship; ++i) //insert submarine
    {
        bool error;
        do
        {
            error = false;
            try
            {
                std::pair<battleships::coordinate, ship::orientation>
                    input = getShipData(p->doMove("input type 'coordinate orientation' insert submarine no." + i));
                std::unique_ptr<ship> s = std::make_unique<submarine>(battleships::coordinate(10,'B'),ship::VERTICAL);
                error = !d.setShip(std::move(s));
            }
            catch (std::invalid_argument &ex)
            {
                error = true;
            }
        } while (error);
    }
}
std::pair<battleships::coordinate, ship::orientation> game::getShipData(const std::string &s)
{
    battleships::coordinate outputCoordinate;
    ship::orientation outputOrientation;
    if (s.length() != 4 && s.length() != 5) throw std::invalid_argument("invalid length");
    int position = s.find(' ');
    if (position != 2 && position != 3) throw std::invalid_argument("separator char not found");
    std::string stringCoordinate = s.substr(0, position);
    std::string stringOrientation = s.substr(position + 1, 1);
    //pass-through exception
    if (stringCoordinate.length() == 2)
        outputCoordinate =
            battleships::coordinate((int) (stringCoordinate[1]), stringCoordinate[0]); //self check-boundary
    else
        outputCoordinate = battleships::coordinate(stoi(stringCoordinate.substr(1, 2)), stringCoordinate[0]);
    if (stringOrientation == "H")
        outputOrientation = ship::HORIZONTAL;
    else if (stringOrientation == "V")
        outputOrientation = ship::VERTICAL;
    else throw std::invalid_argument("Orientation not valid");

    return std::make_pair(outputCoordinate, outputOrientation);
}

void game::make_action(const std::vector<std::pair<char,battleships::coordinate>>& vec, defense ally_defense, defense enemy_defense, attack ally_attack)
{
    for(auto it = vec.begin(), end = vec.end(); it != end; ++it)
    {
        switch(it->first)
        {
            case ('M'):
                ally_defense.move(it->second,(it+1)->second);
                it++; //dobbiamo andare al pair successivo
                break;

            case ('S'):
                ally_defense.repair_ship(it->second);
                break;

            case ('C'):
                enemy_defense.fire(it->second);
                if(enemy_defense.isDamaged(it->second))
                    ally_attack.hit(it->second);
                else
                    ally_attack.water(it->second);
                break;

            case ('E'):
                break;
        }
    }
}