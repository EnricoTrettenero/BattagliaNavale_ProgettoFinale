//
// Created by Enry on 08/01/2023.
//
#include <iostream>
#include "../../lib/Human.h"
std::string human::doMove(std::string input)
{
    std::cout << std::endl << input << std::endl;
    std::string in;
    std::getline(std::cin, in, '\n'); //prendi il dato da std::cin, mettilo nella variabile in, carattere delimitante \n
    std::cout << in << std::endl;
    return in;
}
std::string human::to_string()
{
    return "Human: " + name_;
}
human::human(const std::string &name) : player(name)
{}
