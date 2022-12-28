//
// Created by vale on 27/12/22.
//

#include "../../../lib/board/Defense.h"
defense::defense()
{
    for (int i = 0; i < kDimBoard; ++i)
    {
        for (int j = 0; j < kDimBoard; ++j)
        {
            _matrix[i][j]= ' ';
        }
    }
    filler();
}
void defense::filler() {

}
