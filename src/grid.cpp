#include "grid.h"

Color grid::items[GRID_WIDTH][GRID_HEIGHT] = {{{0, 0, 0, 255}}};
short grid::drawing_order[GRID_HEIGHT] = {0};

grid::grid() {}

void grid::occupy_pos(std::vector<iVector2> posList, Color color)
{
    assert(posList.size() <= 4);
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
                              GetScreenHeight() - (y * BLOCK_SIZE + HUD_HEIGHT / 2),
                              BLOCK_SIZE, BLOCK_SIZE, items[x][drawing_order[y]]);
}

bool grid::logic(std::vector<iVector2> posList, Color color)
{
    occupy_pos(posList, color);
    
    // check_completed_rows();
    return check_for_endgame();
}

bool grid::check_for_endgame()
{
    for (int x = 0; x < GRID_WIDTH; x++)
        if (items[x][drawing_order[GRID_HEIGHT - 1]].r != 0
        ||  items[x][drawing_order[GRID_HEIGHT - 1]].g != 0
        ||  items[x][drawing_order[GRID_HEIGHT - 1]].b != 0)
            return true;
    return false;
}

void grid::check_completed_rows()
{
    printGrid();
    for (int y = 0; y < GRID_HEIGHT + 1; y++)
    {
        int x = 0;
        while (items[x][drawing_order[y]].r != 0
           ||  items[x][drawing_order[y]].g != 0
           ||  items[x][drawing_order[y]].b != 0)
        {
            if (x == GRID_WIDTH)
            {
                // FIXME: Make it properly replace the rows.
                reset_row(y);
                drawing_order[GRID_HEIGHT] = y;
                for (int i = y; i < GRID_HEIGHT; i++)
                    drawing_order[i]--;
                break;
            }
            x++;
        }
    }
}

void grid::reset()
{
    for (short y = 0; y < GRID_HEIGHT + 1; y++)
    {
        reset_row(y);
        drawing_order[y] = y;
    }
}

void grid::reset_row(short row)
{
    for (int x = 0; x < GRID_WIDTH; x++)
        items[x][row] = {0, 0, 0, 255};
}

#include <iostream>

void grid::printGrid()
{
    std::cout << " y   dy  ";
    for (int x = 0; x < GRID_WIDTH; x++)
         std::cout << x << " ";
    std::cout << std::endl;

    for (int y = GRID_HEIGHT; y > 0; y--)
    {
        if (y <= 9)
            std::cout << "0" << y;
        else
            std::cout << y;
        if (drawing_order[y] <= 9)
            std::cout << " | 0" << drawing_order[y] << "  ";
        else
            std::cout << " | " << drawing_order[y] << "  ";
        for (int x = 0; x < GRID_WIDTH; x++)
        {
            if (items[x][drawing_order[y]].r != 0
            ||  items[x][drawing_order[y]].g != 0
            ||  items[x][drawing_order[y]].b != 0)
                std::cout << "1 ";
            else
                std::cout << "0 ";
        }
         std::cout << std::endl;
    }
     std::cout << "\n_________________________________" << std::endl;
}
