//
// Created by vale on 27/12/22.
//

#include "../../lib/Game.h"
#include "../../lib/ship/Battleship.h"
#include "../../lib/ship/Support.h"
#include "../../lib/ship/Submarine.h"
#include <string>
game::game(std::unique_ptr<player> p1, std::unique_ptr<player> p2) : p1_{std::move(p1)}, p2_{std::move(p2)}
{
    filler(p1_, defenseBoardP1_, attackBoardP1_);
}
void game::filler(std::unique_ptr<player> &p, defense &d, attack &a)
{
    for (int i = 0; i < kNumberBattleship; ++i) //insert battleships
    {
        bool repeat = true;
        do
        {
            std::string tmp = p->doMove("insert Battleship "+std::to_string(i)+"expected 1 coordinate and orientation H or V");
            try
            {
                char y = tmp[0];
                ship::orientation o = tmp[4] == 'H' ? ship::HORIZONTAL : ship::VERTICAL;
                tmp.erase(tmp.begin());
                battleships::coordinate xy = battleships::coordinate(std::stoi(tmp), y);
                std::unique_ptr<ship> p = std::make_unique<battleship>(xy, o);
                if (d.setShip(std::move(p)))
                    repeat = false;
            }
            catch (std::invalid_argument ex) {}
        } while (repeat);
    }
    for (int i = 0; i < kNumberSupport; ++i) //insert support
    {
        bool repeat = true;
        do
        {
            std::string
                tmp = p->doMove("insert support " + std::to_string(i) + "expected 1 coordinate and orientation H or V");
            try
            {
                char y = tmp[0];
                ship::orientation o = tmp[4] == 'H' ? ship::HORIZONTAL : ship::VERTICAL;
                tmp.erase(tmp.begin());
                battleships::coordinate xy = battleships::coordinate(std::stoi(tmp), y);
                std::unique_ptr<ship> p = std::make_unique<support>(xy, o);
                if (d.setShip(std::move(p)))
                    repeat = false;
            }
            catch (std::invalid_argument ex)
            {
            }
        } while (repeat);
    }
    for (int i = 0; i < kNumberSubmarine; ++i) //insert submarine
    {
        bool repeat = true;
        do
        {
            std::string tmp =
                p->doMove("insert Battleship " + std::to_string(i) + "expected 1 coordinate and orientation H or V");
            try
            {
                char y = tmp[0];
                ship::orientation o = tmp[4] == 'H' ? ship::HORIZONTAL : ship::VERTICAL;
                tmp.erase(tmp.begin());
                battleships::coordinate xy = battleships::coordinate(std::stoi(tmp), y);
                std::unique_ptr<ship> p = std::make_unique<submarine>(xy, o);
                if (d.setShip(std::move(p)))
                    repeat = false;
            }
            catch (std::invalid_argument ex)
            {
            }
        } while (repeat);
    }
}
