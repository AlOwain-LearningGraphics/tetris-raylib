#include "raylib.h"

int main(int argc, char* argv[])
{
    InitWindow(480, 880, "example");
    SetTargetFPS(60);
    
    while(!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(BLACK);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
