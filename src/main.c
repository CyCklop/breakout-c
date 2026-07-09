#include <raylib.h>
#include <stdbool.h>

#include "../includes/ladrillo.h"
#include "../includes/jugador.h"
#include "../includes/pelota.h"

int main(void)
{
    const int ancho_ventana = 800;
    const int alto_ventana = 600;

    int filas = 8;
    int columnas = 10;

    Ladrillo tablero[filas][columnas];
    Jugador jugador;
    Pelota pelota;

    bool menu_juego = true;

    InitWindow(ancho_ventana, alto_ventana, "breakout");

    SetTargetFPS(60);

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            tablero[i][j].estado = true;

            switch (i)
            {
                case 0:
                case 1:
                    tablero[i][j].color = RED;
                    break;
                case 2:
                case 3:
                    tablero[i][j].color = ORANGE;
                    break;
                case 4:
                case 5:
                    tablero[i][j].color = GREEN;
                    break;
                case 6:
                case 7:
                    tablero[i][j].color = YELLOW;
                    break;
            }

            tablero[i][j].posicion.x = 125 + (j * 55);
            tablero[i][j].posicion.y = 50 + (i * 25);

            tablero[i][j].tamaño = (Vector2){ 50, 20};
        }
    }

    jugador.color = WHITE;

    jugador.velocidad = 5.5f;
    jugador.posicion.x = 375;
    jugador.posicion.y = 520;

    jugador.tamaño = (Vector2){70, 15};
    
    pelota.color = WHITE;

    pelota.radio = 10.0f;
    pelota.posicion.x = ancho_ventana / 2.0f;
    pelota.posicion.y = alto_ventana / 2.0f;

    pelota.velocidad.x = 4.0f;
    pelota.velocidad.y = -4.0f;

    pelota.activa = true;

    while (!WindowShouldClose())
    {

        if (menu_juego)
        {
            if (IsKeyPressed(KEY_SPACE))
            {
                menu_juego = false;
            }
        }
        else
        {
            mover_jugador(&jugador);

            if (jugador.posicion.x <= 0)
            {
                jugador.posicion.x = 0;
            }

            if (jugador.posicion.x >= (ancho_ventana - jugador.tamaño.x))
            {                                                        
                jugador.posicion.x = ancho_ventana - jugador.tamaño.x;
            }

            calcular_rebote(&pelota, ancho_ventana, alto_ventana);
        }

        BeginDrawing();
            ClearBackground(BLACK);

            if (menu_juego)
            {
                DrawText("BREAKOUT-C", 250, 86, 48, WHITE);
                DrawText("Presiona ESPACIO para iniciar", 200, 286, 28, WHITE);
            }
            else
            {
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
                DrawRectangleV(jugador.posicion, jugador.tamaño, jugador.color);
                if (pelota.activa == true)
                {
                    DrawCircleV(pelota.posicion, pelota.radio, pelota.color);
                }
            }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
