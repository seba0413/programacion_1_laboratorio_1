#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main()
{
    EProducto productos[200];
    int i;

    for(i = 0; i < 200; i++)
    {
        productos[i].flagVacio = 1;
    }

    if  ((cargarDatosDeProducto(productos,0,199))==0)
    {
        imprimirDatosDeProducto(productos,0);
    }
    return 0;
}

