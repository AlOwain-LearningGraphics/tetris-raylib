#pragma once
#include "raylib.h"
#include "iVector2.h"
#include <assert.h>

#define MAP_HEIGHT 20
#define MAP_WIDTH 10
#define TETROMINO_PIECES 4

class tetromino {
public:
    enum type {
        STRAIGHT,
        SQUARE,
        L_TYPE,
        J_TYPE,
        SKEW,
        REVERSE_SKEW,
        GAME_ENDED_OUT_OF_BOUNDS
    };
    enum direction {
        UP,
        RIGHT,
        DOWN,
        LEFT
    };

    tetromino();

    void draw(iVector2 map_dimensions);
    void logic();
private:
    static float time_since_last_move;
    static bool grid[MAP_WIDTH][MAP_HEIGHT];
    iVector2 pos;
    Color color;
    type tetromino_type;
    direction tetromino_map[TETROMINO_PIECES - 1];

    void CreateTetrominoMap();
    iVector2 TraverseMap(int index);
    bool ChangePos(iVector2 newPos);
};
