#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"
#include "parser.h"

/****************************************************
    Menu:
        1. Parse del archivo data.csv
        2. Listar Empleados
        3. Ordenar por nombre
        4. Agregar un elemento
        5. Elimina un elemento
        6. Listar Empleados (Desde/Hasta)
*****************************************************/


int main()
{
    ArrayList* listaEmpleados = al_newArrayList();

    //FILE* pFile;
    parserEmployee("destinatarios.csv",listaEmpleados);

    int j;
    for(j=0; al_len(listaEmpleados); j++)//al_len(blackList);
    {
        Employee* d = al_get(listaEmpleados, j); //al_get(blackList, j);

        int index = al_indexOfElement(listaEmpleados, d, comparoDest);//al_indexOfElement(destinatarios, d, comparoDest);

        al_remove(listaEmpleados, index);//al_remove(destinatarios, index);
    }


    return 0;
}
