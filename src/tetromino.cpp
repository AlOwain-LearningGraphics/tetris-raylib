#include "tetromino.h"
#include <iostream>
#include <raylib.h>

// Initializeing the static grid to be false.
// This is used to calculate collision.
bool tetromino::m_HasGameEnded = false;
bool tetromino::grid[10][20] = {{false}};
float tetromino::time_since_last_move = 0;

enum tetromino::type GetRandomType()
{
    return static_cast<enum tetromino::type>(GetRandomValue(0, 5));
}

Color GetRandomColor()
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

static int count = 0;
tetromino::tetromino()
{
    color = GetRandomColor();
    tetromino_type = GetRandomType();
    CreateTetrominoMap();

    // FIXME:        Manage a proper spawning mechanism. This spawns
    //          a Tetromino randomly till it finds an empty spot.
    //          This is only here to test the collision system
    while (!ChangePos({GetRandomValue(1, 10), GetRandomValue(1, 20)}));
    
    // TODO: Check if the game ended
}

void tetromino::logic()
{
}

void tetromino::draw(iVector2 map_dimensions)
{
    iVector2 currPos = pos;
    for (int i = 0; i < TETROMINO_PIECES; i++)
    {
        DrawRectangle(currPos.m_x * 40 + map_dimensions.m_x, ((GetScreenHeight() - map_dimensions.m_y) - currPos.m_y * 40), 40, 40, color);
        currPos += TraverseMap(i);
    }
}

bool tetromino::HasGameEnded()
{
    return m_HasGameEnded;
}
void tetromino::CreateTetrominoMap()
{
    switch (tetromino_type)
    {
        case STRAIGHT:
            tetromino_map[0] = DOWN;
            tetromino_map[1] = DOWN;
            tetromino_map[2] = DOWN;
            return;
        case SQUARE:
            tetromino_map[0] = RIGHT;
            tetromino_map[1] = DOWN;
            tetromino_map[2] = LEFT;
            return;
        case L_TYPE:
            tetromino_map[0] = DOWN;
            tetromino_map[1] = DOWN;
            tetromino_map[2] = RIGHT;
            return;
        case J_TYPE:
            tetromino_map[0] = DOWN;
            tetromino_map[1] = DOWN;
            tetromino_map[2] = LEFT;
            return;
        case SKEW:
            tetromino_map[0] = DOWN;
            tetromino_map[1] = RIGHT;
            tetromino_map[2] = DOWN;
            return;
        case REVERSE_SKEW:
            tetromino_map[0] = DOWN;
            tetromino_map[1] = LEFT;
            tetromino_map[2] = DOWN;
            return;
        default:
            assert(0 && "Tetromino can not have a type other than those specified");
    }
}

iVector2 tetromino::TraverseMap(int index)
{
    switch (tetromino_map[index]) {
        case UP:
            return {0, 1};
        case RIGHT:
            return {1, 0};
        case DOWN:
            return {0, -1};
        case LEFT:
            return {-1, 0};
    }
    return {0, 0};
}

bool OutOfBounds(iVector2 pos)
{
    if (pos.m_x > 9 || pos.m_x < 0 || pos.m_y <= 0)
    {
        return true;
    }
    return false;
}

bool tetromino::ChangePos(iVector2 newPos)
{
    iVector2 traversalPos = newPos;
    for (int i = 0; i < TETROMINO_PIECES; i++)
    {
        if (grid[traversalPos.m_x][traversalPos.m_y] || OutOfBounds(traversalPos))
        {
            return false;
        }
        traversalPos += TraverseMap(i);
    }

    traversalPos = newPos;
    for (int i = 0; i < TETROMINO_PIECES; i++)
    {
        grid[traversalPos.m_x][traversalPos.m_y] = true;
        traversalPos += TraverseMap(i);
    }

    pos = newPos;
    return true;
}
