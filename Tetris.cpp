#include "raylib.h"

int main(int argc, char* argv[])
{
    InitWindow(800, 600, "example");
    SetTargetFPS(60);
    
    while(!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
