////
//// Created by Enry on 16/01/2023.
////
#include <string>
#include <vector>
#include <stdexcept>
#include <fstream>
#include "../lib/ship/Battleship.h"
#include "../lib/board/Attack.h"
#include "../lib/board/Defense.h"
#include "../lib/Player.h"
#include "../lib/Game.h"
#include "../lib/Replay.h"
#include "../lib/ReplayGame.h"
using namespace std;

int main(int argc, char *argv[])
{
    vector<string> input{&argv[0],&argv[0+argc]};

    if(input.size()==3 && input[1]=="v")
    {
        replaygame rg = replaygame("input.txt");
            vector<string> boards = rg.startReplay();
            for (const auto & board : boards)
            {
                cout<<endl<<board<<endl;
            }
    }
    else if(input.size()==3&&input[0][0]=='f')
    {

    }
    else throw std::invalid_argument("file not valid");
    return 0;
}