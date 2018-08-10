#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "utn.h"
#include "parser.h"
#include "reparto.h"

int main()
{
    int opcion;
    ArrayList* listaReparto = al_newArrayList();
    ArrayList* listaNueva = al_newArrayList();
    char localidad[128];

    do
    {
        getValidInt("\n1.Cargar Archivo\n2.Imprimir entregas\n3.Imprimir localidades\n4.Generar archivo\n5.Salir\n","\nOpcion invalida\n", &opcion, 1,5,2);

        switch(opcion)
        {
            case 1:
                parser_cargarLista(listaReparto);
                break;
            case 2:
                al_map(listaReparto, imprimirEntrega);
                break;
            case 3:
                reparto_imprimirLocalidades(listaReparto);
                break;
            case 4:
                reparto_repartoPorLocalidad(listaReparto, listaNueva, localidad);
                reparto_generarArchivo(listaNueva, localidad);
                break;

        }

    }while (opcion != 5);

    return 0;
}
