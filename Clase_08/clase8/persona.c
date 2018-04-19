int persona_ordenarPersona(EPersona personas[], int cantidadElementos)
{
    int auxiliarPersona;
    int i;
    int retorno = -1;
    int flagSwap;

    if(cantidadElementos > 0)
    {
        retorno = 0;
        do
        {
            flagSwap = 0;
            for(i=0; i<cantidadElementos-1; i++)
            {
                if (strcmp(personas[i].apellido, personas[i+1].apellido)>0)
                {
                    auxiliarPersona = personas[i].apellido;
                    personas[i].apellido = personas[i+1].apellido;
                    personas[i+1].apellido = auxiliarPersona;
                    flagSwap = 1;
                }
            }

        }while(flagSwap);
    }

    return retorno;
}
