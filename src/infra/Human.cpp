//
// Created by Enry on 08/01/2023.
//
#include <iostream>
#include "../../lib/Human.h"
std::string human::doMove(std::string input)
{
    std::cout<<std::endl<<input<<std::endl;
    std::string in;
    std::getline (std::cin,in,'\n');
    std::cout<<in<<std::endl;
    return in;
}