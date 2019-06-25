#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Empleado.h"
#include "utn.h"
#include "Parser.h"
#include "Controller.h"

int parser_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int contadorError=0;
    int contadorCargados=0;
    int retornoParser;
    int option=0;

    FILE *pFile=NULL;

    utn_getUnsignedInt("\n\nSe reiniciara la lista con los elementos cargados desde el archivo. Desea continuar? \n1) Si 2) No ","\nError",1,2,1,&option);
    if(option==1)
    {
        if(path!=NULL && pArrayListEmployee!=NULL)
        {
            //ll_clear(pArrayListEmployee);
            pFile=fopen(path,"r");    //direccìon archivo, modo de arpetura
            if(pFile!=NULL)
            {
                while(!feof(pFile))
                {
                    retornoParser=parser_parseEmpleados(pFile,pArrayListEmployee);
                    if(retornoParser==-2)
                        contadorError++;
                    else if(retornoParser==1)
                        contadorCargados++;
                }
                fclose(pFile);
                printf("\nError de validacion en %d elementos \n%d elementos cargados exitosamente",contadorError,contadorCargados);
                if(contadorCargados>0)
                    retorno=0;
            }
        }
    }
    return retorno;
}


int parser_parseEmpleados(FILE* fileName, LinkedList* listaEmpleados)
{
    int retorno=-1;
    Empleado* auxPuntero=NULL;
    char arrayBuffers[4][STR_SIZE];

    if(fileName!=NULL)
    {
        if(fscanf(fileName,"%[^,],%[^,],%[^\n]\n",arrayBuffers[0],arrayBuffers[1],arrayBuffers[2])==3)
            retorno=0;
        if(strcmp(arrayBuffers[0],"id")==0)
            retorno=-1;

        if(retorno==0)
        {
            strcpy(arrayBuffers[3],"0");
            auxPuntero=employee_newParametros(arrayBuffers[0],arrayBuffers[1],arrayBuffers[2],arrayBuffers[3]);         //valido los datos y lo guardo en aux
            if(auxPuntero!=NULL)
            {
                ll_add(listaEmpleados,auxPuntero);
                retorno=1;
            }
            else
            {
                retorno=-2;
            }
        }
    }
    return retorno;
}

int generarArchivoSueldos(char* path , LinkedList* pArrayListEmployee)
{
    int i;
    Empleado* pEmpleado=NULL;
    int retorno=-1;
    FILE *pFile=NULL;
    int bufferID;
    int bufferHoras;
    int bufferSueldo;
    char bufferNombre[STR_SIZE];
    int contador=0;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pFile=fopen(path,"w");
        if(pFile!=NULL)
        {
            for(i=0;i<ll_len(pArrayListEmployee);i++)
            {
                pEmpleado=ll_get(pArrayListEmployee,i);
                employee_getId(pEmpleado,&bufferID);
                employee_getNombre(pEmpleado,bufferNombre);
                employee_getHorasTrabajadas(pEmpleado,&bufferHoras);
                employee_getSueldo(pEmpleado,&bufferSueldo);

                if(fprintf(pFile,"%d,%s,%d,%d\n",bufferID,bufferNombre,bufferHoras,bufferSueldo)>8)
                    contador++;
            }
            retorno=0;
            fclose(pFile);
            printf("\nElementos guardados exitosamente: %d",contador);
        }
    }
    return retorno;
}

