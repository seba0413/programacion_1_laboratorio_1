#ifndef REPARTO_H_INCLUDED
#define REPARTO_H_INCLUDED

typedef struct
{
    int id;
    char producto[128];
    char direccion[128];
    char localidad[128];
    char recibe[128];
}Reparto;

/** \brief Imprime todas las entregas de la lista
 *
 * \param void* elemento
 * \param
 * \return void
 *
 */

void imprimirEntrega(void* elemento);

/** \brief Ordena dos elementos por localidad
 *
 * \param void* elemento1
 * \param void* elemento2
 * \return int resultado de la comparacion
 *
 */

int ordenarPorLocalidad(void* elemento1, void* elemento2);

/** \brief Imprime las localidades de los repartos
 *
 * \param ArrayList* listaReparto
 * \param
 * \return int 0 ok, -1 error
 *
 */

int reparto_imprimirLocalidades(ArrayList* listaReparto);

/** \brief  Carga en una lista los repartos de una localidad que ingresa el usuario
 *
 * \param ArrayList* listaReparto
 * \param ArrayList* listaNueva
 * \param char* localidad
 * \return char* localidad
 *
 */

char* reparto_repartoPorLocalidad(ArrayList* listaReparto, ArrayList* listaNueva, char* localidad);

/** \brief Genera un archivo de texto
 *
 * \param ArrayList* listaNueva
 * \param char* fileName
 * \return int 0 ok, -1 error
 *
 */

int reparto_generarArchivo(ArrayList* listaNueva, char* fileName);

Reparto* reparto_new();
void reparto_delete();
Reparto* reparto_newConParametros(int id,char* producto,char* direccion,char* localidad,char* recibe);

int reparto_setId(Reparto* this,int id);
int reparto_getId(Reparto* this,int* id);

int reparto_setProducto(Reparto* this,char* producto);
int reparto_getProducto(Reparto* this,char* producto);

int reparto_setDireccion(Reparto* this,char* direccion);
int reparto_getDireccion(Reparto* this,char* direccion);

int reparto_setLocalidad(Reparto* this,char* localidad);
int reparto_getLocalidad(Reparto* this,char* localidad);

int reparto_setRecibe(Reparto* this,char* recibe);
int reparto_getRecibe(Reparto* this,char* recibe);

#endif // REPARTO_H_INCLUDED
