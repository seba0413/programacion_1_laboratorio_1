#include "Empleado.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

S_Empleado* Empleado_new()
{
    S_Empleado* this;
    this=malloc(sizeof(S_Empleado));
    return this;
}

void Empleado_delete(S_Empleado* this)
{
    free(this);
}

int Empleado_setId(S_Empleado* this,int id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->id=id;
        retorno=0;
    }
    return retorno;
}

int Empleado_getId(S_Empleado* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

int Empleado_setNombre(S_Empleado* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

int Empleado_getNombre(S_Empleado* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

int Empleado_setHorasTrabajadas(S_Empleado* this,int horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int Empleado_getHorasTrabajadas(S_Empleado* this,int* horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int Empleado_setSueldo(S_Empleado* this,int sueldo)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->sueldo=sueldo;
        retorno=0;
    }
    return retorno;
}

int Empleado_getSueldo(S_Empleado* this,int* sueldo)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *sueldo=this->sueldo;
        retorno=0;
    }
    return retorno;
}

void Empleado_calcularSueldo(void* empleado)
{
    S_Empleado* auxEmpleado;

    auxEmpleado = (S_Empleado*) empleado;

    if(empleado != NULL)
    {

       if(auxEmpleado->horasTrabajadas < 120)
       {
           auxEmpleado->sueldo = auxEmpleado->horasTrabajadas * 180;
       }
       if(auxEmpleado->horasTrabajadas >= 120 || auxEmpleado->horasTrabajadas < 160)
       {
           auxEmpleado->sueldo = auxEmpleado->horasTrabajadas * 240;
       }
       if(auxEmpleado->horasTrabajadas >= 160 || auxEmpleado->horasTrabajadas < 240)
       {
           auxEmpleado->sueldo = auxEmpleado->horasTrabajadas * 350;
       }

    }

    empleado = (void*) auxEmpleado;

}

