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
    m_pos = {-10, -10};
    m_tetromino_type = GetRandomType();
    m_color = GetRandomColor();
    m_rotation = false;

    // FIXME:        Manage a proper spawning mechanism. This spawns
    //          a Tetromino randomly.
    change_pos({GetRandomValue(1, 10), 20}, m_rotation);

    // TODO: Check if the game ended
}

bool tetromino::logic(input_type next_move)
{
    switch (next_move) {
        case DOWN:
            return change_pos({m_pos.m_x, m_pos.m_y - 1}, m_rotation);
        case LEFT:
            return change_pos({m_pos.m_x - 1, m_pos.m_y}, m_rotation);
        case RIGHT:
            return change_pos({m_pos.m_x + 1, m_pos.m_y}, m_rotation);
        case ROTATE:
            return change_pos({m_pos.m_x, m_pos.m_y}, !m_rotation);
        default:
            return true;
    }
}

tetromino::input_type tetromino::input()
{
    if (IsKeyDown(KEY_LEFT)) { return LEFT; }
    if (IsKeyDown(KEY_RIGHT)) { return RIGHT; }
    if (IsKeyDown(KEY_DOWN)) { return DOWN; }
    if (IsKeyDown(KEY_UP)) { return ROTATE; }

    return NO_MOVE;
}

void tetromino::draw()
{
    std::vector<iVector2> tPos = get_pos();
    for (int i = 0; i < TETROMINO_PIECES; i++)
    {
        // Draw relative to the HUD size
        DrawRectangle(tPos[i].m_x * BLOCK_SIZE + HUD_WIDTH / 2,
                      GetScreenHeight() - (tPos[i].m_y * BLOCK_SIZE + HUD_HEIGHT / 2),
                      BLOCK_SIZE, BLOCK_SIZE, get_color());
    }
}

std::vector<iVector2> tetromino::get_pos() { return TranslatePos(m_pos, m_tetromino_type, m_rotation); }
Color tetromino::get_color() { return m_color; }

std::vector<iVector2> TranslatePos(iVector2 original_position, tetromino::tetromino_type type, bool rotation)
{
    std::vector<iVector2> grid_position;
    switch (type)
    {
        case tetromino::STRAIGHT:
            grid_position = {{0 ,  0},
                             {0 , -1},
                             {0 , -2},
                             {0 , -3}};
        break;
        case tetromino::SQUARE:
            grid_position = {{0 ,  0},
                             {1 ,  0},
                             {1 , -1},
                             {0 , -1}};
        break;
        case tetromino::L_TYPE:
            grid_position = {{0 ,  0},
                             {0 , -1},
                             {0 , -2},
                             {1 , -2}};
        break;
        case tetromino::J_TYPE:
            grid_position = {{0 ,  0},
                             {0 , -1},
                             {0 , -2},
                             {-1, -2}};
        break;
        case tetromino::SKEW:
            grid_position = {{0 ,  0},
                             {0 , -1},
                             {1 , -1},
                             {1 , -2}};
        break;
        case tetromino::REVERSE_SKEW:
            grid_position = {{0 ,  0},
                             {0 , -1},
                             {-1, -1},
                             {-1, -2}};
        break;
        default:
            assert(0);
        break;
    }
    if (rotation)
    {
        for (int i = 0; i < 4; i++)
        {
            grid_position[i] = {grid_position[i].m_y, grid_position[i].m_x};
        }
    }

    for (int i = 0; i < 4; i++)
    {
        grid_position[i] = {grid_position[i].m_x + original_position.m_x, grid_position[i].m_y + original_position.m_y};
    }
    return grid_position;
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

bool tetromino::change_pos(iVector2 new_pos, bool new_rotation)
{
    grid game_grid;
    std::vector<iVector2> newTetrominoPos = TranslatePos(new_pos, m_tetromino_type, new_rotation);

    if (OutOfBounds(newTetrominoPos)) { return false; }
    if (game_grid.is_occupied(newTetrominoPos)) { return false; }

    m_pos = new_pos;
    m_rotation = new_rotation;
    return true;
}
