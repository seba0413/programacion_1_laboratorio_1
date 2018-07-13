
#include "deposito.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Deposito* deposito_new()
{
    Deposito* this;
    this=malloc(sizeof(Deposito));
    return this;
}

void deposito_delete(Deposito* this)
{
    free(this);
}

Deposito* deposito_newConParametros(int producto,char* descripcion ,int cantidad)
{
    Deposito* this;
    this=deposito_new();

    if(
    !deposito_setProducto(this,producto)&&
    !deposito_setDescripcion (this,descripcion )&&
    !deposito_setCantidad(this,cantidad))
        return this;

    deposito_delete(this);
    return NULL;
}

int deposito_setProducto(Deposito* this,int producto)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->producto=producto;
        retorno=0;
    }
    return retorno;
}

int deposito_getProducto(Deposito* this,int* producto)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *producto=this->producto;
        retorno=0;
    }
    return retorno;
}

int deposito_setDescripcion (Deposito* this,char* descripcion )
{
    int retorno=-1;
    if(this!=NULL && descripcion !=NULL)
    {
        strcpy(this->descripcion ,descripcion );
        retorno=0;
    }
    return retorno;
}

int deposito_getDescripcion (Deposito* this,char* descripcion )
{
    int retorno=-1;
    if(this!=NULL && descripcion !=NULL)
    {
        strcpy(descripcion ,this->descripcion );
        retorno=0;
    }
    return retorno;
}

int deposito_setCantidad(Deposito* this,int cantidad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->cantidad=cantidad;
        retorno=0;
    }
    return retorno;
}

int deposito_getCantidad(Deposito* this,int* cantidad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *cantidad=this->cantidad;
        retorno=0;
    }
    return retorno;
}

