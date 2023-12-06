#include "grid.h"

Color grid::items[GRID_WIDTH][GRID_HEIGHT] = {{{0, 0, 0, 255}}};
short grid::drawing_order[GRID_HEIGHT + 1] = {1};

grid::grid() {}

void grid::occupy_pos(std::vector<iVector2> posList, Color color)
{
    for (iVector2 pos : posList)
    {
        items[pos.m_x][drawing_order[pos.m_y]].r = color.r;
        items[pos.m_x][drawing_order[pos.m_y]].g = color.g;
        items[pos.m_x][drawing_order[pos.m_y]].b = color.b;
        items[pos.m_x][drawing_order[pos.m_y]].a = 255;
    }
}

bool grid::is_occupied(std::vector<iVector2> posList)
{
    for (iVector2 pos : posList)
        if (items[pos.m_x][drawing_order[pos.m_y]].r != 0
        ||  items[pos.m_x][drawing_order[pos.m_y]].g != 0
        ||  items[pos.m_x][drawing_order[pos.m_y]].b != 0)
            return true;
    return false;
}

void grid::draw()
{
    for (int y = 0; y < GRID_HEIGHT; y++)
        for (int x = 0; x < GRID_WIDTH; x++)
            if (items[x][drawing_order[y]].r != 0
            ||  items[x][drawing_order[y]].g != 0
            ||  items[x][drawing_order[y]].b != 0)
                DrawRectangle(x * BLOCK_SIZE + (HUD_WIDTH / 2),
                              GetScreenHeight() - (drawing_order[y] * BLOCK_SIZE + HUD_HEIGHT / 2),
                              BLOCK_SIZE, BLOCK_SIZE, items[x][drawing_order[y]]);
}

bool grid::logic(std::vector<iVector2> posList, Color color)
{
    occupy_pos(posList, color);
    
    check_completed_rows();

    
    return check_for_endgame();
}

bool grid::check_for_endgame()
{
    for (int x = 0; x < GRID_WIDTH; x++)
        if (items[x][GRID_HEIGHT - 1].r != 0
        ||  items[x][GRID_HEIGHT - 1].g != 0
        ||  items[x][GRID_HEIGHT - 1].b != 0)
            return true;
    return false;
}

void grid::check_completed_rows()
{
    for (int y = 0; y < GRID_HEIGHT; y++)
    {
        int x = 0;
        while (items[x][drawing_order[y]].r != 0
           ||  items[x][drawing_order[y]].g != 0
           ||  items[x][drawing_order[y]].b != 0)
        {
            if (x == GRID_WIDTH)
            {
                // TODO: change drawing order here.
                break;
            }
            x++;
        }
    }
}

void grid::reset()
{
    for (int y = 0; y < GRID_HEIGHT; y++)
    {
        for (int x = 0; x < GRID_WIDTH; x++)
            items[x][y] = {0, 0, 0, 255};
        drawing_order[y] = y;
    }
}
