#ifndef JUGADOR_H
#define JUGADOR_H

#include <raylib.h>

#include "pelota.h"

typedef struct
{
    Vector2 tamaño;
    Vector2 posicion;
    float velocidad;
    Color color;
} Jugador;

void mover_jugador(Jugador *jugador);
void colision_pelota(Jugador *jugador, Pelota *pelota);

#endif
