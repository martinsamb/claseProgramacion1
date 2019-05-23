#include <stdio.h>
#include <stdlib.h>
#include "empleado.h"

int main()
{
    //int indiceActual;
    int auxInt;

    char bufferId[4096];
    char bufferNombre[4096];
    char bufferApellido[4096];
    char bufferEstado[4096];

    FILE *pFile = NULL;
    FILE *pFileBkp = NULL;
    pFileBkp = fopen("data.csv","r");
    pFileBkp = fopen("data.csv","w");

    if(pFile != NULL && pFileBkp != NULL)
    {
        fscanf(pFile,"%[[^,],%[^,],%[^,],%[^\n]\n",
        bufferId,bufferNombre, bufferApellido, bufferEstado);

        printf("%s\n", bufferApellido);
    }
    fclose(pFile);
    fclose(pFileBkp);

    //sprint(bufferId,"%d",id); termina en una variable bufferId

    Empleado *pArrayEmpleado[1000];
    int ultimoElementoArrayEmpleado = 0;
    int indiceActual;
    float peso;
    //char* nombre;
    //int auxInt;

    indiceActual = ultimoElementoArrayEmpleado;
    pArrayEmpleado[indiceActual] =  Emp_new();


    if(pArrayEmpleado[indiceActual] != NULL)
    {
        ultimoElementoArrayEmpleado++;
        printf("OK");
        if(!Emp_setPeso(pArrayEmpleado[indiceActual],120.5))
        {
            Emp_getPeso(pArrayEmpleado[indiceActual],&peso);
            printf("\n El peso es %f",&peso);

        }
    }

    return 0;

}
