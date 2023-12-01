#pragma once

#include "tetromino.h"
#include "raylib.h"
#include "grid.h"

class gameController {
public:
    gameController();

    void draw();
    void logic();
private:
    float time_between_moves;
    float time_since_last_move;
    grid game_grid;
    tetromino piece;

    void reset();
};
