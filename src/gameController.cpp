#include "gameController.h"

gameController::gameController() { reset(); }

void gameController::logic()
{
    time_since_move += GetFrameTime();
    time_since_physics_tick += GetFrameTime();
    tetromino::input_type input_buffer = piece.input();
    next_move = (input_buffer == tetromino::NO_MOVE) ? next_move : input_buffer;

    if (time_since_physics_tick > physics_ticks_per_sec)
    {
        if (!piece.logic(tetromino::DOWN))
        {
            game_grid.occupy_pos(piece.get_pos(), piece.get_color());
            if (game_grid.check_for_endgame()) { reset(); }
            piece.reset();
        }
        time_since_physics_tick = 0;
        time_since_move = 0;
    }
    if (time_since_move > ticks_per_sec)
    {
        piece.logic(next_move);
        next_move = tetromino::NO_MOVE;
        time_since_move = 0;
    }
}

void gameController::draw()
{
    // time_since_last_move would only be 0 if logic was just done
    if (time_since_move != 0) { return; }
    
    ClearBackground(BLACK);
    
    game_grid.draw();
    piece.draw();
}

void gameController::reset()
{
    piece.reset();
    game_grid.reset();

    next_move = tetromino::NO_MOVE;
    time_since_move = 0;
    ticks_per_sec = 0.15;
    time_since_physics_tick = 0;
    physics_ticks_per_sec = 1;
}
