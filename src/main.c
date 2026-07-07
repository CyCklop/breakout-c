#include <raylib.h>

int main(void)
{
    const int anchoVentana = 800;
    const int altoVentana = 600;

    InitWindow(anchoVentana, altoVentana, "breakout");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
