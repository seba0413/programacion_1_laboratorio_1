#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()

{
    // ARREGLAR, NO VALIDA BIEN!!
    // dios sabe que tendra
    int numero;
    int j;


    char arrayAux[50];
    for(j=0; j<50; j++)
        arrayAux[j]='*';

    // paso 1.
    fflush(stdin);
    fgets(arrayAux,sizeof(arrayAux),stdin);
    arrayAux[strlen(arrayAux)-1] = 0;// Le quitamos el ultimo enter que se guarda en el array

    for(j=0; j<50; j++)
        printf("%c %d\n",arrayAux[j],arrayAux[j]);

    // paso 2. Validacion
    int i;
    int retorno=0;
    for(i=0; i<strlen(arrayAux); i++)
    {
        if(arrayAux[i]<'0' || arrayAux[i]>'9')
        {
            retorno=-1;
            break;
        }
    }

    // paso 3. Asignacion de valores. atoi convierte char en int
    if(retorno==0)
    {
        // uso atoi
       numero= atoi(arrayAux);
       printf("ingresaste:%d",numero);
       return numero;
    }
    else
    {
        printf("no ingresaste un numero");
    }

    char array1[5];
    int saldoEnElBanco = 0;

    //scanf("%s",array1);


    //fgets(array1,sizeof(array1),stdin);
    printf("%s",array1);

    printf("\nvar vale:%d",saldoEnElBanco);
    return 0;
}
