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
                                                                                                  fileName_{fileName}
{
    fillPlayerBoards(p1_, defenseBoardP1_, attackBoardP1_);
    fillPlayerBoards(p2_, defenseBoardP2_, attackBoardP2_);
    play();
}

void game::fillPlayerBoards(std::unique_ptr<player> &p, defense &d, attack &a)
{
    d = defense();
    a = attack();
    //vale ti amo cazzo

    fillShip<submarine>(kNumberSubmarine,
                        p,
                        d,
                        submarine::className()); //template function che usa una  virtual function di player (che potrebbe essere human o ai)
    fillShip<battleship>(kNumberBattleship,
                         p,
                         d,
                         battleship::className()); //TODO fare in modo che le Knumber siano intuibili dalla classe del template
    fillShip<support>(kNumberSupport, p, d, support::className());
}

std::pair<battleships::coordinate, ship::orientation> game::getShipData(const std::string &s)
{

    ship::orientation outputOrientation;

    if (s.length() != 4 && s.length() != 5) throw std::invalid_argument("invalid length");
    int position = s.find(' ');
    if (position != 2 && position != 3) throw std::invalid_argument("separator char not found");

    std::string stringCoordinate = s.substr(0, position);
    std::string stringOrientation = s.substr(position + 1, 1);
    for (auto &c : stringOrientation) c = toupper(c);

    //pass-through exception
    if (stringOrientation == "H")
        outputOrientation = ship::HORIZONTAL;
    else if (stringOrientation == "V")
        outputOrientation = ship::VERTICAL;
    else throw std::invalid_argument("Orientation not valid");

    return std::make_pair(getCoordinate(stringCoordinate), outputOrientation);
}

void game::make_action(const std::vector<std::pair<char, battleships::coordinate>> &vec,
                       defense &ally_defense,
                       defense &enemy_defense,
                       attack &ally_attack)
{
    for (auto it = vec.begin(), end = vec.end(); it != end; ++it)
    {
        switch (it->first)
        {
            case ('M'):ally_defense.move(it->second, (it + 1)->second);
                it++; //dobbiamo andare al pair successivo
                break;

            case ('S'):ally_defense.repair_ship(it->second);
                break;

            case ('C'):enemy_defense.fire(it->second);
                if (enemy_defense.isDamaged(it->second))
                    ally_attack.hit(it->second);
                else
                    ally_attack.water(it->second);
                break;

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

void game::play()
{
    turnCounter = 0;
    turn = true;
    output_ = "";
    while (turnCounter < maxTurn)//tmp
    {
        if (maxTurn - turnCounter < 10)
        {
            std::cout << "Pay attention: " << maxTurn - turnCounter << " turns remaining!";
        };
        if (turn)
        {
            std::cout << defenseBoardP1_ << std::endl << attackBoardP1_ << std::endl;
            playTurn(p1_, defenseBoardP1_, attackBoardP1_, defenseBoardP2_);
            if (hasLost(p2_, defenseBoardP2_))
                endGame(p1_);
        } else
        {
            std::cout << defenseBoardP1_ << std::endl << attackBoardP1_ << std::endl;
            playTurn(p2_, defenseBoardP2_, attackBoardP2_, defenseBoardP1_);
            if (hasLost(p1_, defenseBoardP1_))
                endGame(p2_);
        }
        turn = !turn;
        turnCounter++;
    }

    if (turnCounter > maxTurn)
        std::cout << "Draw: max number of turns reached!";
    std::ofstream fileLog(fileName_);
    if (!fileLog.is_open()) throw std::invalid_argument("filename not valid");
    fileLog << output_;
    fileLog.close();
}
void game::playTurn(std::unique_ptr<player> &p, defense &d, attack &a, defense &enemyD)
{
    // type input AA 4 | AA 10 | AA AA | XX XX | B1 F1 | B10 F1 | B10 F10
    std::string input = p->doAction("insert move " + std::to_string(turnCounter) + " Player " + p->to_string());
    bool repeat;
    do
    {
        repeat = false;
        for (auto &c : input) c = toupper(c);
        //analyze string
        int position = input.find(' ');
        if ((input.length() >= 4 && input.length() <= 7) && (position >= 2 && position <= 3))
        {
            std::string strFirst = input.substr(0, position);
            std::string strLast = input.substr(position + 1, input.length() - position - 1);
            // special moves
            if (strFirst == "AA")
            {
                if (strLast == "AA")
                {
                    a.reset();
                    input = p->doAction("Special Moves Attack reset, insert new move ");
                    output_ += strFirst + " " + strLast + "\n";
                } else
                {
                    try
                    {
                        int val = stoi(strLast); //reset before a specific turn
                        a.reset(val);
                        input = p->doAction(
                            "Special Moves Attack reset for " + std::to_string(val) + " turn, insert new move ");
                        output_ += strFirst + " " + strLast + "\n";
                    }
                    catch (std::invalid_argument &ex)
                    {
                        std::cerr << "Formato di input non valido";
                        input = p->doAction("move Error AA second Parameter not valid");
                    }
                }
                repeat = true; //special moves

            } else if (strFirst == "XX" && strLast == "XX")
            {
                input = p->doAction(d.to_string() + "\n" + a.to_string() + "\n Special Move XX XX, insert new Move ");
                repeat = true;
                output_ += strFirst + " " + strLast + "\n";
            } else //coordinate case
            {
                try
                {
                    battleships::coordinate XYorigin = getCoordinate(strFirst);
                    battleships::coordinate XYtarget = getCoordinate(strLast);
                    make_action(d.useShip(XYorigin, XYtarget), d, enemyD, a); //implements error
                    a.nextTurn();
                    output_ += strFirst + " " + strLast + "\n";
                }
                catch (std::invalid_argument &ex)
                {
                    std::cerr << "Formato di input non valido";
                    repeat = true;
                    input = p->doAction("Input Error, coordinate not valid, re-insert move");
                }
            }
        } else
        {
            repeat = true;
            input = p->doAction("Input Error, input not valid, re-insert move");
        }
    } while (repeat);
}
battleships::coordinate game::getCoordinate(const std::string &s)
{
    std::string strCoordinate = s;
    battleships::coordinate outputCoordinate{};
    for (auto &c : strCoordinate) c = toupper(c);
    if (strCoordinate.length() == 2)
        outputCoordinate =
            battleships::coordinate(stoi(strCoordinate.substr(1, 1)), strCoordinate[0]); //self check-boundary
    else
        outputCoordinate = battleships::coordinate(stoi(strCoordinate.substr(1, 2)), strCoordinate[0]);

    return outputCoordinate;
}

void game::endGame(std::unique_ptr<player> &p)
{
    std::cout << "Game ended with player " << p->to_string() << " winning" << std::endl;
}

bool game::hasLost(std::unique_ptr<player> &p, defense &d)
{
    if (d.getShipCount() == 0)
        return true;
    return false;
}
