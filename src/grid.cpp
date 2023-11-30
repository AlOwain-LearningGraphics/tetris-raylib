#include "grid.h"

Color grid::items[GRID_WIDTH][GRID_HEIGHT] = {{BLACK}};

grid::grid() {}

void grid::occupyPos(std::vector<iVector2> posList, Color color)
{
    for (iVector2 pos : posList)
    {
        items[pos.m_x][pos.m_y].r = color.r;
        items[pos.m_x][pos.m_y].g = color.g;
        items[pos.m_x][pos.m_y].b = color.b;
        items[pos.m_x][pos.m_y].a = color.a;
    }
}

bool grid::isOccupied(std::vector<iVector2> posList)
{
    for (iVector2 pos : posList)
    {
        if (items[pos.m_x][pos.m_y].r != BLACK.r
        &&  items[pos.m_x][pos.m_y].g != BLACK.g
        &&  items[pos.m_x][pos.m_y].g != BLACK.b
        &&  items[pos.m_x][pos.m_y].b != BLACK.a)
        {
            return true;
        }
    }
    return false;
}

void grid::draw(iVector2 map_dimensions)
{
    for (int y = 0; y < GRID_HEIGHT; y++)
    {
        for (int x = 0; x < GRID_WIDTH; x++)
        {
            DrawRectangle(x * BLOCK_SIZE + map_dimensions.m_x, GetScreenHeight() - ((y * BLOCK_SIZE) + map_dimensions.m_y), BLOCK_SIZE, BLOCK_SIZE, {items[x][y].r, items[x][y].g, items[x][y].b, items[x][y].a});
        }
    }
}

void grid::reset()
{
    for (int y = 0; y < GRID_HEIGHT; y++)
    {
        for (int x = 0; x < GRID_WIDTH; x++)
        {
            items[x][y] = BLACK;
        }
    }
}
