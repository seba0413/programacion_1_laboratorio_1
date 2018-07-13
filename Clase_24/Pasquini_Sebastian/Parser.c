#include "ArrayList.h"
#include "deposito.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int parser_cargarDepositos(ArrayList* listaDeposito, char* filename)
{
    int retorno = -1;
    char producto[128];
    char descripcion [128];
    char cantidad[128];
    Deposito* auxDeposito;

    if(listaDeposito != NULL && filename != NULL)
    {
        FILE* fp = fopen(filename, "r");

        if(fp != NULL)
        {
            fscanf(fp, "%[^,],%[^,],%[^\n]\n", producto, descripcion, cantidad);
            while (!feof(fp))
            {
                fscanf(fp, "%[^,],%[^,],%[^\n]\n", producto, descripcion, cantidad);
                auxDeposito = deposito_newConParametros(atoi(producto), descripcion, atoi(cantidad));
                al_add(listaDeposito, auxDeposito);
                //printf("%s, %s", producto, descripcion);
            }

            retorno = 0;
        }
        fclose(fp);
    }

    return retorno;
}
