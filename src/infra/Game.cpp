//
// Created by vale on 27/12/22.
//

#include "../../lib/Game.h"
#include "../../lib/ship/Battleship.h"
#include "../../lib/ship/Support.h"
#include "../../lib/ship/Submarine.h"
#include <string>
#include <iostream>
game::game(std::unique_ptr<player> p1, std::unique_ptr<player> p2, const std::string &fileName) : p1_{std::move(p1)},
                                                                                                  p2_{std::move(p2)},
                                                                                                  fileName_{fileName},
                                                                                                  turn{true},
                                                                                                  turnCounter{0}
{
    srand(time(nullptr)); //set the random seed
}

void game::fillPlayerBoards(std::unique_ptr<player> &p, defense &d, attack &a)
{
    //initialize defense and attack
    d = defense();
    a = attack();

    //fill defense board with different type of ship via template function
    fillShip<submarine>(kNumberSubmarine, p, d, submarine::className());
    fillShip<battleship>(kNumberBattleship, p, d, battleship::className());
    fillShip<support>(kNumberSupport, p, d, support::className());
}

//take a string and return a ship (to check)
//format accepted "B1 B1" | "B10 B1" | "B1 B10" | "B10 B10"
std::pair<battleships::coordinate, battleships::coordinate> game::getShipData(const std::string &s)
{
    //check length valid
    if (s.length() != 5 && s.length() != 6 && s.length() != 7) throw std::invalid_argument("invalid length");
    //find divisor char (' ')
    int position = s.find(' ');
    //divisor char must be in the centre
    if (position != 2 && position != 3) throw std::invalid_argument("separator char not found");
    //extract the coordinates
    std::string strFirst = s.substr(0, position);
    std::string strLast = s.substr(position + 1, s.length() - position - 1);
    //try to make the coordinate else coordinate throw a std::invalid_argument()
    battleships::coordinate bow = getCoordinate(strFirst);
    battleships::coordinate stern = getCoordinate(strLast);
    return std::make_pair(bow, stern);
}

//try to execute the list of action by the ship
void game::make_action(const std::vector<std::pair<char, battleships::coordinate>> &vec,
                       defense &ally_defense,
                       defense &enemy_defense,
                       attack &ally_attack)
{
    //move in the array
    for (auto it = vec.begin(), end = vec.end(); it != end; ++it)
    {
        //first element is operation, second the coordinate
        switch (it->first) //check the operation to do
        {
            //move
            case ('M'):if (!ally_defense.move(it->second, (it + 1)->second)) throw std::invalid_argument("not move");
                it++; //only action that needs two pairs to move the ship, so we increment the iterator
                break;
            //repair
            case ('S'):ally_defense.repair_ship(it->second);
                break;
            //fire
            case ('C'):
                if (enemy_defense.fire(it->second))
                    ally_attack.hit(it->second);
                else
                    ally_attack.water(it->second);
                break;
            //find
            case ('E'):
                if (enemy_defense.isShip(it->second))
                {
                    if (enemy_defense.isDamaged(it->second))
                        ally_attack.hit(it->second);
                    else
                        ally_attack.find(it->second);
                } else
                    ally_attack.water(it->second);
                break;
        }
    }
}

//start the second phase of the game, immediately after the fill
void game::play()
{
    //initialized parameter
    turnCounter = 0;

    //random first move
    turn = rand()%2==0;
    while (turnCounter < maxTurn)
    {
        //TODO
        if (maxTurn - turnCounter < 10)
        {
            std::cout << "Pay attention: " << maxTurn - turnCounter << " turns remaining!" << std::endl;
        }
        if (turn) //flip flop method
        {
            playTurn(p1_, defenseBoardP1_, attackBoardP1_, defenseBoardP2_); //do p1 turn
            if (hasLost(defenseBoardP2_)) //check win
            {
                endGame(p1_);
                break;

            }

        } else
        {
            playTurn(p2_, defenseBoardP2_, attackBoardP2_, defenseBoardP1_);
            if (hasLost(defenseBoardP1_)) //end game
            {
                endGame(p2_);
                break;


            }
        }
        turn = !turn; //flip flop
        turnCounter++;
    }

    if (turnCounter > maxTurn) //draw if number of turns exceeds
        std::cout << "Draw: max number of turns reached!";

    //print the log on file
    std::ofstream fileLog(fileName_);
    if (!fileLog.is_open()) throw std::invalid_argument("filename not valid");
    fileLog << output_;
    fileLog.close();
}

//do the player turn
void game::playTurn(std::unique_ptr<player> &p, defense &d, attack &a, defense &enemyD)
{
    // type input "AA 4" | "AA 10" | "AA AA" | "XX XX" | "B1 F1" | "B10 F1" | "B10 F10"
    //take input from player virtual doAction
    std::string input = p->doAction("insert move " + std::to_string(turnCounter) + " Player " + p->to_string());
    bool repeat;
    do //repeat if input not valid
    {
        repeat = false;
        for (auto &c : input) c = toupper(c);
        //analyze string
        int position = input.find(' ');
        if ((input.length() >= 4 && input.length() <= 7) && (position >= 2 && position <= 3))//validity check
        {
            //split string
            std::string strFirst = input.substr(0, position);
            std::string strLast = input.substr(position + 1, input.length() - position - 1);
            // special moves check
            if (strFirst == "AA")
            {
                //reset on attack board
                if (strLast == "AA")
                {
                    a.reset();
                    input = p->doAction("Special Moves Attack reset, insert new move ");
                    output_ += p->to_string() + ":" + strFirst + " " + strLast + "\n"; //register on log file the move
                }
                //reset on attack board the slots update before x turn
                else
                {
                    try
                    {
                        int val = stoi(strLast); //reset before a specific turn
                        a.reset(val);
                        input = p->doAction(
                            "Special Moves Attack reset for " + std::to_string(val) + " turn, insert new move ");
                        output_ += p->to_string() + ":" + strFirst + " " + strLast + "\n";
                    }
                    catch (std::invalid_argument &ex)
                    {
                        input = p->doAction("move Error AA second Parameter not valid");
                    }
                }
                repeat = true; //special moves repeat

            }
            //print board
            else if (strFirst == "XX" && strLast == "XX")
            {
                input = p->doAction(board::concat2string(d.to_string() , a.to_string()) + "\n Special Move XX XX, insert new Move ");
                repeat = true;

            }

            //coordinate case
            else
            {
                try //catch coordinate and make_action exception
                {
                    battleships::coordinate XYorigin = getCoordinate(strFirst);
                    battleships::coordinate XYtarget = getCoordinate(strLast);
                    make_action(d.useShip(XYorigin, XYtarget), d, enemyD, a); //throw exception if invalid move
                    a.nextTurn();//attack next turn
                    output_ += p->to_string() + ":" + strFirst + " " + strLast + "\n"; // register on log file
                }
                catch (std::invalid_argument &ex)
                {
                    repeat = true;
                    input = p->doAction("Input Error, coordinate not valid, re-insert move");
                }
            }
        }

        //general error
        else
        {
            repeat = true;
            input = p->doAction("Input Error, input not valid, re-insert move");
        }
    } while (repeat);
}

void game::startNewGame()
{
    output_ = p1_->to_string() + "\n" + p2_->to_string() + "\n"; //print the player name on log file
    fillPlayerBoards(p1_, defenseBoardP1_, attackBoardP1_); //call the filler for player
    fillPlayerBoards(p2_, defenseBoardP2_, attackBoardP2_);
    play(); //start the came
}

//convert string to coordinate throw std::invalid_argument if not valid
battleships::coordinate game::getCoordinate(const std::string &s)
{
    std::string strCoordinate = s;
    battleships::coordinate outputCoordinate{};
    for (auto &c : strCoordinate) c = toupper(c);
    if (strCoordinate.length() == 2) //check length
        outputCoordinate =
            battleships::coordinate(stoi(strCoordinate.substr(1, 1)), strCoordinate[0]); //self check-boundary
    else
        outputCoordinate = battleships::coordinate(stoi(strCoordinate.substr(1, 2)), strCoordinate[0]);

    return outputCoordinate;
}

//show end game
void game::endGame(std::unique_ptr<player> &p)
{
    std::cout << "Game ended with player " << p->to_string() << " winning" << std::endl;
}

//check if the player with the defense board passed has lost
bool game::hasLost(defense &d)
{
    return d.getShipCount() == 0;
}

//protected constructor
game::game() = default;

