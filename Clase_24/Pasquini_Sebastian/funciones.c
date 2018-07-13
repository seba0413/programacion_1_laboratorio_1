#include "ArrayList.h"
#include "deposito.h"
#include "utn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int funciones_moverProductos(ArrayList* deposito1, ArrayList* deposito2)
{
    int retorno = -1;
    int i;
    int numeroDepositoOrigen;
    int numeroDepositoDestino;
    int codigoProductoAMover;
    int producto;

    if(deposito1 != NULL && deposito2 != NULL)
    {
        getValidInt("\nIngrese numero de deposito de origen\n", "\nOpcion invalida\n", &numeroDepositoOrigen,1,2,2);
        getValidInt("\nIngrese numero de deposito de destino\n", "\nOpcion invalida\n", &numeroDepositoDestino,1,2,2);
        if(numeroDepositoOrigen == 1)
        {
            getValidInt("\nIngrese codigo de producto a mover\n", "\nOpcion invalida\n", &codigoProductoAMover,1,10,2);
            for (i = 0; i < al_len(deposito1); i++)
            {
                Deposito* auxDeposito = al_get(deposito1, i);
                deposito_getProducto(auxDeposito, &producto);
                if (codigoProductoAMover == producto)
                {
                    al_remove(deposito1, i);
                    al_add(deposito2, auxDeposito);
                    printf("\nProducto %d borrado de la lista 1 y agregado a la lista 2\n", codigoProductoAMover);
                    retorno = 0;
                    break;
                }
            }
        }
        if(numeroDepositoOrigen == 2)
        {
            getValidInt("\nIngrese codigo de producto a mover\n", "\nOpcion invalida\n", &codigoProductoAMover,11,15,2);
            for (i = 0; i < al_len(deposito2); i++)
            {
                Deposito* auxDeposito = al_get(deposito2, i);
                deposito_getProducto(auxDeposito, &producto);
                if (codigoProductoAMover == producto)
                {
                    al_remove(deposito2, i);
                    al_add(deposito1, auxDeposito);
                    retorno = 0;
                    printf("\nProducto %d borrado de la lista 2 y agregado a la lista 1\n", codigoProductoAMover);
                    break;
                }
            }
        }
    }
    return retorno;
}

int funciones_descontarProductosDeDeposito(ArrayList* deposito1, ArrayList* deposito2)
{
    int retorno = -1;
    int i;
    int codigoProducto;
    int flag;
    int producto;
    int cantidadADescontar;
    int cantidad;

    getValidInt("\nIngrese codigo de producto\n", "\nOpcion invalida\n", &codigoProducto,1,15,2);

    for (i = 0; i < al_len(deposito1); i++)
    {
        Deposito* auxDeposito = al_get(deposito1, i);
        deposito_getProducto(auxDeposito, &producto);
        if (codigoProducto == producto)
        {
            flag = 1;
            getValidInt("\nIngrese cantidad de productos a descontar\n", "\nCantidad invalida\n", &cantidadADescontar, 1,100,2);
            deposito_getCantidad(auxDeposito, &cantidad);
            if(cantidadADescontar <= cantidad)
            {
                cantidad = cantidad - cantidadADescontar;
                deposito_setCantidad(auxDeposito, cantidad);
                al_set(deposito1, i, auxDeposito);
                printf("\nCantidad %d descontada del producto %d\n", cantidadADescontar, producto);
                retorno = 0;
                break;
            }
        }
    }
    if (!flag)
    {
        for (i = 0; i < al_len(deposito2); i++)
        {
            Deposito* auxDeposito = al_get(deposito2, i);
            deposito_getProducto(auxDeposito, &producto);
            if (codigoProducto == producto)
            {
                getValidInt("\nIngrese cantidad de productos a descontar\n", "\nCantidad invalida\n", &cantidadADescontar, 1,100,2);
                deposito_getCantidad(auxDeposito, &cantidad);
                if(cantidadADescontar <= cantidad)
                {
                    cantidad = cantidad - cantidadADescontar;
                    deposito_setCantidad(auxDeposito, cantidad);
                    al_set(deposito2, i, auxDeposito);
                    printf("\nCantidad %d descontada del producto %d\n", cantidadADescontar, producto);
                    retorno = 0;
                    break;
                }
            }
        }
    }
    return retorno;
}
//--------------------------------------------------------------------------------------------
int funciones_agregarProductosDeDeposito(ArrayList* deposito1, ArrayList* deposito2)
{
    int retorno = -1;
    int i;
    int codigoProducto;
    int flag;
    int producto;
    int cantidadASumar;
    int cantidad;

    getValidInt("\nIngrese codigo de producto\n", "\nOpcion invalida\n", &codigoProducto,1,15,2);

    for (i = 0; i < al_len(deposito1); i++)
    {
        Deposito* auxDeposito = al_get(deposito1, i);
        deposito_getProducto(auxDeposito, &producto);
        if (codigoProducto == producto)
        {
            flag = 1;
            getValidInt("\nIngrese cantidad de productos a agregar\n", "\nCantidad invalida\n", &cantidadASumar, 1,100,2);
            deposito_getCantidad(auxDeposito, &cantidad);
            cantidad = cantidad + cantidadASumar;
            deposito_setCantidad(auxDeposito, cantidad);
            al_set(deposito1, i, auxDeposito);
            printf("\nCantidad %d agregada al producto %d\n", cantidadASumar, producto);

            retorno = 0;
            break;
        }
    }
    if (!flag)
    {
        for (i = 0; i < al_len(deposito2); i++)
        {
            Deposito* auxDeposito = al_get(deposito2, i);
            deposito_getProducto(auxDeposito, &producto);
            if (codigoProducto == producto)
            {
                getValidInt("\nIngrese cantidad de productos a sumar\n", "\nCantidad invalida\n", &cantidadASumar, 1,100,2);
                deposito_getCantidad(auxDeposito, &cantidad);
                cantidad = cantidad + cantidadASumar;
                deposito_setCantidad(auxDeposito, cantidad);
                al_set(deposito2, i, auxDeposito);
                printf("\nCantidad %d agregada al producto %d\n", cantidadASumar, producto);

                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}
