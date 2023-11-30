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
        game_grid.occupy_pos(piece.get_pos(), piece.get_color());
        piece.reset();
    }

    time_since_last_move = 0;
}

void gameController::draw()
{
    // time_since_last_move would only be 0 if logic was just done
    if (time_since_last_move != 0) { return; }
    
    ClearBackground(BLACK);
    
    game_grid.draw();
    piece.draw();
}

void gameController::reset()
{
    piece.reset();

    // You can make it any non-zero value 
    time_between_moves = 1;
    time_since_last_move = 1;
}
