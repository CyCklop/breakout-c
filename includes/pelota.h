#ifndef PELOTA_H
#define PELOTA_H

#include <raylib.h>
#include <stdbool.h>

typedef struct
{
    Vector2 posicion;
    Vector2 velocidad;
    float radio;
    bool activa;
    Color color;
} Pelota;

void calcular_rebote(Pelota *pelota, int ancho_ventana, int alto_ventana);

#endif
