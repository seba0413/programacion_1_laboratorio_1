#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*char array1[50];
    char array2[50];
    printf("%s", array2);
    scanf("%s", array1);
    strcpy(array2,array1);
    printf("%s", array2);
    */

    int numero;
    int j;
    //paso 1
    char arrayAux[50];
    for(j=0; j<50;j++)
        arrayAux[j]='*';
    fgets(arrayAux, sizeof(arrayAux), stdin);
    //paso 2
    int i;
    int retorno = 0;
    for(i=0; i<strlen(arrayAux);i++)
    {
        if (arrayAux[i]<'0' || arrayAux > '9')
        {
            retorno = -1;
            break;
        }
    }
    //paso 3
    if(retorno == 0)
    {
        //uso atoi
        numero = atoi(arrayAux);
        printf("Ingresaste %d", numero);
    }
    else
    {
        printf("No ingresaste numero");
    }

}


//strlen= cantidad de caracteres validos que tiene esa cadena
//strcpy= copiar en una cadena de destino una cadena de origen
//strcat = identifica la ultima posicion escrita en el array y le agrega otra cadena
//fgets= obtiene la cadena ingresada por el usuario pero controlando la cantidad de char que se pueden ingresar
