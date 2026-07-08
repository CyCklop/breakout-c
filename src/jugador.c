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
