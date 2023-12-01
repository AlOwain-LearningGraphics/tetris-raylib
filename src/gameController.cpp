#include "gameController.h"
#include <raylib.h>

gameController::gameController() { reset(); }

void gameController::logic()
{
    time_since_last_move += GetFrameTime();
    time_since_logic += GetFrameTime();

    if (time_since_last_move < move_delay) { return; }

    piece.input();
    if (time_since_logic >= logic_delay)
    {
        time_since_logic = 0;
        if (!piece.logic()) 
        {
            game_grid.occupy_pos(piece.get_pos(), piece.get_color());
            piece.reset();
        }
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

    time_since_last_move = 0;
    time_since_logic = 0;
    move_delay = 0.1;
    logic_delay = 0.5;
}
