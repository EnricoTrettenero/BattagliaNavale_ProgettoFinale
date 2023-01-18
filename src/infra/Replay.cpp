//
// Created by Enry on 09/01/2023.
//
#include "../../lib/Replay.h"

std::string replay::doAction(std::string input) {
    if(position==moves_.size()) throw std::out_of_range("moves out of range"); //check end of array
    return moves_[position++]; } //return current moves and increment position

replay::replay(const std::string &name, const std::vector<std::string> &moves)
    : player(name), moves_{moves}, position{0} {}
