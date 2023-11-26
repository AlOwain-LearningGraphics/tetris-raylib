#include "raylib.h"
#include "gameController.h"


int main(int argc, char* argv[])
{
    InitWindow(BLOCK_SIZE * GRID_WIDTH + HUD_WIDTH, BLOCK_SIZE * GRID_HEIGHT + HUD_HEIGHT, "Tetris - implemented using RayLib");
    SetTargetFPS(60);
    
    // There is no better name for a variable.
    gameController x;
    while(!WindowShouldClose())
    {
        x.logic();
        BeginDrawing();
            x.draw();
        EndDrawing();
    }
    
    // FIXME:       Sementation Fault occurs when exiting the loop, seemingly related to the
    //          mismanaged memory. Oh well, it's the Operating System's responsibility now.
    CloseWindow();
    return 0;
}
