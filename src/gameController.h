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
    float time_since_last_move;
    float time_since_logic;
    float move_delay;
    float logic_delay;
    grid game_grid;
    tetromino piece;

    void reset();
};
