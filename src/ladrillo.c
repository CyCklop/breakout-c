#include <raylib.h>
#include <stdbool.h>

#include "../includes/ladrillo.h"

bool estado_ladrillo(Ladrillo *ladrillo)
{
    if (ladrillo->estado == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void colision_pelota_ladrillo(Ladrillo *ladrillo, Pelota *pelota)
{
    Rectangle rect_ladrillo = {
        ladrillo->posicion.x,
        ladrillo->posicion.y,
        ladrillo->tamaño.x,
        ladrillo->tamaño.y
    };

    if (CheckCollisionCircleRec(pelota->posicion, pelota->radio, rect_ladrillo))
    {
        ladrillo->estado = false;

        bool impacto_vertical = (pelota->posicion.x > ladrillo->posicion.x) && (pelota->posicion.x < (ladrillo->posicion.x + ladrillo->tamaño.x));
    
        if (impacto_vertical)
        {
            pelota->velocidad.y *= -1;
        }
        else
        {
            pelota->velocidad.x *= -1;
        }
    }
}
