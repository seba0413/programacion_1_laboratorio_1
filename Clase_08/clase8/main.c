#include <stdio.h>
#include <stdlib.h>
#include "persona.h"

int main()
{
    EPersona persona[3];
    int i;
    for(i = 0; i<3; i++)
    {
        fflush(stdin);
        printf("Nombre?\n");
        gets(persona[i].nombre);
        printf("Apellido?\n");
        gets(persona[i].apellido);
        printf("Legajo?\n");
        scanf("%d", &persona[i].legajo);
    }

    for(i=0; i<3; i++)
    {
        printf("%s %s. Legajo: %d\n", persona[i].nombre, persona[i].apellido, persona[i].legajo);
    }


    return 0;
}
