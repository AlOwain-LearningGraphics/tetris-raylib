#pragma once

#include "tetromino.h"
#include "raylib.h"

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
#ifndef TETROMINO_PIECES
#define TETROMINO_PIECES 4
#endif
#ifndef MAX_PIECES
#define MAX_PIECES ((GRID_WIDTH * GRID_HEIGHT) / TETROMINO_PIECES) + 5
#endif

class gameController {
public:
    gameController();

    void draw();
    void logic();
private:
    float time_between_moves;
    float time_since_last_move;

    tetromino pieces[MAX_PIECES];
    int focused_piece;

    void reset();
};
