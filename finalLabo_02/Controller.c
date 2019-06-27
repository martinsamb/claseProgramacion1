#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Entrega.h"
#include "File.h"
#include "utn.h"

/** \brief Carga los datos de los empleados desde el archivo indicado (modo texto).
 *
 * \param path char* Nombre del archivo
 * \param pArrayList LinkedList*
 * \return int -1 Error(parametros nulos o 0 elemetos cargados) 0 Carga exitosa (al menos un elemento cargado)
 *
 */
int controllerEntrega_loadFromText(char* path , LinkedList* pArrayList)
{
    int retorno=-1;
    int contadorError=0;
    int contadorCargados=0;
    int retornoParser;
    //int option=0;

    FILE *pFile=NULL;

    if(path!=NULL && pArrayList!=NULL)
    {
        ll_clear(pArrayList);
        pFile=fopen(path,"r");

        if(pFile!=NULL)
        {
            while(!feof(pFile))
            {
                retornoParser=parser_EntregaFromText(pFile,pArrayList);
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
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo indicado (modo binario).
 *
 * \param path char* Nombre del archivo
 * \param pArrayList LinkedList*
 * \return int -1 Error(parametros nulos o 0 elemetos cargados) 0 Carga exitosa (al menos un elemento cargado)
 *
 *//*
int controllerEntrega_loadFromBinary(char* path , LinkedList* pArrayList)
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
                    retornoParser=parser_EntregaFromBinary(pFile,pArrayList);
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

/** \brief Alta de Entrega
 *
 * \param pArrayList LinkedList*
 * \param ultimoId int* Puntero al maximo ID actual de la lista
 * \return int -1 Error / 0 Alta exitosa
 *
 */
int controllerEntrega_addEntrega(LinkedList* pArrayList, int* ultimoId)
{
    int retorno=-1;
    char arrayBuffers[4][STR_SIZE];
    Entrega* pEntrega=NULL;

    if(pArrayList!=NULL)
    {
        utn_getTexto("\nNombre ","\nError",1,STR_SIZE,1,arrayBuffers[1]);
        utn_getTexto("\nApellido ","\nError",1,STR_SIZE,1,arrayBuffers[2]);
        utn_getTexto("\nDNI ","\nError",1,STR_SIZE,1,arrayBuffers[3]);
        sprintf(arrayBuffers[0],"%d",(*ultimoId)+1);

        pEntrega = entrega_newParametros(arrayBuffers[0],arrayBuffers[1],arrayBuffers[2],arrayBuffers[3]);         //valido los datos y lo guardo en aux
        if(pEntrega!=NULL)
        {
            ll_add(pArrayList,pEntrega);
            retorno=0;
            (*ultimoId)++;
            printf("\nAlta exitosa");
        }
        else
            printf("\nError");
    }
    return retorno;
}

/** \brief Modificar datos de Entrega
 *
 * \param pArrayList LinkedList*
 * \return int -1 Error / 0 Modificacion exitosa
 *
 */
int controllerEntrega_editEntrega(LinkedList* pArrayList)
{
    int retorno=-1;
    int id;
    int indice;
    char opcion;
    char bufferModificacion[STR_SIZE];
    int bufferID;
    int bufferCantidad; //cambiar
    float bufferImporte; //cambiar
    char bufferTipo[STR_SIZE];
    Entrega* pEntrega=NULL;

    if(pArrayList!=NULL)
    {
        if(utn_getUnsignedInt("\nID a modificar: ","\nError",1,8,1,&id)==0)
        {
            if(entrega_searchId(pArrayList,id,&indice)==-1)
            {
                printf("\nNo existe este ID");
            }
            else
            {
                do
                {
                    pEntrega=ll_get(pArrayList,indice);
                    entrega_getId(pEntrega,&bufferID);
                    entrega_getTipo(pEntrega,bufferTipo);
                    entrega_getCantidad(pEntrega,&bufferCantidad);
                    entrega_getImporte(pEntrega,&bufferImporte);
                    printf("\n ID: %d   Tipo: %s   Cantidad: %d  Importe: %f  ",bufferID,bufferTipo,bufferCantidad,bufferImporte);                       //cambiar

                    utn_getLetra("\nModificar: A Tipo B Cantidad C Importe S(salir)","\nError",1,&opcion);                      //cambiar
                    switch(opcion)
                    {
                        case 'A':
                            utn_getTexto("\nTipo: ","\nError",1,STR_SIZE,1,bufferModificacion);                     //cambiar
                            entrega_setTipo(pEntrega,bufferModificacion);
                            break;
                        case 'B':
                            utn_getTexto("\nCantidad: ","\nError",1,sizeof(int),1,bufferModificacion);                     //cambiar
                            entrega_setCantidadStr(pEntrega,bufferModificacion);
                            break;
                        case 'C':
                            utn_getTexto("\nImporte: ","\nError",1,sizeof(int),1,bufferModificacion);                     //cambiar
                            entrega_setImporteStr(pEntrega,bufferModificacion);
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

/** \brief Baja de Entrega
 *
 * \param pArrayList LinkedList*
 * \return int -1 Error / 0 Baja exitosa
 *
 */
int controllerEntrega_removeEntrega(LinkedList* pArrayList)
{
    int retorno=-1;
    int id;
    int indice;
    if(pArrayList!=NULL)
    {
        if(utn_getUnsignedInt("\nID a cancelar: ","\nError",1,8,1,&id)==0)
        {
            if(entrega_searchId(pArrayList,id,&indice)==-1)
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

/** \brief Listar Entrega
 *
 * \param pArrayList LinkedList*
 * \return int -1 Error (parametros nulos) / 0 parametros validos
 *
 */
int controllerEntrega_ListEntrega(LinkedList* pArrayList)
{
    int retorno=-1;
    int i;
    int bufferID;
    int bufferCantidad;
    float bufferImporte;
    char bufferTipo[STR_SIZE];
    int size=ll_len(pArrayList);
    Entrega* pEntrega;

    if(pArrayList!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            pEntrega=ll_get(pArrayList,i);
            entrega_getId(pEntrega,&bufferID);
            entrega_getTipo(pEntrega,bufferTipo);
            entrega_getCantidad(pEntrega,&bufferCantidad);
            entrega_getImporte(pEntrega,&bufferImporte);

            printf("\n ID: %d   Tipo: %s  Cantidad: %d  Importe: %f  ",bufferID,bufferTipo,bufferCantidad,bufferImporte);                       //cambiar
        }
        retorno=0;
    }
    return retorno;
}

/** \brief Ordena Entrega por nombre (diferencia mayusculas y minusculas)
 *
 * \param pArrayList LinkedList*
 * \return int -1 Error (parametros nulos) / 0 parametros validos
 *
 */
int controllerEntrega_sortEntrega(LinkedList* pArrayList)
{
    int retorno=-1;
    if(pArrayList!=NULL)
    {
        ll_sort(pArrayList,entrega_compareTipo,1);
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
int controllerEntrega_saveAsText(char* path , LinkedList* pArrayList)
{
    int i;
    Entrega* pEntrega=NULL;
    int retorno=-1;
    FILE *pFile=NULL;
    int bufferID;
    int bufferCantidad;
    float bufferImporte;
    char bufferTipo[STR_SIZE];
    int contador=0;

    if(path!=NULL && pArrayList!=NULL)
    {
        pFile=fopen(path,"w");
        if(pFile!=NULL)
        {
            for(i=0;i<ll_len(pArrayList);i++)
            {
                pEntrega=ll_get(pArrayList,i);
                entrega_getId(pEntrega,&bufferID);
                entrega_getTipo(pEntrega,bufferTipo);
                entrega_getCantidad(pEntrega,&bufferCantidad);
                entrega_getImporte(pEntrega,&bufferImporte);

                if(fprintf(pFile,"%d,%s,%d,%f\n",bufferID,bufferTipo,bufferCantidad,bufferImporte)>8)     //cambiar
                    contador++;
            }
            retorno=0;
            fclose(pFile);
            printf("\nElementos guardados exitosamente: %d",contador);
        }
    }
    return retorno;
}
/*
int controller_ListData(LinkedList* pArrayListData)
{
    int retorno = -1;
    int i;
    char option = 'n';
    char option2 = 'n';
    int pagina = 99;
    int bufferId;
    Data *data;
    char bufferTipo[1000];
    int bufferCantidad;
    float bufferImporte;
    printf("Cargando lista...\n");
//    ll_sort(pArrayListCliente, cliente_compare, ASCENDENTE);
    if(pArrayListData != NULL)
    {
        do
        {
            for(i = 0; i < ll_len(pArrayListData); i++)
            {
                data = (Data*)ll_get(pArrayListData, i);
                if( !data_getTipo(data, bufferTipo)&&
                    !data_getId(data, &bufferId)&&
                    !data_getCantidad(data,&bufferCantidad)&&
                    !data_getImporte(data, &bufferImporte))
                    {
                        printf("Id: %d\t Tipo : %s\t  cantidad: %d\t Importe: %.2f\n",
                                bufferId,
                                bufferTipo,
                                bufferCantidad,
                                bufferImporte );
                        retorno = 0;
                    }
                    else
                    {
                        printf("\nNo se pudo mostrar al cliente\n");
                        retorno = -1;
                    }

                if(i == pagina)
                {
                    do
                    {
                        utn_getChar("\n\tPresione 's' para siguiente pagina: ",
                        "Error, vuelva a intentar",1,2,2,&option2);
                        pagina+=99;
                        system("clear");
                    }while(option2 == 'n');
                }
            }
            utn_getChar("\n\tPresione 's' para volver al menu principal: ",
                        "Error, vuelva a intentar",1,2,2,&option);
        }while(option == 'n');
    }
    return retorno;
}

int controller_Informe(char *path, LinkedList *pArrayListData)
{
    int retorno = -1;
    int i;
    int cantidadDeEntregas;
    int cantidadBultos = 0;
    int auxCantidadBultos;
    int cantidadDeEntregasRegular;
    int cantidadDeEntregasGold;
    int cantidadDeEntregasPlus;
    float promedioImportes;
    float promedioBultos;
    float auxImporte;
    float importeTotal = 0;

    Data *pData;
    FILE* pFile = NULL;
    LinkedList *regular = ll_newLinkedList();
    LinkedList *gold = ll_newLinkedList();
    LinkedList *plus = ll_newLinkedList();
    regular = ll_filter(pArrayListData, data_REGULAR);
    if(path != NULL && pArrayListData != NULL)
    {
        pFile = fopen(path, "w");
        if(pFile != NULL)
        {
            cantidadDeEntregas = ll_len(pArrayListData);
            regular = ll_filter(pArrayListData, data_REGULAR);
            gold = ll_filter(pArrayListData, data_GOLD);
            plus = ll_filter(pArrayListData, data_PLUS);

            for(i = 0; i < ll_len(pArrayListData); i++)
            {
                pData = ll_get(pArrayListData, i);
                data_getCantidad(pData, &auxCantidadBultos);
                data_getImporte(pData, &auxImporte);
                importeTotal = importeTotal + auxImporte;
                cantidadBultos = cantidadBultos + auxCantidadBultos;
            }
            promedioBultos = (cantidadBultos /(float) cantidadDeEntregas);
            promedioImportes = (float)(importeTotal / cantidadDeEntregas);

            cantidadDeEntregasRegular = ll_len(regular);
            cantidadDeEntregasGold = ll_len(gold);
            cantidadDeEntregasPlus = ll_len(plus);

            fprintf(pFile,  "*****************\n"
                            "Informe de ventas\n"
                            "*****************\n"
                            "Cantidad total de entregas: %d\n"
                            "Cantidad de entregas por tipo: %d (GOLD) - %d (REGULAR) - %d (PLUS)\n"
                            "Cantidad total de bultos entregados: %d\n"
                            "Promedio de bultos por entrega: %.2f\n"
                            "Importe promedio por entrega: %.2f\n",
                    cantidadDeEntregas,
                    cantidadDeEntregasGold,
                    cantidadDeEntregasRegular,
                    cantidadDeEntregasPlus,
                    cantidadBultos,
                    promedioBultos,
                    promedioImportes);
        }
        printf("\nInforme generado con exito\n");
        fclose(pFile);
    }
    return retorno;
}
*/
/** \brief Guarda los datos de los Entrega en el archivo indicado (modo binario).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int -1 Error / 0 Apertura de archivo exitosa
 *
 *//*
int controllerEntrega_saveAsBinary(char* path , LinkedList* pArrayList)
{
    int i;
    Entrega* pEntrega=NULL;
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
                pEntrega=ll_get(pArrayList,i);         //obtengo el puntero de c/empleado
                contador+=fwrite(pEntrega,sizeof(Entrega),1,pFile);        //1 > cuantos empleados se guardan en cada iteracion
            }
            retorno=0;
            fclose(pFile);
            printf("\nElementos guardados exitosamente: %d",contador);
        }
    }
    return retorno;
}*/



