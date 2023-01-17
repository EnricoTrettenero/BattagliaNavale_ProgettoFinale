//
// Created by vale on 10/01/23.
//

#ifndef BATTAGLIANAVALE_LIB_GAME_HPP_
#define BATTAGLIANAVALE_LIB_GAME_HPP_
#include <memory>
#include <iostream>
#include "../lib/ship/Ship.h"

template<typename T>
void game::fillShip(int kNumber, std::unique_ptr<player> &p, defense &d, std::string type)
{
    static_assert(std::is_base_of<ship, T>::value, "T must be derived from ship");
    for (int i = 0; i < kNumber; ++i)
    {
        bool error;
        do
        {
            error = false;
            try
            {
                std::pair<battleships::coordinate, ship::orientation> input = getShipData(p->doInsert(
                    "input type 'coordinate orientation' insert " + type + " no." + std::to_string(i)));
                std::unique_ptr<ship> s = std::make_unique<T>(input.first, input.second);
                error = !d.setShip(std::move(s));
            }
            catch (std::invalid_argument &ex)
            {
                error = true;
            }
        } while (error);
    }
}

#endif //BATTAGLIANAVALE_LIB_GAME_HPP_