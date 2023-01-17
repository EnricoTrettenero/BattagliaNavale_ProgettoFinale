//
// Created by Enry on 09/01/2023.
//
#include "../../lib/Replay.h"
std::string replay::to_string()
{
    return "Replay " + name_;
}
std::string replay::doAction(std::string input)
{
    return moves_[position]!="" ? moves_[position++] : "A5 B5";
}

std::string replay::doInsert(std::string input)
{
    return moves_[position++];

}
replay::replay(const std::string &name, const std::vector<std::string> &moves) : player(name), printOrRead{true}, moves_{moves}, position{0}
{

}
const std::string &replay::getOutputString() const
{
    return outputString_;
}
