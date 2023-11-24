#include "raylib.h"
#include "tetromino.h"

int main(int argc, char* argv[])
{
    InitWindow(480, 880, "example");
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
            x.draw();
            r.draw();
            t.draw();
            k.draw();
            s.draw();
            i.draw();
            ClearBackground(BLACK);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
