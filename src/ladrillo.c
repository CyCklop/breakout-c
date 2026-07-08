#include <raylib.h>
#include <stdbool.h>

#include "../imports/ladrillo.h"

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
