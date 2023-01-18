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

int main(int argc, char *argv[])
{
    //convert argv to vector for easy use
    vector<string> input{&argv[0], &argv[0 + argc]};

    try
    {
        //try replay
        replaygame rg = replaygame(input[2]);
        vector<string> boards = rg.startReplay();
        if (input.size() == 3 && input[1] == "v") //case output on screen
        {

            for (const auto &board : boards)
            {
                cout << endl << board << endl;
                this_thread::sleep_for(chrono::milliseconds(1000)); //for 1 sec pause
            }
        } else if (input.size() == 4 && input[1] == "f") //case ouput on file
        {
            ofstream fileOutput(input[3]);
            for (const auto &board : boards)
            {
                fileOutput << board;
            }
            fileOutput.close();
        } else
        {
            cout << "Error: arguments not valid " << endl;
            return 1;
        }
    }
    catch (exception &ex)
    {
        cout<<"log file not valid"<<endl;
        return 1;
    }

    return 0;
}