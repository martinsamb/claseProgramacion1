#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Venta.h"                          //Replace Venta (tipo) y venta (f)     campos: IdCliente + idCliente // CodProducto + int2 // Precio + nombre2
#include "File.h"
#include "utn.h"

/*




*/

/** \brief Carga los datos de los empleados desde el archivo indicado (modo texto).
 *
 * \param path char* Nombre del archivo
 * \param pArrayList LinkedList*
 * \return int -1 Error(parametros nulos o 0 elemetos cargados) 0 Carga exitosa (al menos un elemento cargado)
 *
 */
int controllerVenta_loadFromText(char* path , LinkedList* pArrayList)
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
                    retornoParser=parser_VentaFromText(pFile,pArrayList);
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
int controllerVenta_loadFromBinary(char* path , LinkedList* pArrayList)
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
                    retornoParser=parser_VentaFromBinary(pFile,pArrayList);
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

/** \brief Alta de Venta
 *
 * \param pArrayList LinkedList*
 * \param ultimoId int* Puntero al maximo ID actual de la lista
 * \return int -1 Error / 0 Alta exitosa
 *
 */
int controllerVenta_addVenta(LinkedList* pArrayList, int* ultimoId)
{
    int retorno=-1;
    char arrayBuffers[5][STR_SIZE];             //cambiar por cantidad de campos
    Venta* auxPuntero=NULL;

    if(pArrayList!=NULL)
    {
        utn_getTexto("\nID Cliente ","\nError",1,STR_SIZE,1,arrayBuffers[1]);
        utn_getTexto("\nCodigo Producto","\nError",1,STR_SIZE,1,arrayBuffers[2]);           //cambiar
        utn_getTexto("\nCantidad ","\nError",1,STR_SIZE,1,arrayBuffers[3]);
        utn_getTexto("\nPrecio ","\nError",1,STR_SIZE,1,arrayBuffers[4]);
        sprintf(arrayBuffers[0],"%d",(*ultimoId)+1);

        auxPuntero=venta_newParametros(arrayBuffers[0],arrayBuffers[1],arrayBuffers[2],arrayBuffers[3],arrayBuffers[4]);         //valido los datos y lo guardo en aux
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

/** \brief Modificar datos de Venta
 *
 * \param pArrayList LinkedList*
 * \return int -1 Error / 0 Modificacion exitosa
 *
 */
int controllerVenta_editVenta(LinkedList* pArrayList)
{
    int retorno=-1;
    int id;
    int indice;
    char opcion;
    char bufferModificacion[STR_SIZE];
    int bufferID;
    int bufferIdCliente;                        //cambiar
    int bufferCodProducto;                       //cambiar
    int bufferCantidad;
    float bufferPrecio;
    Venta* puntero=NULL;

    if(pArrayList!=NULL)
    {
        if(utn_getUnsignedInt("\nID a modificar: ","\nError",1,8,1,&id)==0)
        {
            if(venta_searchId(pArrayList,id,&indice)==-1)
            {
                printf("\nNo existe este ID");
            }
            else
            {
                do
                {
                    puntero=ll_get(pArrayList,indice);
                    venta_getId(puntero,&bufferID);
                    venta_getCantidad(puntero,&bufferCantidad);
                    venta_getPrecio(puntero,&bufferPrecio);
                    venta_getIdCliente(puntero,&bufferIdCliente);
                    venta_getCodProducto(puntero,&bufferCodProducto);
                    printf("\n ID: %d  IdCliente: %d   CodProducto: %d   Cantidad: %d   Precio: %f",bufferID,bufferIdCliente,bufferCodProducto,bufferCantidad,bufferPrecio);                       //cambiar

                    utn_getLetra("\nModificar: A IdCliente B CodProducto C Cantidad D Precio S(salir)","\nError",1,&opcion);                      //cambiar
                    switch(opcion)
                    {
                        case 'A':
                            utn_getTexto("\nIdCliente: ","\nError",1,STR_SIZE,1,bufferModificacion);                     //cambiar
                            venta_setIdClienteStr(puntero,bufferModificacion);
                            break;
                        case 'B':
                            utn_getTexto("\nCodProducto: ","\nError",1,sizeof(int),1,bufferModificacion);                       //cambiar
                            venta_setCodProductoStr(puntero,bufferModificacion);
                            break;
                        case 'C':
                            utn_getTexto("\nCantidad: ","\nError",1,sizeof(int),1,bufferModificacion);                       //cambiar
                            venta_setCantidadStr(puntero,bufferModificacion);
                            break;

                        case 'D':
                            utn_getTexto("\nPrecio: ","\nError",1,sizeof(int),1,bufferModificacion);                       //cambiar
                            venta_setPrecioStr(puntero,bufferModificacion);
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

/** \brief Baja de Venta
 *
 * \param pArrayList LinkedList*
 * \return int -1 Error / 0 Baja exitosa
 *
 */
int controllerVenta_removeVenta(LinkedList* pArrayList)
{
    int retorno=-1;
    int id;
    int indice;
    if(pArrayList!=NULL)
    {
        if(utn_getUnsignedInt("\nID a cancelar: ","\nError",1,8,1,&id)==0)
        {
            if(venta_searchId(pArrayList,id,&indice)==-1)
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

/** \brief Listar Venta
 *
 * \param pArrayList LinkedList*
 * \return int -1 Error (parametros nulos) / 0 parametros validos
 *
 */
int controllerVenta_ListVenta(LinkedList* pArrayList)
{
    int retorno=-1;
    int i;
    int bufferID;
    int bufferIdCliente;                       //cambiar
    int bufferCodProducto;
    int bufferCantidad;
    float bufferPrecio;
    int size=ll_len(pArrayList);
    Venta* puntero;

    if(pArrayList!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            puntero=ll_get(pArrayList,i);
            venta_getId(puntero,&bufferID);
            venta_getCantidad(puntero,&bufferCantidad);
            venta_getPrecio(puntero,&bufferPrecio);
            venta_getIdCliente(puntero,&bufferIdCliente);                       //cambiar
            venta_getCodProducto(puntero,&bufferCodProducto);

            printf("\n ID: %d  IdCliente: %d   CodProducto: %d   Cantidad: %d   Precio: %f",bufferID,bufferIdCliente,bufferCodProducto,bufferCantidad,bufferPrecio);                       //cambiar
        }
        retorno=0;
    }
    return retorno;
}

/** \brief Ordena Venta por nombre (diferencia mayusculas y minusculas)
 *
 * \param pArrayList LinkedList*
 * \return int -1 Error (parametros nulos) / 0 parametros validos
 *
 *//*
int controllerVenta_sortVenta(LinkedList* pArrayList)
{
    int retorno=-1;
    if(pArrayList!=NULL)
    {
        ll_sort(pArrayList,venta_cmpName,1);
        retorno=0;
    }
    return retorno;
}*/

/** \brief Guarda los datos de los empleados en el archivo indicado (modo texto).
 *
 * \param path char* Nombre del archivo
 * \param pArrayList LinkedList*
 * \return int -1 Error / 0 Apertura de archivo exitosa
 *
 */
int controllerVenta_saveAsText(char* path , LinkedList* pArrayList)
{
    int i;
    Venta* pVenta=NULL;
    int retorno=-1;
    FILE *pFile=NULL;
    int bufferID;
    int bufferIdCliente;                       //cambiar
    int bufferCodProducto;                       //cambiar
    int bufferCantidad;
    float bufferPrecio;
    int contador=0;

    if(path!=NULL && pArrayList!=NULL)
    {
        pFile=fopen(path,"w");
        if(pFile!=NULL)
        {
            for(i=0;i<ll_len(pArrayList);i++)
            {
                pVenta=ll_get(pArrayList,i);
                venta_getId(pVenta,&bufferID);
                venta_getCantidad(pVenta,&bufferCantidad);
                venta_getPrecio(pVenta,&bufferPrecio);
                venta_getIdCliente(pVenta,&bufferIdCliente);                       //cambiar
                venta_getCodProducto(pVenta,&bufferCodProducto);                       //cambiar

                if(fprintf(pFile,"%d,%d,%d,%d,%f\n",bufferID,bufferIdCliente,bufferCodProducto,bufferCantidad,bufferPrecio)>9)                       //cambiar
                    contador++;
            }
            retorno=0;
            fclose(pFile);
            printf("\nElementos guardados exitosamente: %d",contador);
        }
    }
    return retorno;
}

/** \brief Guarda los datos de los Venta en el archivo indicado (modo binario).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int -1 Error / 0 Apertura de archivo exitosa
 *
 *//*
int controllerVenta_saveAsBinary(char* path , LinkedList* pArrayList)
{
    int i;
    Venta* pVenta=NULL;
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
                pVenta=ll_get(pArrayList,i);         //obtengo el puntero de c/empleado
                contador+=fwrite(pVenta,sizeof(Venta),1,pFile);        //1 > cuantos empleados se guardan en cada iteracion
            }
            retorno=0;
            fclose(pFile);
            printf("\nElementos guardados exitosamente: %d",contador);
        }
    }
    return retorno;
}*/


