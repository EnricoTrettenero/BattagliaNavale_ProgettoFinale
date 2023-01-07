//
// Created by vale on 27/12/22.
//

#include "../../../lib/ship/Support.h"

support::support(const battleships::coordinate &center, orientation orientation) : ship(
    kSupportChar,
    std::vector<char>(kSupportDim, kSupportChar),
    kSupportDim,
    center,
    orientation
) {}

bool support::action(battleships::coordinate c, defense ally_defense, defense enemy_defense, attack enemy_attack)
{
    ally_defense.move(center(),c); //muovo la nave di supporto nella nuova posizione
    std::vector<battleships::coordinate> toBeRepairedShip = ally_defense.isShip(c,1); //ottengo le coordinate delle porzioni di nave nel raggio
    for(auto & i : toBeRepairedShip)
    {
        if(getOrientation() == HORIZONTAL) //escludo le coordinate della nave di supporto stessa
        {
            if(i != center() || (i.x() != center().x() && i.y() != center().y()+1) || (i.x() != center().x() && i.y() != center().y()-1))
            {
                ally_defense.repair_ship(i);
            }
        }
        else{
            if(i != center() || (i.y() != center().y() && i.x() != center().x()+1) || (i.y() != center().y() && i.x() != center().x()-1))
            {
                ally_defense.repair_ship(i);
            }
        }
    }
    return true;
}
