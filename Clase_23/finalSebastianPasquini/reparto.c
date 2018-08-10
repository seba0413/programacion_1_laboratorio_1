#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "utn.h"
#include "parser.h"
#include "reparto.h"

void imprimirEntrega(void* elemento)
{
    int id;
    char producto[128];
    char direccion[128];
    char localidad[128];
    char recibe[128];
    Reparto* auxiliar = (Reparto*) elemento;

    reparto_getId(auxiliar, &id);
    reparto_getProducto(auxiliar, producto);
    reparto_getDireccion(auxiliar, direccion);
    reparto_getLocalidad(auxiliar, localidad);
    reparto_getRecibe(auxiliar, recibe);

    printf("\nId: %d\nProducto: %s\nDireccion: %s\nLocalidad: %s\nRecibe: %s\n", id,producto,direccion,localidad,recibe);
}

int ordenarPorLocalidad(void* elemento1, void* elemento2)
{
    char localidad1[128];
    char localidad2[128];

    Reparto* auxiliar1 = (Reparto*) elemento1;
    Reparto* auxiliar2 = (Reparto*) elemento2;

    reparto_getLocalidad(auxiliar1, localidad1);
    reparto_getLocalidad(auxiliar2, localidad2);

    return strcmp(localidad1, localidad2);
}

int reparto_imprimirLocalidades(ArrayList* listaReparto)
{
    int retorno = -1;
    int i;
    Reparto* auxiliar1;
    Reparto* auxiliar2;
    char localidad1[128];
    char localidad2[128];

    if(listaReparto != NULL)
    {
        al_sort(listaReparto, ordenarPorLocalidad, 0);

        for(i = 0; i < al_len(listaReparto)-1; i++)
        {
            auxiliar1 = al_get(listaReparto, i);
            auxiliar2 = al_get(listaReparto, i+1);

            reparto_getLocalidad(auxiliar1, localidad1);
            reparto_getLocalidad(auxiliar2, localidad2);

            if (strcmp(localidad1, localidad2)!= 0)
                printf("\n%s\n", localidad1);
        }
        retorno = 0;
    }
    return retorno;
}

char* reparto_repartoPorLocalidad(ArrayList* listaReparto, ArrayList* listaNueva, char* localidad)
{
    char auxLocalidad[128];
    Reparto* auxiliar;
    int i;

    if(listaReparto != NULL && listaNueva != NULL)
    {
        fflush(stdin);
        printf("\nIngrese localidad:\n");
        gets(localidad);

        for(i = 0; i< al_len(listaReparto); i++)
        {
            auxiliar = al_get(listaReparto, i);
            reparto_getLocalidad(auxiliar, auxLocalidad);
            if(!strcmp(localidad, auxLocalidad))
                al_add(listaNueva, auxiliar);
        }
        printf("\nSe cargaron a la lista los repartos de la localidad de %s\n", localidad);
    }
    return localidad;
}

int reparto_generarArchivo(ArrayList* listaNueva, char* fileName)
{
    int retorno = -1;
    int id;
    char producto[128];
    char direccion[128];
    char localidad[128];
    char recibe[128];
    int i;
    Reparto* auxiliar;

    if(listaNueva != NULL)
    {
        FILE* pFile = fopen(fileName, "w");
        if(pFile != NULL)
        {
            for(i = 0; i < al_len(listaNueva); i++)
            {
                auxiliar = al_get(listaNueva, i);
                reparto_getId(auxiliar, &id);
                reparto_getProducto(auxiliar, producto);
                reparto_getDireccion(auxiliar, direccion);
                reparto_getLocalidad(auxiliar, localidad);
                reparto_getRecibe(auxiliar, recibe);
                fprintf(pFile,"%d,%s,%s,%s,%s\n",id,producto,direccion,localidad,recibe);
            }
            retorno = 0;
            printf("\nArchivo generado correctamente\n");
        }
        else
            printf("\nEl archivo no pudo generarse\n");

        fclose(pFile);
    }
    return retorno;

}

Reparto* reparto_new()
{
    Reparto* this;
    this=malloc(sizeof(Reparto));
    return this;
}

void reparto_delete(Reparto* this)
{
    free(this);
}

Reparto* reparto_newConParametros(int id,char* producto,char* direccion,char* localidad,char* recibe)
{
    Reparto* this;
    this=reparto_new();

    if(
    !reparto_setId(this,id)&&
    !reparto_setProducto(this,producto)&&
    !reparto_setDireccion(this,direccion)&&
    !reparto_setLocalidad(this,localidad)&&
    !reparto_setRecibe(this,recibe))
        return this;

    reparto_delete(this);
    return NULL;
}

int reparto_setId(Reparto* this,int id)
{
    int retorno=-1;
    static int proximoId=-1;

    if(this!=NULL && id==-1)
    {
        proximoId++;
        this->id=proximoId;
        retorno=0;
    }
    else if(id>proximoId)
    {
        proximoId=id;
        this->id=proximoId;
        retorno=0;
    }
    return retorno;
}

int reparto_getId(Reparto* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

int reparto_setProducto(Reparto* this,char* producto)
{
    int retorno=-1;
    if(this!=NULL && producto!=NULL)
    {
        strcpy(this->producto,producto);
        retorno=0;
    }
    return retorno;
}

int reparto_getProducto(Reparto* this,char* producto)
{
    int retorno=-1;
    if(this!=NULL && producto!=NULL)
    {
        strcpy(producto,this->producto);
        retorno=0;
    }
    return retorno;
}

int reparto_setDireccion(Reparto* this,char* direccion)
{
    int retorno=-1;
    if(this!=NULL && direccion!=NULL)
    {
        strcpy(this->direccion,direccion);
        retorno=0;
    }
    return retorno;
}

int reparto_getDireccion(Reparto* this,char* direccion)
{
    int retorno=-1;
    if(this!=NULL && direccion!=NULL)
    {
        strcpy(direccion,this->direccion);
        retorno=0;
    }
    return retorno;
}

int reparto_setLocalidad(Reparto* this,char* localidad)
{
    int retorno=-1;
    if(this!=NULL && localidad!=NULL)
    {
        strcpy(this->localidad,localidad);
        retorno=0;
    }
    return retorno;
}

int reparto_getLocalidad(Reparto* this,char* localidad)
{
    int retorno=-1;
    if(this!=NULL && localidad!=NULL)
    {
        strcpy(localidad,this->localidad);
        retorno=0;
    }
    return retorno;
}

int reparto_setRecibe(Reparto* this,char* recibe)
{
    int retorno=-1;
    if(this!=NULL && recibe!=NULL)
    {
        strcpy(this->recibe,recibe);
        retorno=0;
    }
    return retorno;
}

int reparto_getRecibe(Reparto* this,char* recibe)
{
    int retorno=-1;
    if(this!=NULL && recibe!=NULL)
    {
        strcpy(recibe,this->recibe);
        retorno=0;
    }
    return retorno;
}

