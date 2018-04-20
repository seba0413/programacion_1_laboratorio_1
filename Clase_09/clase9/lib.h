#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nombre[50];
    char descripcion[200];
    float precio;
    int flagVacio;
}EProducto;

int cargarDatosDeProducto(EProducto array[], int indice, int size);
void imprimirDatosDeProducto(EProducto array[], int indice);
int buscarProductoSinCargar(EProducto array[], int size);
