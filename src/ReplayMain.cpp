////
//// Created by Enry on 16/01/2023.
////
//#include <string>
//#include <vector>
//#include <stdexcept>
//#include <fstream>
//
//#include <memory>
//#include "../lib/ship/Battleship.h"
//#include "../lib/board/Attack.h"
//#include "../lib/board/Defense.h"
//#include "../lib/ship/Support.h"
//#include "../lib/ship/Submarine.h"
//#include "../lib/Player.h"
//#include "../lib/Human.h"
//#include "../lib/Ai.h"
//#include "../lib/Game.h"
//#include "../lib/Replay.h"
//#include "../lib/ReplayGame.h"
//using namespace std;
//
//int mainf(int argc, char *argv[])
//{
//    vector<string> input{&argv[0],&argv[0+argc]};
//    if(input.size()==2 && input[0][0]=='v')
//    {
//        replaygame rg = replaygame("input.txt");
//        vector<string> boards = rg.startReplay();
//        for (const auto & board : boards)
//        {
//            cout<<endl<<board<<endl;
//            string tmp;
//            cin>>tmp;
//        }
//    }
//    else if(input.size()==3&&input[0][0]=='f')
//    {
//
//    }
//    else throw std::invalid_argument("parametri passati non validi");
//    return 0;
//}