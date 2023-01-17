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
                std::pair<battleships::coordinate, battleships::coordinate> input = getShipData(p->doAction(
                    "input type 'coordinate orientation' insert " + type + " no." + std::to_string(i)));
                std::unique_ptr<ship> s = std::make_unique<T>(input.first, input.second);
                error = !d.setShip(std::move(s));
                if (error) {}
                else
                {
                    output_ += p->to_string() + ":" + input.first.to_string() + " " + input.second.to_string() + "\n";
                }
            }
            catch (std::invalid_argument &ex)
            {
                // std::cerr << "Formato di input non valido";
                error = true;
            }
        } while (error);
    }
}

#endif //BATTAGLIANAVALE_LIB_GAME_HPP_
