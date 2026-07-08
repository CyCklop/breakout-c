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
