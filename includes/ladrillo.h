#ifndef LADRILLO_H
#define LADRILLO_H

#include <raylib.h>
#include <stdbool.h>

typedef struct
{
    Vector2 tamaño;
    Vector2 posicion;
    bool estado;
    Color color;
} Ladrillo;

bool estado_ladrillo(Ladrillo *ladrillo);

#endif
