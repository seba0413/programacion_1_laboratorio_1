#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "utn.h"
#include "parser.h"
#include "reparto.h"

int parser_cargarLista(ArrayList* listaReparto)
{
    int retorno = -1;
    char id[16];
    char producto[128];
    char direccion[128];
    char localidad[128];
    char recibe[128];
    char fileName[128];
    Reparto* auxiliar;

    if(listaReparto != NULL)
    {
        fflush(stdin);
        printf("\nIngrese nombre del archivo:\n");
        gets(fileName);

        FILE* fp = fopen(fileName, "r");

        if (fp != NULL)
        {
            if(fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, producto, direccion, localidad, recibe)==5)
            {
                while(!feof(fp))
                {
                    if(fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, producto, direccion, localidad, recibe)==5)
                    {
                        auxiliar = reparto_newConParametros(atoi(id), producto, direccion, localidad, recibe);
                        al_add(listaReparto, auxiliar);
                    }
                }
            }
            retorno = 0;
            printf("\nLa lista fue cargada correctamente\n");
        }
        else
            printf("\nLa lista no pudo cargarse\n");

        fclose(fp);
    }
    return retorno;
}
