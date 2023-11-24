#include "raylib.h"
#include "tetromino.h"

// TODO: define these and manage the Tetrominoes elsewhere 
#define BLOCK_SIZE 40
#define HUD_WIDTH 80
#define HUD_HEIGHT 80

int main(int argc, char* argv[])
{
    InitWindow(BLOCK_SIZE * MAP_WIDTH + HUD_WIDTH, BLOCK_SIZE * MAP_HEIGHT + HUD_HEIGHT, "example");
    SetTargetFPS(60);
    
    tetromino x;
    tetromino r;
    tetromino t;
    tetromino k;
    tetromino s;
    tetromino i;

    while(!WindowShouldClose())
    {
        x.logic();
        r.logic();
        t.logic();
        k.logic();
        s.logic();
        i.logic();
        BeginDrawing();
            x.draw({HUD_WIDTH / 2, HUD_HEIGHT / 2});
            r.draw({HUD_WIDTH / 2, HUD_HEIGHT / 2});
            t.draw({HUD_WIDTH / 2, HUD_HEIGHT / 2});
            k.draw({HUD_WIDTH / 2, HUD_HEIGHT / 2});
            s.draw({HUD_WIDTH / 2, HUD_HEIGHT / 2});
            i.draw({HUD_WIDTH / 2, HUD_HEIGHT / 2});
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
