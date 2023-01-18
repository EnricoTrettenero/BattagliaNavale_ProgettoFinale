/**
 * @file Human.cpp
 * @author Valentin Necula
 *
 */
#include <iostream>
#include "../../lib/Human.h"

std::string human::doAction(std::string input)
{
    std::cout << std::endl << input << std::endl; //print the input communication string
    std::string in;
    std::getline(std::cin, in, '\n'); //read line from std in and sto at the end of line
    return in;
}

//constructor
human::human(const std::string &name) : player(name) {}
