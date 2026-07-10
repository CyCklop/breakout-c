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
    int vidas;
} Jugador;

void mover_jugador(Jugador *jugador);
void colision_pelota_jugador(Jugador *jugador, Pelota *pelota);

#endif
