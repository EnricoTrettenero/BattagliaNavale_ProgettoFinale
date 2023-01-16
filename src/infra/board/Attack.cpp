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
    for (auto &i : turnMatrix)
    {
        for (int &j : i)
        { j++; }
    }
}
void attack::reset()
{
    for (int i = 0; i < kDimBoard; ++i)
    {
        for (int j = 0; j < kDimBoard; ++j)
        {
            turnMatrix[i][j] = 0;
            if (_matrix[i][j] == 'Y')
                _matrix[i][j] = '*';
        }
    }
}
void attack::find(battleships::coordinate xy)
{
    _matrix[xy.y()][xy.x()] = 'Y';
    turnMatrix[xy.y()][xy.x()] = 0;
}
void attack::hit(battleships::coordinate xy)
{
    _matrix[xy.y()][xy.x()] = 'X';
    turnMatrix[xy.y()][xy.x()] = 0;
}

void attack::water(battleships::coordinate xy)
{
    _matrix[xy.y()][xy.x()] = 'O';
    turnMatrix[xy.y()][xy.x()] = 0;
}
void attack::reset(int turn)
{
    for (int i = 0; i < kDimBoard; ++i)
    {
        for (int j = 0; j < kDimBoard; ++j)
        {
            if (turnMatrix[i][j] > turn&&_matrix[i][j]=='Y')
            {
                _matrix[i][j] = '*';
                turnMatrix[i][j] = 0;
            }
        }
    }
}