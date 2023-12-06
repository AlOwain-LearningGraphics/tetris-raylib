#pragma once
#include "raylib.h"
#include "iVector2.h"
#include "grid.h"
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
#ifndef HUD_WIDTH
#define HUD_WIDTH 80
#endif
#ifndef HUD_HEIGHT
#define HUD_HEIGHT 80
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
    enum input_type {
        LEFT,
        RIGHT,
        DOWN,
        ROTATE,
        NO_MOVE
    };
    
    tetromino();


    void draw();
    bool logic(input_type next_move);
    input_type input();
    void reset();
    std::vector<iVector2> get_pos();
    Color get_color();
private:
    iVector2 m_pos;
    bool m_rotation = false;
    tetromino_type m_tetromino_type;
    Color m_color;

    bool change_pos(iVector2 newPos, bool rotation);
};

std::vector<iVector2> TranslatePos(iVector2 pos, tetromino::tetromino_type type, bool rotation);
bool OutOfBounds(std::vector<iVector2> tGrid);
