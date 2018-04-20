#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int cargarDatosDeProducto(EProducto array[], int indice, int size)
{
    if (size < 200)
    {
        int retorno = 0;
        printf("\nIngrese nombre: \n");
        char auxNombre[50];

        //Paso 1. Cargar el auxiliar
        fflush(stdin);
        fgets(auxNombre,sizeof(auxNombre),stdin);
        array[strlen(auxNombre)-1] = 0; //Le quitamos el ultimo enter que se guarda en el array


        //Paso 2. Validar que haya pasado letras
        int i;
        for(i=0, i<strlen(auxNombre); i++)
        {
            if((auxNombre[i] < 65) || (auxNombre[i] > 90 && auxNombre[i] < 97) || (auxNombre[i] > 122) ||
               (auxNombre[i] != 32)
            {
                retorno = -1;
                break;
            }
        }
        //Paso 3. Asignacion del auxiliar en el dato una vez validado
        //Conviene hacerlo una vez validado todos los datos
        if  (retorno == 0)
        {
            strcpy(array[indice].nombre, auxNombre);
        }
    }
    return retorno;
}

void imprimirDatosDeProducto(EProducto array[], int indice)
{
    printf("\nProducto: %s \nDescripcion: %s \nPrecio: %.2f \nflagVacio %d ", array[indice].nombre,
            array[indice].descripcion, array[indice].precio, array[indice].flagVacio);

}

int buscarProductoSinCargar(EProducto array[], int size)
{
    int i;
    int retorno = -1;
    for(i = 0; i < size, i++)
    {
        if (array[i].flagVacio == 1)
            retorno = i;

        return retorno;
    }

}
