//
// Created by Enry on 09/01/2023.
//
#include "../../lib/Replay.h"
std::string replay::to_string() { return name_; }

std::string replay::doAction(std::string input) { return moves_[position++]; }

replay::replay(const std::string &name, const std::vector<std::string> &moves)
    : player(name), moves_{moves}, position{0} {}
