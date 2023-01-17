//
// Created by Enry on 16/01/2023.
//
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;

void doReplay(int argc, char *argv[])
{
    vector<string> input{&argv[0],&argv[0+argc]};
    if(input.size()==2 && input[0][0]=='v')
    {

    }
    else if(input.size()==3&&input[0][0]=='f')
    {

    }
    else throw std::invalid_argument("parametri passati non validi");
}