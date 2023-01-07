//
// Created by vale on 27/12/22.
//

#include "../../../lib/ship/Submarine.h"
submarine::submarine(const battleships::coordinate &center, orientation orientation) : ship(
    kSubmarineChar,
    std::vector<char>(kSubmarineDim, kSubmarineChar),
    kSubmarineDim,
    center,
    orientation
) {}

bool submarine::action(battleships::coordinate c, defense ally_defense, defense enemy_defense, attack ally_attack)
{
    ally_defense.move(center(),c); //muovo la nave nella nuova posizione
    std::vector<battleships::coordinate> found_ships = ally_defense.isShip(c,2); //ottengo le coordinate delle porzioni di nave nel raggio
    for(auto & i : found_ships)
    {
        if(enemy_defense.isDamaged(c))
        {
            ally_attack.hit(c); //se era una porzione di nave già colpita setto a X (vedasi FAQ Q14)
        } else
        {
            ally_attack.find(i); //setto ad Y nella mia board le coordinate delle navi trovate
        }

    }
    return true;
}

