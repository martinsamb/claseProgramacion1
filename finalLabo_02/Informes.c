#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Entrega.h"
#include "Informes.h"
#include "utn.h"

int Informes_ContadorAcumulado(LinkedList* pArrayList, int* contadorGold, int* contadorRegular, int* contadorPlus, int* acumuladoCantidad, int* promedioCantidad, int* promedioImporte)
{
    int retorno=-1;
    int i;

    int bufferCantidad=0;
    float bufferImporte=0;
    int acumuladoImporte=0;

    int size=ll_len(pArrayList);

    Entrega* pEntrega=NULL;

    if(pArrayList!=NULL && size>0)
    {
        for(i=0;i<size;i++)
        {
                pEntrega=ll_get(pArrayList,i);

                if(entrega_compareCriterio(pEntrega,"GOLD")==0)
                    (*contadorGold)++;
                if(entrega_compareCriterio(pEntrega,"REGULAR")==0)
                    (*contadorRegular)++;
                if(entrega_compareCriterio(pEntrega,"PLUS")==0)
                    (*contadorPlus)++;

                entrega_getCantidad(pEntrega,&bufferCantidad);
                (*acumuladoCantidad)+=bufferCantidad;

                entrega_getImporte(pEntrega,&bufferImporte);
                acumuladoImporte+=bufferImporte;
        }
        (*promedioCantidad)=(*acumuladoCantidad)/size;
        (*promedioImporte)=acumuladoImporte/size;

        retorno=0;
    }
    return retorno;
}

int informeEntrega_saveAsText(char* path , LinkedList* pArrayList)
{
    int retorno=-1;
    FILE *pFile=NULL;
    int cantidadTotal=ll_len(pArrayList);
    int contadorGold=0;
    int contadorRegular=0;
    int contadorPlus=0;
    int acumuladoCantidad=0;
    int promedioCantidad=0;
    int promedioImporte=0;

    if(path!=NULL && pArrayList!=NULL)
    {
        Informes_ContadorAcumulado(pArrayList,&contadorGold, &contadorRegular, &contadorPlus, &acumuladoCantidad, &promedioCantidad, &promedioImporte);
        pFile=fopen(path,"w");
        if(pFile!=NULL)
        {
            fprintf(pFile,"\n********************\n");
            fprintf(pFile,"\nInforme de ventas\n");
            fprintf(pFile,"\n********************\n");
            fprintf(pFile,"- Cantidad total de entregas: %d\n",cantidadTotal);
            fprintf(pFile,"- Cantidad de entregas por tipo: %d (GOLD) - %d (REGULAR) - %d (PLUS)\n",contadorGold,contadorRegular,contadorPlus);
            fprintf(pFile,"- Cantidad total de bultos entregados: %d\n",acumuladoCantidad);
            fprintf(pFile,"- Promedio de bultos por entrega: %d\n",promedioCantidad);
            fprintf(pFile,"- Importe promedio por entrega: %d",promedioImporte);
            fprintf(pFile,"\n********************");

            retorno=0;
            fclose(pFile);
        }
    }
    return retorno;
}

/*
- Cantidad total de entregas: XX
- Cantidad de entregas por tipo: XX (GOLD) - XX (REGULAR) - XX (PLUS)
- Cantidad total de bultos entregados: XX
- Promedio de bultos por entrega: XX
- Importe promedio por entrega: XX
*/
