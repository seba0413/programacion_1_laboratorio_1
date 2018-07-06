#include <stdio.h>
#include <stdlib.h>
#include "Model.h"
#include "View.h"
#include "funciones.h"
#include "HTMLBuilder.h"
#include "MovieDAO.h"

int main()
{
    char seguir='s';
    int opcion=0;

    if ((importarPeliculas(model_getMovies(),model_getMoviesLen())) == -1)
        pelicula_init(model_getMovies(),model_getMoviesLen());


    while(seguir=='s')
    {
        printf("\n1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);
        fflush(stdin);

        switch(opcion)
        {
            case 1:
                 view_pedirDatosAltaMovie();
                 autoSavePeliculas(model_getMovies(),model_getMoviesLen());
                break;
            case 2:
                 pelicula_baja(model_getMovies(),model_getMoviesLen());
                 autoSavePeliculas(model_getMovies(),model_getMoviesLen());
                break;
            case 3:
                  view_modificar();
                  autoSavePeliculas(model_getMovies(),model_getMoviesLen());
               break;
            case 4:
                 htmlBuilder_generarPagina(model_getMovies(),"template/index.html",model_getMoviesLen());
                break;
            case 5:
                movieDAO_guardarPeliculas(model_getMovies(),model_getMoviesLen());
                seguir = 'n';

                break;
        }
    }

    return 0;
}
