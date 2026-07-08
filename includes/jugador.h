#ifndef JUGADOR_H
#define JUGADOR_H

#include <raylib.h>

typedef struct
{
    Vector2 tamaño;
    Vector2 posicion;
    float velocidad;
    Color color;
} Jugador;

void mover_jugador(Jugador *jugador);

#endif
