#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

int validarLetras(char auxiliar[])
{
    int retorno = 0;
    int i;
    for(i=0; i < strlen(auxiliar); i++)
    {
        if((auxiliar[i] < 65 && auxiliar[i] != 32) || (auxiliar[i]> 90 && auxiliar[i]< 97) || (auxiliar[i]> 122))
        {
            retorno = -1;
            break;
        }
    }
    return retorno;
}

int validarFloat(char auxiliar[])
{
    int retorno = 0;
    int i;

    for(i=0; i<strlen(auxiliar); i++)
    {
        if((auxiliar[i]<48 && auxiliar[i] != 46) || (auxiliar[i]>57))
        {
            retorno=-1;
            break;
        }
    }
    return retorno;
}

int cargarDatosDeProducto(EProducto array[], int indice, int size)
{
    int retorno;
    if (size < 200)
    {
        //Paso 1. Cargar el auxiliar Nombre
        int retornoNombre;
        printf("\nIngrese nombre: \n");
        char auxNombre[50];
        fflush(stdin);
        fgets(auxNombre,sizeof(auxNombre),stdin);
        auxNombre[strlen(auxNombre)-1] = 0; //Le quitamos el ultimo enter que se guarda en el array
        //Paso 2. Validar que haya pasado letras
        retornoNombre = validarLetras(auxNombre);

        //Descripcion
        int retornoDescripcion;
        printf("\nIngrese descripcion: \n");
        char auxDescripcion[200];
        fflush(stdin);
        fgets(auxDescripcion,sizeof(auxDescripcion),stdin);
        auxDescripcion[strlen(auxDescripcion)-1] = 0;
        retornoDescripcion = validarLetras(auxDescripcion);

        //Precio
        int retornoPrecio;
        printf("\nIngrese precio: \n");
        char auxPrecio[10];
        fflush(stdin);
        fgets(auxPrecio, sizeof(auxPrecio), stdin);
        auxPrecio[strlen(auxPrecio)-1] = 0;
        retornoPrecio = validarFloat(auxPrecio);

        //Paso 3. Asignacion de auxiliares en los datos validados
        if  (retornoNombre == 0 && retornoDescripcion == 0 && retornoPrecio == 0)
        {
            retorno = 0;
        }
        else
        {
            if (retornoNombre != 0)
                printf("Error de carga en nombre");
            if (retornoDescripcion != 0)
                printf("Error de carga en descripcion");
            if (retornoPrecio != 0)
                printf("Error de carga en precio");
        }
        if (retorno == 0)
        {
            strcpy(array[indice].nombre, auxNombre);
            strcpy(array[indice].descripcion, auxDescripcion);
            array[indice].precio = atof(auxPrecio);
            array[indice].flagVacio = 0;
        }
    }
    return retorno;
}

void imprimirDatosDeProducto(EProducto array[], int indice)
{
    printf("\nProducto: %s", array[indice].nombre);
    printf("\nDescripcion: %s", array[indice].descripcion);
    printf("\nPrecio: %.2f", array[indice].precio);
}

/*int buscarProductoSinCargar(EProducto array[], int size)
{
    int i;
    int retorno = -1;
    for(i = 0; i < size, i++)
    {
        if (array[i].flagVacio == 1)
            retorno = i;

        return retorno;
    }

}*/
