#include "tetromino.h"
#include "raylib.h"

#define BLOCK_SIZE 40
#define HUD_WIDTH 80
#define HUD_HEIGHT 80

class gameController {
public:
    gameController();

    void draw();
    void logic();
private:
    float time_since_last_move;

    // TODO: Make the amount of tetrominoes equal [(MAP_WIDTH * MAP_HEIGHT) / TETROMINO_PIECES];
    tetromino pieces[2]; 
    int CurrentPieceID;

    void reset();
};
