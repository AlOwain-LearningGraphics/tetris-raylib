#include "gameController.h"
#include <raylib.h>


gameController::gameController() { reset(); }

void gameController::logic()
{
    time_since_last_move += GetFrameTime();

    // GetFrameTime can not be 0 or negative
    assert(time_since_last_move > 0);

    if (time_since_last_move < 1) { return; }
    
    CurrentPieceID = 0;
    pieces[CurrentPieceID].logic();

    time_since_last_move = 0;
}

void gameController::draw()
{
    // time_since_last_move would only be 0 if logic was just done
    if (time_since_last_move != 0) { return; }
    
    ClearBackground(BLACK);
    for (tetromino piece : pieces)
    {
        piece.draw({BLOCK_SIZE, BLOCK_SIZE});
    }
}

void gameController::reset()
{
    // You can make it any non-zero value 
    time_since_last_move = 1;
}
