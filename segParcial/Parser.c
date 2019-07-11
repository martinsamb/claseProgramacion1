#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Venta.h"
#include "Parser.h"

#define FALSE 0
#define TRUE 1

int Apertura(char* archivo, LinkedList* ListaVenta)
{
    Venta* pVenta = NULL;
    FILE* pFile = fopen(archivo,"r");

    char bufferId[20];
    char bufferFecha[20];
    char bufferFoto[30];
    char bufferCantidad[30];
    char bufferPrecio[30];
    char bufferCuit[15];

    int retorno = FALSE;
    if(pFile != NULL && ListaVenta != NULL)
    {
        while(!feof(pFile))
        {
            fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
                                                    bufferId,
                                                    bufferFecha,
                                                    bufferFoto,
                                                    bufferCantidad,
                                                    bufferPrecio,
                                                    bufferCuit);

            pVenta =  venta_newVentaParametros(bufferId,
                                                     bufferFecha,
                                                     bufferFoto,
                                                     bufferCantidad,
                                                     bufferPrecio,
                                                     bufferCuit);

            if(pVenta != NULL)
            {
                ll_add(ListaVenta, pVenta);
                retorno = TRUE;
            }
        }
    }
    fclose(pFile);
    return retorno;
}

int guardado(char* archivo, int total, int mayor150, int mayor300, int polaroids)
{
    FILE* pFile = fopen(archivo, "w+");
    int retorno = FALSE;
    if (pFile != NULL)
    {
        fprintf(pFile, "Cantidad de fotos reveladas totales: ");
        fprintf(pFile, "%d", total);
        fprintf(pFile, "\nCantidad de ventas mayores a 150: ");
        fprintf(pFile, "%d", mayor150);
        fprintf(pFile, "\nCantidad de ventas mayores a 300: ");
        fprintf(pFile, "%d", mayor300);
        fprintf(pFile, "\ncantidad de fotos Polaroids reveladas: ");
        fprintf(pFile, "%d", polaroids);
        retorno = TRUE;    }
    fclose(pFile);
    return retorno;
}


