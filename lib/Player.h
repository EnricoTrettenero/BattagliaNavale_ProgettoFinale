//
// Created by vale on 27/12/22.
//

#ifndef BATTAGLIANAVALE_LIB_PLAYER_H_
#define BATTAGLIANAVALE_LIB_PLAYER_H_
#include <string>
class player
{
 public:
    virtual std::string doMove(std::string input) =0;

};

#endif //BATTAGLIANAVALE_LIB_PLAYER_H_
