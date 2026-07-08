#include <raylib.h>
#include <stdbool.h>

#include "../imports/ladrillo.h"

int main(void)
{
    const int anchoVentana = 600;
    const int altoVentana = 800;

    int filas = 14;
    int columnas = 8;

    Ladrillo tablero[filas][columnas];

    InitWindow(anchoVentana, altoVentana, "breakout");

    SetTargetFPS(60);


    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            tablero[i][j].estado = true;
            tablero[i][j].color = GREEN;

            tablero[i][j].posicion.x = 79 + (j * 55);
            tablero[i][j].posicion.y = 30 + (i * 25);

            tablero[i][j].tamaño = (Vector2){ 50, 20};
        }
    }

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(BLACK);
            for (int i = 0; i < filas; i++)
            {
                for (int j = 0; j < columnas; j++)
                {
                    if (estado_ladrillo(&tablero[i][j]) == true)
                    {
                        DrawRectangleV(tablero[i][j].posicion, tablero[i][j].tamaño, tablero[i][j].color);
                    }
                }
            }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
