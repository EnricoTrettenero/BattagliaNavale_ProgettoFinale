/**
 * @file Game.hpp
 * @author Valentin Necula
 * @brief This class is used to implement a template function
 * used to fill the boards with the needed ships
 *
 */

#ifndef BATTAGLIANAVALE_LIB_GAME_HPP_
#define BATTAGLIANAVALE_LIB_GAME_HPP_

#include <memory>
#include <iostream>
#include "../lib/ship/Ship.h"

template<typename T>
void game::fillShip(int kNumber, std::unique_ptr<player> &p, defense &d, const std::string& type)
{
    //check if T is derived from ship
    static_assert(std::is_base_of<ship, T>::value, "T must be derived from ship");

    //for each ship of the type required
    for (int i = 0; i < kNumber; ++i)
    {
        bool error;
        do //repeat if there is an invalid input
        {
            try
            {
                //get the data to create the ship via player->doAction()
                std::pair<battleships::coordinate, battleships::coordinate> input = getShipData(p->doAction(
                    "input type 'coordinate orientation' insert " + type + " no." + std::to_string(i+1)));
                std::unique_ptr<ship> s = std::make_unique<T>(input.first, input.second); //create the ship
                error = !d.setShip(std::move(s)); //try to insert the ship on the player defense board
                if (!error)
                {
                    //update output_
                    output_ += p->to_string() + ":" + input.first.to_string() + " " + input.second.to_string() + "\n";
                }
            }
            catch (std::invalid_argument &ex)
            {
                error = true;
            }
        } while (error); //repeat if there is an input error
    }
}

#endif //BATTAGLIANAVALE_LIB_GAME_HPP_
