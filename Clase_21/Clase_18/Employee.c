#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Employee.h"

static int isValidName(char* name);
static int isValidEmail(char* email);


Employee* employee_new(void)
{

    Employee* returnAux = (Employee*) malloc(sizeof(Employee));
    return returnAux;

}

Employee* employee_newParametros(char* name, char* email)
{
    Employee* this;
    this = employee_new();
    if( !employee_setName(this,name) &&
        !employee_setEmail(this,email) )
    {
        return this;
    }
    employee_delete(this);
    return NULL;
}


void employee_delete(Employee* this)
{
    if(this != NULL)
        free(this);
}


int employee_setName(Employee* this, char* name)
{
    int retorno = -1;
    if(this != NULL && name != NULL && isValidName(name))
    {
        retorno = 0;
        strcpy(this->name,name);
    }
    return retorno;
}

int employee_getName(Employee* this, char* name)
{
    int retorno = -1;
    if(this != NULL && name != NULL)
    {
        retorno = 0;
        strcpy(name,this->name);
    }
    return retorno;
}

int employee_setEmail(Employee* this, char* email)
{
    int retorno = -1;
    if(this != NULL && email != NULL && isValidEmail(email))
    {
        retorno = 0;
        strcpy(this->email,email);
    }
    return retorno;
}

int employee_getEmail(Employee* this, char* email)
{
    int retorno = -1;
    if(this != NULL && email != NULL)
    {
        retorno = 0;
        strcpy(email,this->email);
    }
    return retorno;
}



static int isValidName(char* name)
{
    return 1;
}

static int isValidEmail(char* email)
{
    return 1;
}


int employee_compareName(Employee* pEmployeeA,Employee* pEmployeeB)
{
    char nameEmployeeA[51];
    char nameEmployeeB[51];
    int retorno = 0;
    if(pEmployeeA!=NULL && pEmployeeB != NULL)
    {
        employee_getName(pEmployeeA,nameEmployeeA);
        employee_getName(pEmployeeB,nameEmployeeB);
        retorno = strcmp(nameEmployeeA,nameEmployeeB);
    }
    return retorno ;
}

/*int employee_compare(Employee* pEmployeeA,Employee* pEmployeeB)
{
    int idEmployeeA;
    int idEmployeeB;
    int retorno = 0;
    if(pEmployeeA!=NULL && pEmployeeB != NULL)
    {
        employee_getId(pEmployeeA,&idEmployeeA);
        employee_getId(pEmployeeB,&idEmployeeB);
        if(idEmployeeA > idEmployeeB)
        {
            retorno = 1;
        }
        else if(idEmployeeA < idEmployeeB)
        {
            retorno = -1;
        }

    }
    return retorno;

}*/


void employee_print(Employee* this)
{
    char name[51];
    char email[51];
    if(this != NULL)
    {
        employee_getName(this,name);
        employee_getEmail(this,email);
        fprintf(stdout,"\nNombre: %s - Email: %s", name,email);
    }

}


/*void employee_print2(Employee* this)
{
    int id;
    char name[51];
    char lastName[51];
    int isEmpty;
    if(this != NULL)
    {
        employee_getId(this,&id);
        employee_getName(this,name);
        employee_getLastName(this,lastName);
        employee_getIsEmpty(this,&isEmpty);
        fprintf(stdout,"%d,%s,%s,%s\n", id,name,lastName,isEmpty);
    }

}*/
