#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Entrega.h"      //Replace Entrega (tipo) y entrega (f)

/** \brief Parsea los datos de las Entrega desde el archivo data.csv (modo texto).
 *
 * \param pFile FILE*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int parser_EntregaFromText(FILE* pFile , LinkedList* pArrayList)
{
    int retorno=-1;
    Entrega* pEntrega=NULL;
    char arrayBuffers[4][STR_SIZE];                                     //cambiar

    if(pFile!=NULL)
    {
        if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",arrayBuffers[0],arrayBuffers[1],arrayBuffers[2],arrayBuffers[3])==4)       //cambiar
            retorno=0;
        if(strcmp(arrayBuffers[0],"id")==0)
            retorno=-1;

        if(retorno==0)
        {                                                                                                                       //cambiar
            pEntrega=entrega_newParametros(arrayBuffers[0],arrayBuffers[1],arrayBuffers[2],arrayBuffers[3]);         //valido los datos y lo guardo en aux
            if(pEntrega!=NULL)
            {
                ll_add(pArrayList,pEntrega);
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

/** \brief Parsea los datos de las Entrega desde el archivo data.csv (modo binario).
 *
 * \param pFile FILE*
 * \param pArrayList LinkedList*
 * \return int
 *
 *//*
int parser_EntregaFromBinary(FILE* pFile , LinkedList* pArrayList)
{
    int retorno=-1;
    Entrega auxEntrega;
    Entrega* pEntrega;

    if(pFile!=NULL && pArrayList!=NULL)
    {
        if(fread(&auxEntrega,sizeof(Entrega),1,pFile)==1)
        {
            pEntrega=entrega_newBinario(auxEntrega);
            if(pEntrega!=NULL)
            {
                ll_add(pArrayList,pEntrega);
                //printf("\n%d", pEntrega->id);
                retorno=0;
            }
            else
            {
                retorno=-2;
            }
        }
    }
    return retorno;
}*/

/*
Cambiar
    cantidad de buffers, cantidad de elementos en mascara
*/
