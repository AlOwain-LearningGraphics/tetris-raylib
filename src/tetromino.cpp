#include "tetromino.h"

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

tetromino::tetromino() {}

void tetromino::reset()
{
    m_tetromino_type = GetRandomType();
    color = GetRandomColor();

    // FIXME:        Manage a proper spawning mechanism. This spawns
    //          a Tetromino randomly.
    ChangePos({GetRandomValue(1, 10), 20});

    // TODO: Check if the game ended
}

bool tetromino::logic()
{
    return ChangePos({m_pos.m_x, m_pos.m_y - 1});
}

void tetromino::draw()
{
    std::vector<iVector2> tPos = get_pos();
    for (int i = 0; i < TETROMINO_PIECES; i++)
    {
        // Draw relative to the HUD size
        DrawRectangle(tPos[i].m_x * BLOCK_SIZE + HUD_WIDTH / 2,
                      GetScreenHeight() - (tPos[i].m_y * BLOCK_SIZE + HUD_HEIGHT / 2),
                      BLOCK_SIZE, BLOCK_SIZE, color);
    }
}

std::vector<iVector2> tetromino::get_pos() { return TranslatePos(m_pos, m_tetromino_type); }
Color tetromino::get_color() { return color; }

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

bool OutOfBounds(std::vector<iVector2> tGrid)
{
    for (int i = 0; i < TETROMINO_PIECES; i++)
    {
        if (tGrid[i].m_x > 9 || tGrid[i].m_x < 0 || tGrid[i].m_y <= 0)
        {
            return true;
        }
    }
    return false;
}

bool tetromino::ChangePos(iVector2 newPos)
{
    grid game_grid;
    std::vector<iVector2> newTetrominoPos = TranslatePos(newPos, m_tetromino_type);

    if (OutOfBounds(newTetrominoPos)) { return false; }
    if (game_grid.is_occupied(newTetrominoPos)) { return false; }

    m_pos = newPos;
    return true;
}
