#include "tetromino.h"
#include <vector>

// Initializeing the static grid to be false.
bool tetromino::grid[10][20] = {{false}};

enum tetromino::tetromino_type GetRandomType()
{
    return static_cast<enum tetromino::tetromino_type>(GetRandomValue(0, 5));
}

Color GetRandomColor()
{
    switch (GetRandomValue(0, 6))
    {
        case 0: return PURPLE;
        case 1: return GREEN;
        case 2: return BLUE;
        case 3: return DARKBLUE;
        case 4: return ORANGE;
        case 5: return YELLOW;
        case 6: return RED;
        default:
            assert(0);
        break;
    }
}

tetromino::tetromino()
{
    // FIXME:       A rework of the construction, destruction, and reuse of Tetrominoes
    //          is really needed. A Tetromino now is drawn even if it didn't spawn,
    //          and when implemnting the destruction in the near future using the current
    //          method of simply removing the tetromino would cause issues with the collision
    //          and the removal of some parts of the Tetromino without others.
    m_tetromino_type = GetRandomType();
    color = BLACK;
}

void tetromino::reset()
{
    m_tetromino_type = GetRandomType();
    color = GetRandomColor();

    // FIXME:        Manage a proper spawning mechanism. This spawns
    //          a Tetromino randomly till it finds an empty spot.
    //          This is only here to test the collision system
    while (!ChangePos({GetRandomValue(1, 10), 20}));
    
    // TODO: Check if the game ended
}

bool tetromino::logic()
{
    bool x = ChangePos({m_pos.m_x, m_pos.m_y - 1});
    return x;
}

void tetromino::draw(iVector2 map_dimensions)
{
    std::vector<iVector2> tPos = TranslatePos(m_pos, m_tetromino_type);
    for (int i = 0; i < TETROMINO_PIECES; i++)
    {
        DrawRectangle(tPos[i].m_x * 40 + map_dimensions.m_x, ((GetScreenHeight() - map_dimensions.m_y) - tPos[i].m_y * 40), BLOCK_SIZE, BLOCK_SIZE, color);
    }
}

std::vector<iVector2> TranslatePos(iVector2 pos, tetromino::tetromino_type type)
{
    switch (type)
    {
        case tetromino::STRAIGHT:
            return {{pos.m_x   , pos.m_y   },
                    {pos.m_x   , pos.m_y -1},
                    {pos.m_x   , pos.m_y -2},
                    {pos.m_x   , pos.m_y -3}};
        case tetromino::SQUARE:
            return {{pos.m_x   , pos.m_y   },
                    {pos.m_x +1, pos.m_y   },
                    {pos.m_x +1, pos.m_y -1},
                    {pos.m_x   , pos.m_y -1}};
        case tetromino::L_TYPE:
            return {{pos.m_x   , pos.m_y   },
                    {pos.m_x   , pos.m_y -1},
                    {pos.m_x   , pos.m_y -2},
                    {pos.m_x +1, pos.m_y -2}};
        case tetromino::J_TYPE:
            return {{pos.m_x   , pos.m_y   },
                    {pos.m_x   , pos.m_y -1},
                    {pos.m_x   , pos.m_y -2},
                    {pos.m_x -1, pos.m_y -2}};
        case tetromino::SKEW:
            return {{pos.m_x   , pos.m_y   },
                    {pos.m_x   , pos.m_y -1},
                    {pos.m_x +1, pos.m_y -1},
                    {pos.m_x +1, pos.m_y -2}};
        case tetromino::REVERSE_SKEW:
            return {{pos.m_x   , pos.m_y   },
                    {pos.m_x   , pos.m_y -1},
                    {pos.m_x -1, pos.m_y -1},
                    {pos.m_x -1, pos.m_y -2}};
        default:
            assert(0 && "Tetromino type undefined.");
        break;
    }
}

bool OutOfBounds(iVector2 pos, tetromino::tetromino_type type)
{
    std::vector<iVector2> tGrid = TranslatePos(pos, type);
    for (int i = 0; i < TETROMINO_PIECES; i++)
    {
        if (tGrid[i].m_x > 10 || tGrid[i].m_x < 0 || tGrid[i].m_y <= 0)
        {
            return true;
        }
    }
    return false;
}

void tetromino::OccupyGridPos(iVector2 pos, bool occupy)
{
    std::vector<iVector2> tGrid = TranslatePos(pos, m_tetromino_type);
    for (int i = 0; i < TETROMINO_PIECES; i++)
    {
        grid[tGrid[i].m_x][tGrid[i].m_y] = occupy;
    }
}

bool tetromino::ChangePos(iVector2 newPos)
{
    if (OutOfBounds(newPos, m_tetromino_type)) { return false; }

    // Here we traverse the Tetromino to check every coordinate
    // it will occupy if we change its position to see whether
    // the place is already taken or not on the grid
    std::vector<iVector2> newGrid = TranslatePos(newPos, m_tetromino_type);
    for (int i = 0; i < TETROMINO_PIECES; i++)
    {
        if (grid[newGrid[i].m_x][newGrid[i].m_y])
        {
            std::vector<iVector2> oldGrid = TranslatePos(m_pos, m_tetromino_type);
            bool sharedPos = false;
            for (int j = 0; j < TETROMINO_PIECES; j++)
            {
                if (oldGrid[j] == newGrid[i])
                {
                    sharedPos = true;
                    break;
                }
            }
            if (!sharedPos)
            {
                return false;
            }
        }
    }
    
    OccupyGridPos(m_pos, false);
    OccupyGridPos(newPos, true);
    m_pos = newPos;
    return true;
}
