/**
 * @file Attack.cpp
 * @author Davide Redana
 *
 */

#include "../../../lib/board/Attack.h"

attack::attack() : board()
{
    for (int i = 0; i < kDimBoard; ++i)
    {
        for (int j = 0; j < kDimBoard; ++j)
        {
            //fill the whole _matrix with '*' and set each slot of turnMatrix to 0
            _matrix[i][j] = kBoardChar;
            turnMatrix[i][j] = 0;
        }
    }
}

void attack::nextTurn()
{
    //update each slot of turnMatrix incrementing it by one (one turn has passed)
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
            //reset each slot of _matrix from the previous char to '*'
            turnMatrix[i][j] = 0;
            if (_matrix[i][j] == kFindChar || _matrix[i][j] == kWaterChar || _matrix[i][j] == kHitChar)
                _matrix[i][j] = kBoardChar;
        }
    }
}

void attack::find(battleships::coordinate xy)
{
    //set the char of the slot on matrix to 'Y' and of the slot on turn-matrix to 0
    _matrix[xy.y()][xy.x()] = kFindChar;
    turnMatrix[xy.y()][xy.x()] = 0;
}

void attack::hit(battleships::coordinate xy)
{
    //set the char of the slot on matrix to 'X' and of the slot on turn-matrix to 0
    _matrix[xy.y()][xy.x()] = kHitChar;
    turnMatrix[xy.y()][xy.x()] = 0;
}

void attack::water(battleships::coordinate xy)
{
    //set the char of the slot on matrix to 'O' and of the slot on turn-matrix to 0
    _matrix[xy.y()][xy.x()] = kWaterChar;
    turnMatrix[xy.y()][xy.x()] = 0;
}

void attack::reset(int turn)
{
    for (int i = 0; i < kDimBoard; ++i)
    {
        for (int j = 0; j < kDimBoard; ++j)
        {
            //if the slots older than turn contain a Y
            if (turnMatrix[i][j] > turn&&_matrix[i][j]==kFindChar)
            {
                _matrix[i][j] = kBoardChar;
                turnMatrix[i][j] = 0;
            }
        }
    }
}