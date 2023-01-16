//
// Created by Enry on 08/01/2023.
//
#include <iostream>
#include "../../lib/Ai.h"
std::string ai::doAction(std::string input)
{
    return input;
}
std::string ai::doInsert(std::string input)
{
    std::cout << std::endl << input << std::endl;
    return "C10 V"; //TODO fixme (implementare random inserimento- adesso va in loop)
}
std::string ai::to_string()
{
    return "Ai: " + name_;
}
ai::ai(const std::string &name) : player(name) {}
