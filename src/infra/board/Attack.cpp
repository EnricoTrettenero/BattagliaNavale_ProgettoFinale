//
// Created by vale on 27/12/22.
//

#include "../../../lib/board/Attack.h"
attack::attack() : board()
{
    for (int i = 0; i < kDimBoard; ++i)
    {
        for (int j = 0; j < kDimBoard; ++j)
        {
            _matrix[i][j] = '*';
            turnMatrix[i][j] = 0;
        }
    }
}
void attack::nextTurn()
{
    for (int i = 0; i < kDimBoard; ++i)
    {
        for (int j = 0; j < kDimBoard; ++j)
        {
            turnMatrix[i][j]++;
        }
    }
}
void attack::reset()
{
    for (int i = 0; i < kDimBoard; ++i)
    {
        for (int j = 0; j < kDimBoard; ++j)
        {
            turnMatrix[i][j]=0;
            _matrix[i][j]='*';
        }
    }
}
void attack::find(battleships::coordinate xy)
{
    _matrix[xy.x()][xy.y()] = 'Y';
    turnMatrix[xy.x()][xy.y()]= 0;
}
void attack::hit(battleships::coordinate xy)
{
    _matrix[xy.x()][xy.y()] = 'X';
    turnMatrix[xy.x()][xy.y()]= 0;
}

void attack::water(battleships::coordinate xy)
{
    _matrix[xy.x()][xy.y()] = 'O';
    turnMatrix[xy.x()][xy.y()]= 0;
}
void attack::reset(int turn)
{
    for (int i = 0; i < kDimBoard; ++i)
    {
        for (int j = 0; j < kDimBoard; ++j)
        {
            if(turnMatrix[i][j]>turn)
            {
                _matrix[i][j]='*';
                turnMatrix[i][j]=0;
            }
        }
    }
}