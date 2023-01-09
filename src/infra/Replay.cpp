//
// Created by Enry on 09/01/2023.
//
#import "../../lib/Replay.h"
std::string replay::to_string()
{
    return "Replay " + name_;
}
std::string replay::doMove(std::string input)
{
    std::string tmp;
    getline(file_, tmp);
    return tmp;
}
replay::replay(const std::string &name) : player(name)
{
    file_ = std::ifstream(name);
    if (!file_.is_open()) throw std::invalid_argument("file not valid");
}
