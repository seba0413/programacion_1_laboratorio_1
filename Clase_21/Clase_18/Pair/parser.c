#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"


int parserEmployee(char* fileName, ArrayList* pArrayListEmployee)
{
    char name[128];
    char email[128];
    ArrayList* lista;
    Employee* empleado;

    FILE* fp = fopen(fileName, "r");
    if(fp!=NULL)
    {
        printf("Abri el archivo!\n");
        do
        {
            int parts = fscanf(fp, "%[^,],%[^\n]", name, email);
            if (parts ==2)
            {
                employee_new()
            }
        }
    }
    return 0;
}
