#pragma once
#include "iVector2.h"
#include "raylib.h"
#include <cassert>
#include <vector>

#ifndef BLOCK_SIZE
#define BLOCK_SIZE 40
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

class grid {
public:
    grid();

    void draw();
    void reset();
    bool logic(std::vector<iVector2> posList, Color color);

    void occupy_pos(std::vector<iVector2> posList, Color color);
    bool is_occupied(std::vector<iVector2> posList);
private:
    static Color items[GRID_WIDTH][GRID_HEIGHT];
    static short drawing_order[GRID_HEIGHT];

    void reset_row(short row);
    void check_completed_rows();
    bool check_for_endgame();
    
    void printGrid();
};
