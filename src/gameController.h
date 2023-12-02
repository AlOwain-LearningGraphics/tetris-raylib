#pragma once

#include "tetromino.h"
#include "raylib.h"
#include "grid.h"

class gameController {
public:
    gameController();

    void draw();
    void logic();
    void reset();
private:
    float time_since_move, ticks_per_sec, time_since_physics_tick, physics_ticks_per_sec;
    
    tetromino::input_type next_move;

    grid game_grid;
    tetromino piece;
};
