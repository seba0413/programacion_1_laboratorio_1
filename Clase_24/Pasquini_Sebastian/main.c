#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "deposito.h"
#include "ArrayList.h"
#include "Parser.h"
#include "utn.h"
#include "informe.h"
#include "funciones.h"

int main()
{
    ArrayList* deposito1 = al_newArrayList();
    ArrayList* deposito2 = al_newArrayList();
    int numeroDeposito;
    int opcion;

    do
    {
        getValidInt("\n1.Cargar productos\n2.Listar productos de deposito\n3.Mover productos a deposito\n4.Descontar productos de deposito\n5.Agregar productos a deposito\n6.Salir\n", "\nOpcion invalida\n", &opcion,1,6,2);

        switch (opcion)
        {
            case 1:
                if (!parser_cargarDepositos(deposito1, "dep0.csv"))
                    printf("\nLista deposito 1 cargada\n");
                else
                    printf("\nNo se pudo cargar la lista deposito 1\n");

                if(!parser_cargarDepositos(deposito2, "dep1.csv"))
                    printf("\nLista deposito 2 cargada\n");
                else
                    printf("\nNo se pudo cargar la lista deposito 2\n");
            break;

            case 2:
                getValidInt("\nIngrese numero de deposito\n", "\nOpcion invalida\n", &numeroDeposito,1,2,2);
                printf("%d", numeroDeposito);
                if(numeroDeposito == 1)
                {
                    //printf("hola");
                    informe_imprimirLista(deposito1);
                }

                else
                    informe_imprimirLista(deposito2);
            break;

            case 3:
                funciones_moverProductos(deposito1, deposito2);
                informe_escribirArchivo(deposito1,"dep0.csv");
                informe_escribirArchivo(deposito2,"dep1.csv");
            break;

            case 4:
                funciones_descontarProductosDeDeposito(deposito1, deposito2);
                informe_escribirArchivo(deposito1,"dep0.csv");
                informe_escribirArchivo(deposito2,"dep1.csv");
            break;

            case 5:
                funciones_agregarProductosDeDeposito(deposito1, deposito2);
                informe_escribirArchivo(deposito1,"dep0.csv");
                informe_escribirArchivo(deposito2,"dep1.csv");

            break;
        }

    }while(opcion != 6);

    return 0;
}
