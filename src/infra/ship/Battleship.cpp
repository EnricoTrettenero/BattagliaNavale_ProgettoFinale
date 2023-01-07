//
// Created by vale on 27/12/22.
//

#include "../../../lib/ship/Battleship.h"
battleship::battleship(const battleships::coordinate &center, ship::orientation orientation) : ship(
    kBattleshipChar,
    std::vector<char>(kBattleshipDim, kBattleshipChar),
    kBattleshipDim,
    center,
    orientation
) {}

bool battleship::action(battleships::coordinate c, defense ally_defense, defense enemy_defense, attack ally_attack)
{
    bool a = enemy_defense.fire(c); //colpisce la board di difesa nemica
    if(a) //se l'ha colpita aggiorna con X la board di attacco
    {
        ally_attack.hit(c);
        return true;
    }
    else //se no aggiorna con 0 la board di attacco
    {
        ally_attack.water(c);
        return false;
    }
}
