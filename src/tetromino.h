#pragma once
#include "raylib.h"
#include "iVector2.h"
#include <assert.h>
#include <vector>

#ifndef BLOCK_SIZE
#define BLOCK_SIZE 40
#endif
#ifndef TETROMINO_PIECES 
#define TETROMINO_PIECES 4
#endif
#ifndef GRID_WIDTH
#define GRID_WIDTH 10
#endif
#ifndef GRID_HEIGHT
#define GRID_HEIGHT 20
#endif

class tetromino {
public:
    enum tetromino_type {
        STRAIGHT,
        SQUARE,
        L_TYPE,
        J_TYPE,
        SKEW,
        REVERSE_SKEW,
    };
    
    tetromino();

    void draw(iVector2 map_dimensions);
    bool logic();
    Color color;
    void reset();
private:
    static bool grid[GRID_WIDTH][GRID_HEIGHT];
    iVector2 m_pos;
    tetromino_type m_tetromino_type;

    void OccupyGridPos(iVector2 pos, bool occupy);
    bool ChangePos(iVector2 newPos);
};

std::vector<iVector2> TranslatePos(iVector2 pos, tetromino::tetromino_type type);
