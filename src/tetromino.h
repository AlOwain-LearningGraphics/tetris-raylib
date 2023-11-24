#pragma once
#include "raylib.h"
#include "sVector2.h"

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
        REVERSE_SKEW
    };
    enum direction {
        UP,
        RIGHT,
        DOWN,
        LEFT
    };

    tetromino();

    void draw();
    void logic();
private:
    sVector2 pos;
    Color color;
    type tetromino_type;
    static bool grid[MAP_WIDTH][MAP_HEIGHT];
    direction tetromino_map[TETROMINO_PIECES - 1];
    float time_since_last_move;

    enum type GetRandomType();
    Color GetRandomColor();
    void CreateTetrominoMap();
};
