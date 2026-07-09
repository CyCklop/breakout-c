#include <raylib.h>

#include "../includes/jugador.h"

void mover_jugador(Jugador *jugador)
{
    if (IsKeyDown(KEY_A))
    {
        jugador->posicion.x -= jugador->velocidad;
    }

    if (IsKeyDown(KEY_D))
    {
        jugador->posicion.x += jugador->velocidad;
    }
}

void colision_pelota(Jugador *jugador, Pelota *pelota)
{
    Rectangle rect_jugador = {
        jugador->posicion.x,
        jugador->posicion.y,
        jugador->tamaño.x,
        jugador->tamaño.y
    };

    if (CheckCollisionCircleRec(pelota->posicion, pelota->radio, rect_jugador))
    {
        pelota->velocidad.y *= -1;
        pelota->posicion.y = jugador->posicion.y - pelota->radio;
    }
}
