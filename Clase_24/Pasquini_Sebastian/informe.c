#include "ArrayList.h"
#include "deposito.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int informe_imprimirLista(ArrayList* listaDeposito)
{
    int retorno = -1;
    int i;
    int producto;
    char descripcion [128];
    int cantidad;

    if (listaDeposito != NULL)
    {
        for(i = 0; i < al_len(listaDeposito); i++)
        {
            Deposito* auxDeposito = al_get(listaDeposito, i);
            deposito_getProducto(auxDeposito, &producto);
            deposito_getDescripcion(auxDeposito, descripcion);
            deposito_getCantidad(auxDeposito, &cantidad);
            printf("\n%d, %s, %d\n", producto, descripcion, cantidad);
        }
        retorno = 0;
    }
    return retorno;
}
int informe_escribirArchivo(ArrayList* deposito, char* fileName)
{
    int retorno = -1;
    int producto;
    char descripcion [128];
    int cantidad;
    int i;

    Deposito* auxDeposito;

    if(deposito != NULL && fileName != NULL)
    {
        FILE* pArchivo = fopen(fileName, "w");

        if(pArchivo != NULL)
        {
            for (i = 0; i < al_len(deposito); i++)
            {
                auxDeposito = al_get(deposito, i);
                deposito_getProducto(auxDeposito, &producto);
                deposito_getDescripcion(auxDeposito, descripcion);
                deposito_getCantidad(auxDeposito, &cantidad);
                fprintf(pArchivo, "%d, %s, %d\n",producto, descripcion, cantidad);
            }

            retorno = 0;
            printf("\nArchivo generado\n");
        }
        fclose(pArchivo);
    }

    return retorno;
}
