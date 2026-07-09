#include <raylib.h> 

#include "../includes/pelota.h"

void calcular_rebote(Pelota *pelota, int ancho_ventana, int alto_ventana)
{
    if (pelota->activa == true)
    {
        pelota->posicion.x += pelota->velocidad.x;
        pelota->posicion.y += pelota->velocidad.y;

        if ((pelota->posicion.x - pelota->radio) <= 0)
        {
            pelota->posicion.x = pelota->radio;
            pelota->velocidad.x *= -1;
        }
        else if ((pelota->posicion.x + pelota->radio) >= ancho_ventana)
        {
            pelota->posicion.x = ancho_ventana - pelota->radio;
            pelota->velocidad.x *= -1;
        }

        if ((pelota->posicion.y - pelota->radio) <= 0)
        {
            pelota->posicion.y = pelota->radio;
            pelota->velocidad.y *= -1;
        }

        if ((pelota->posicion.y + pelota->radio) >= alto_ventana)
        {
            pelota->activa = false;
        }
    }
    else
    {
        pelota->velocidad.x = 0;
        pelota->velocidad.y = 0;
    }
}
