#ifndef LADRILLO_H
#define LADRILLO_H

#include <raylib.h>
#include <stdbool.h>

#include "pelota.h"

typedef struct
{
    Vector2 tamaño;
    Vector2 posicion;
    bool estado;
    Color color;
} Ladrillo;

bool estado_ladrillo(Ladrillo *ladrillo);
void colision_pelota_ladrillo(Ladrillo *ladrillo, Pelota *pelota);

#endif
