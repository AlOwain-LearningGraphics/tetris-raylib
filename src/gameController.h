#pragma once

#include "tetromino.h"
#include "raylib.h"
#include "grid.h"

#ifndef GRID_WIDTH
#define GRID_WIDTH 10
#endif
#ifndef GRID_HEIGHT
#define GRID_HEIGHT 20
#endif
#ifndef HUD_WIDTH 
#define HUD_WIDTH 80
#endif
#ifndef HUD_HEIGHT 
#define HUD_HEIGHT 80
#endif

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
