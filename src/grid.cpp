#include "grid.h"

Color grid::items[GRID_WIDTH][GRID_HEIGHT] = {{{BLACK.r, BLACK.g, BLACK.b, 255}}};

grid::grid() {}

void grid::occupy_pos(std::vector<iVector2> posList, Color color)
{
    for (iVector2 pos : posList)
    {
        items[pos.m_x][pos.m_y].r = color.r;
        items[pos.m_x][pos.m_y].g = color.g;
        items[pos.m_x][pos.m_y].b = color.b;
        items[pos.m_x][pos.m_y].a = 255;
    }
}

bool grid::is_occupied(std::vector<iVector2> posList)
{
    for (iVector2 pos : posList)
    {
        if (items[pos.m_x][pos.m_y].r != 0
        ||  items[pos.m_x][pos.m_y].g != 0
        ||  items[pos.m_x][pos.m_y].b != 0)
        {
            return true;
        }
    }
    return false;
}

void grid::draw()
{
    for (int y = 0; y < GRID_HEIGHT; y++)
    {
        for (int x = 0; x < GRID_WIDTH; x++)
        {
            if (items[x][y].r != 0
            ||  items[x][y].g != 0
            ||  items[x][y].b != 0)
            {
                DrawRectangle(x * BLOCK_SIZE + (HUD_WIDTH / 2),
                              GetScreenHeight() - (y * BLOCK_SIZE + HUD_HEIGHT / 2),
                              BLOCK_SIZE, BLOCK_SIZE, items[x][y]);
            }
        }
    }
}

void grid::reset()
{
    for (int y = 0; y < GRID_HEIGHT; y++)
    {
        for (int x = 0; x < GRID_WIDTH; x++)
        {
            items[x][y] = {0, 0, 0, 255};
        }
    }
}
