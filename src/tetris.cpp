#include "raylib.h"
#include "gameController.h"


int main(int argc, char* argv[])
{
    InitWindow(BLOCK_SIZE * MAP_WIDTH + HUD_WIDTH, BLOCK_SIZE * MAP_HEIGHT + HUD_HEIGHT, "example");
    SetTargetFPS(60);

    gameController x;
    while(!WindowShouldClose())
    {
        x.logic();
        BeginDrawing();
            x.draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
