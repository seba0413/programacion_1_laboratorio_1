#ifndef DEPOSITO_H_INCLUDED
#define DEPOSITO_H_INCLUDED

typedef struct
{
    int producto;
    char descripcion [128];
    int cantidad;
}Deposito;

Deposito* deposito_new();
void deposito_delete();
Deposito* deposito_newConParametros(int producto,char* descripcion ,int cantidad);

int deposito_setProducto(Deposito* this,int producto);
int deposito_getProducto(Deposito* this,int* producto);

int deposito_setDescripcion (Deposito* this,char* descripcion );
int deposito_getDescripcion (Deposito* this,char* descripcion );

int deposito_setCantidad(Deposito* this,int cantidad);
int deposito_getCantidad(Deposito* this,int* cantidad);

#endif // DEPOSITO_H_INCLUDED
