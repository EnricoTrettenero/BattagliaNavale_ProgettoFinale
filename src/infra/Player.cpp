//
// Created by vale on 27/12/22.
//

#include "../../lib/Player.h"
//virtual destructor
player::~player() = default;
//constructor
player::player(const std::string &name) : name_{name}
{}
//to string
std::string player::to_string() const
{
    return name_;
}