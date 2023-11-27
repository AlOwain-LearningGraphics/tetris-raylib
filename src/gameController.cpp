#include "gameController.h"

gameController::gameController() { reset(); }

void gameController::logic()
{
    time_since_last_move += GetFrameTime();

    // GetFrameTime can not be 0 or negative
    assert(time_since_last_move > 0);

    if (time_since_last_move < time_between_moves) { return; }
    
    if (!piece.logic())
    {
        piece.reset();
    }

    time_since_last_move = 0;
}

void gameController::draw()
{
    // time_since_last_move would only be 0 if logic was just done
    if (time_since_last_move != 0) { return; }
    
    ClearBackground(BLACK);
    
    // FIXME: Provide actual map dimensions instead of this hack
    piece.draw({40, 40});
}

void gameController::reset()
{
    piece.reset();

    // You can make it any non-zero value 
    time_between_moves = 1;
    time_since_last_move = 1;
}
