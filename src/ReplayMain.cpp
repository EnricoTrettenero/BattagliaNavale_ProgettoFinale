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
#include <chrono>
#include <thread>
using namespace std;

int mainf(int argc, char *argv[])
{
    vector<string> input{&argv[0],&argv[0+argc]};

    if(input.size()==3 && input[1]=="v")
    {
        replaygame rg = replaygame("input.txt");
            vector<string> boards = rg.startReplay();
            for (const auto & board : boards)
            {
                cout<<endl<<board<<endl;
                this_thread::sleep_for(chrono::milliseconds(1000));
            }
    }
    else if(input.size()==4&&input[0][0]=='f')
    {
        replaygame rg = replaygame("input.txt");
        vector<string> boards = rg.startReplay();
        ofstream fileOutput(input[3]);
        for (const auto & board : boards)
        {
            fileOutput<<board;
        }
        fileOutput.close();
    }

    else
    {
        cout<<"Error: arguments not valid "<<endl;
    }
    return 0;
}