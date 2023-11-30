#include "iVector2.h"
#include "raylib.h"
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

class grid {
public:
    grid();

    void occupyPos(std::vector<iVector2> posList, Color color);
    bool isOccupied(std::vector<iVector2> posList);
    void draw(iVector2 map_dimensions);
    void reset();
private:
    static Color items[GRID_WIDTH][GRID_HEIGHT];
};
