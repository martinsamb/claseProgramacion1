#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Cliente.h"                          //Replace Cliente (tipo) y cliente (f)     campos: Int1 + int1 // Int2 + int2 // Apellido + apellido
#include "File.h"
#include "utn.h"

/** \brief Carga los datos de los empleados desde el archivo indicado (modo texto).
 *
 * \param path char* Nombre del archivo
 * \param pArrayList LinkedList*
 * \return int -1 Error(parametros nulos o 0 elemetos cargados) 0 Carga exitosa (al menos un elemento cargado)
 *
 */
int controllerCliente_loadFromText(char* path , LinkedList* pArrayList)
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
        if(path!=NULL && pArrayList!=NULL)
        {
            ll_clear(pArrayList);
            pFile=fopen(path,"r");    //direccion archivo, modo de arpetura

            if(pFile!=NULL)
            {
                while(!feof(pFile))
                {
                    retornoParser=parser_ClienteFromText(pFile,pArrayList);
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

/** \brief Carga los datos de los empleados desde el archivo indicado (modo binario).
 *
 * \param path char* Nombre del archivo
 * \param pArrayList LinkedList*
 * \return int -1 Error(parametros nulos o 0 elemetos cargados) 0 Carga exitosa (al menos un elemento cargado)
 *
 *//*
int controllerCliente_loadFromBinary(char* path , LinkedList* pArrayList)
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
        if(path!=NULL && pArrayList!=NULL)
        {
            ll_clear(pArrayList);
            pFile=fopen(path,"r");    //direccìon archivo, modo de arpetura

            if(pFile!=NULL)
            {
                while(!feof(pFile))
                {
                    retornoParser=parser_ClienteFromBinary(pFile,pArrayList);
                    if(retornoParser==-2)
                        contadorError++;
                    else if(retornoParser==0)
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
}*/

/** \brief Alta de Cliente
 *
 * \param pArrayList LinkedList*
 * \param ultimoId int* Puntero al maximo ID actual de la lista
 * \return int -1 Error / 0 Alta exitosa
 *
 */
int controllerCliente_addCliente(LinkedList* pArrayList, int* ultimoId)
{
    int retorno=-1;
    char arrayBuffers[4][STR_SIZE];             //cambiar por cantidad de campos
    Cliente* auxPuntero=NULL;

    if(pArrayList!=NULL)
    {
        utn_getTexto("\nNombre ","\nError",1,STR_SIZE,1,arrayBuffers[1]);
        utn_getTexto("\nApellido ","\nError",1,STR_SIZE,1,arrayBuffers[2]);           //cambiar
        utn_getTexto("\nDNI ","\nError",1,STR_SIZE,1,arrayBuffers[3]);
        sprintf(arrayBuffers[0],"%d",(*ultimoId)+1);

        auxPuntero=cliente_newParametros(arrayBuffers[0],arrayBuffers[1],arrayBuffers[2],arrayBuffers[3]);         //valido los datos y lo guardo en aux
        if(auxPuntero!=NULL)
        {
            ll_add(pArrayList,auxPuntero);
            retorno=0;
            (*ultimoId)++;
            printf("\nAlta exitosa");
        }
        else
            printf("\nError");
    }
    return retorno;
}

/** \brief Modificar datos de Cliente
 *
 * \param pArrayList LinkedList*
 * \return int -1 Error / 0 Modificacion exitosa
 *
 */
int controllerCliente_editCliente(LinkedList* pArrayList)
{
    int retorno=-1;
    int id;
    int indice;
    char opcion;
    char bufferModificacion[STR_SIZE];
    int bufferID;
    char bufferNombre[STR_SIZE];
    char bufferApellido[STR_SIZE];
    char bufferDni[STR_SIZE];
    Cliente* puntero=NULL;

    if(pArrayList!=NULL)
    {
        if(utn_getUnsignedInt("\nID a modificar: ","\nError",1,8,1,&id)==0)
        {
            if(cliente_searchId(pArrayList,id,&indice)==-1)
            {
                printf("\nNo existe este ID");
            }
            else
            {
                do
                {
                    puntero=ll_get(pArrayList,indice);
                    cliente_getId(puntero,&bufferID);
                    cliente_getNombre(puntero,bufferNombre);
                    cliente_getApellido(puntero,bufferApellido);
                    cliente_getDni(puntero,bufferDni);
                    printf("\n ID: %d   Nombre: %s   Apellido: %s  DNI: %s   ",bufferID,bufferNombre,bufferApellido,bufferDni);                       //cambiar

                    utn_getLetra("\nModificar: A Nombre B Apellido C DNI S(salir)","\nError",1,&opcion);                      //cambiar
                    switch(opcion)
                    {
                        case 'A':
                            utn_getName("\nNombre: ","\nError",1,STR_SIZE,1,bufferModificacion);                     //cambiar
                            cliente_setNombre(puntero,bufferModificacion);
                            break;
                        case 'B':
                            utn_getName("\nApellido: ","\nError",1,STR_SIZE,1,bufferModificacion);                     //cambiar
                            cliente_setApellido(puntero,bufferModificacion);
                            break;
                        case 'C':
                            utn_getTexto("\nDNI: ","\nError",1,STR_SIZE,1,bufferModificacion);                     //cambiar
                            cliente_setDni(puntero,bufferModificacion);
                            break;

                        case 'S':
                            break;
                        default:
                            printf("\nOpcion no valida");
                    }
                }while(opcion!='S');
                retorno=0;
            }
        }
    }
    return retorno;
}

/** \brief Baja de Cliente
 *
 * \param pArrayList LinkedList*
 * \return int -1 Error / 0 Baja exitosa
 *
 */
int controllerCliente_removeCliente(LinkedList* pArrayList)
{
    int retorno=-1;
    int id;
    int indice;
    if(pArrayList!=NULL)
    {
        if(utn_getUnsignedInt("\nID a cancelar: ","\nError",1,8,1,&id)==0)
        {
            if(cliente_searchId(pArrayList,id,&indice)==-1)
            {
                printf("\nNo existe este ID");
            }
            else
            {
                ll_remove(pArrayList,indice);
                printf("\nBaja exitosa");
                retorno=0;
            }
        }
    }
    return retorno;
}

/** \brief Listar Cliente
 *
 * \param pArrayList LinkedList*
 * \return int -1 Error (parametros nulos) / 0 parametros validos
 *
 */
int controllerCliente_ListCliente(LinkedList* pArrayList)
{
    int retorno=-1;
    int i;
    int bufferID;
    char bufferNombre[STR_SIZE];
    char bufferApellido[STR_SIZE];
    char bufferDni[STR_SIZE];

    int size=ll_len(pArrayList);
    Cliente* puntero;

    if(pArrayList!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            puntero=ll_get(pArrayList,i);
            cliente_getId(puntero,&bufferID);
            cliente_getNombre(puntero,bufferNombre);
            cliente_getApellido(puntero,bufferNombre);
            cliente_getDni(puntero,bufferDni);

            printf("\n ID: %d   Nombre: %s   Apellido: %s  DNI: %s",bufferID,bufferNombre,bufferApellido,bufferDni);                       //cambiar
        }
        retorno=0;
    }
    return retorno;
}

/** \brief Ordena Cliente por nombre (diferencia mayusculas y minusculas)
 *
 * \param pArrayList LinkedList*
 * \return int -1 Error (parametros nulos) / 0 parametros validos
 *
 */
int controllerCliente_sortCliente(LinkedList* pArrayList)
{
    int retorno=-1;
    if(pArrayList!=NULL)
    {
        ll_sort(pArrayList,cliente_cmpName,1);
        retorno=0;
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo indicado (modo texto).
 *
 * \param path char* Nombre del archivo
 * \param pArrayList LinkedList*
 * \return int -1 Error / 0 Apertura de archivo exitosa
 *
 */
int controllerCliente_saveAsText(char* path , LinkedList* pArrayList)
{
    int i;
    Cliente* pCliente=NULL;
    int retorno=-1;
    FILE *pFile=NULL;
    int bufferID;
    char bufferNombre[STR_SIZE];
    char bufferApellido[STR_SIZE];
    char bufferDni[STR_SIZE];
    int contador=0;

    if(path!=NULL && pArrayList!=NULL)
    {
        pFile=fopen(path,"w");
        if(pFile!=NULL)
        {
            for(i=0;i<ll_len(pArrayList);i++)
            {
                pCliente=ll_get(pArrayList,i);
                cliente_getId(pCliente,&bufferID);
                cliente_getNombre(pCliente,bufferNombre);
                cliente_getApellido(pCliente,bufferNombre);
                cliente_getDni(pCliente,bufferDni);

                if(fprintf(pFile,"%d,%s,%s,%s\n",bufferID,bufferNombre,bufferApellido,bufferDni)>8)                       //cambiar
                    contador++;
            }
            retorno=0;
            fclose(pFile);
            printf("\nElementos guardados exitosamente: %d",contador);
        }
    }
    return retorno;
}

/** \brief Guarda los datos de los Cliente en el archivo indicado (modo binario).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int -1 Error / 0 Apertura de archivo exitosa
 *
 *//*
int controllerCliente_saveAsBinary(char* path , LinkedList* pArrayList)
{
    int i;
    Cliente* pCliente=NULL;
    int retorno=-1;
    FILE *pFile=NULL;
    int contador=0;
    if(path!=NULL && pArrayList!=NULL)
    {
        pFile=fopen(path,"w");
        if(pFile!=NULL)
        {
            for(i=0;i<ll_len(pArrayList);i++)
            {
                pCliente=ll_get(pArrayList,i);         //obtengo el puntero de c/empleado
                contador+=fwrite(pCliente,sizeof(Cliente),1,pFile);        //1 > cuantos empleados se guardan en cada iteracion
            }
            retorno=0;
            fclose(pFile);
            printf("\nElementos guardados exitosamente: %d",contador);
        }
    }
    return retorno;
}*/


