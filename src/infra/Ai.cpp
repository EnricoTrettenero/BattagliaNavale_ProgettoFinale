//
// Created by Enry on 08/01/2023.
//
#include "../../lib/Ai.h"
std::string ai::doMove(std::string input)
{
    return input;
}
std::string ai::to_string()
{
    return "Ai: " + name_;
}
ai::ai(const std::string &name) : player(name)
{ }
