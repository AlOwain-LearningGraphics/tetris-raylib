#include "tetromino.h"
#include <iostream>
#include <raylib.h>

enum tetromino::type tetromino::GetRandomType()
{
    return static_cast<enum type>(GetRandomValue(0, 5));
}

Color tetromino::GetRandomColor()
{
    switch (GetRandomValue(0, 7))
    {
        case 0:
            return PURPLE;
        case 1:
            return GREEN;
        case 2:
            return BLUE;
        case 3:
            return DARKBLUE;
        case 4:
            return ORANGE;
        case 5:
            return YELLOW;
        default:
            return RED;
    }
}

tetromino::tetromino()
{
    // TODO: Make the tetromino spawn from the top
    pos = {(short) (GetRandomValue(1, 10)), (short) (GetRandomValue(1, 20))};
    color = GetRandomColor(); 
    tetromino_type = GetRandomType();
    CreateTetrominoMap();
}

void tetromino::logic()
{
}

void tetromino::draw()
{
    sVector2 currPos = pos;
    for (int i = 0; i < TETROMINO_PIECES; i++)
    {
        DrawRectangle((int)(currPos.m_x * 40), (GetScreenHeight() - (int)(currPos.m_y * 40)), 40, 40, color);
        switch (tetromino_map[i]) {
            case UP:
                currPos.m_y += 1;
            break;
            case RIGHT:
                currPos.m_x += 1;
            break;
            case DOWN:
                currPos.m_y -= 1;
            break;
            case LEFT:
                currPos.m_x -= 1;
            break;
        }
    }
}

void tetromino::CreateTetrominoMap()
{
    switch (tetromino_type)
    {
        case STRAIGHT:
            tetromino_map[0] = DOWN;
            tetromino_map[1] = DOWN;
            tetromino_map[2] = DOWN;
        break;
        case SQUARE:
            tetromino_map[0] = RIGHT;
            tetromino_map[1] = DOWN;
            tetromino_map[2] = LEFT;
        break;
        case L_TYPE:
            tetromino_map[0] = DOWN;
            tetromino_map[1] = DOWN;
            tetromino_map[2] = RIGHT;
        break;
        case J_TYPE:
            tetromino_map[0] = DOWN;
            tetromino_map[1] = DOWN;
            tetromino_map[2] = LEFT;
        break;
        case SKEW:
            tetromino_map[0] = DOWN;
            tetromino_map[1] = RIGHT;
            tetromino_map[2] = DOWN;
        break;
        case REVERSE_SKEW:
            tetromino_map[0] = DOWN;
            tetromino_map[1] = LEFT;
            tetromino_map[2] = DOWN;
        break;
    }
}
