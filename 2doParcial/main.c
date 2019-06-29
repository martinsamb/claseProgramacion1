#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Parser.h"
#include "LinkedList.h"
#include "Entidad.h"

int criterioMayor150(void* pEntidad);
int criterioMayor300(void* pEntidad);
int criterioPolaroid(void* pEntidad);
int acumuladorDeFotos(LinkedList* lista);

int main()
{
    int cantidadDeFotos = 0;
    int mayores = 0;
    int mayoresMayores = 0;
    int cantidadDeFotosPolaroid = 0;

    LinkedList* lista = ll_newLinkedList();
    if (lista != NULL)
    {
        if (Apertura("data.csv", lista))
        {
            printf("Archivo abierto\n");
            cantidadDeFotos = acumuladorDeFotos(lista);
            mayores = ll_count(lista, criterioMayor150);
            mayoresMayores = ll_count(lista, criterioMayor300);
            cantidadDeFotosPolaroid = ll_count(lista, criterioPolaroid);
            if (guardado("informe.csv", cantidadDeFotos, mayores, mayoresMayores,
                         cantidadDeFotosPolaroid))
            {
                printf("Archivo guardado\n");
            }
            else
            {
                printf("Ocurrio un error en el guardado");
            }
        }
        else
        {
            printf("Ocurrio un error en la apertura");
        }
    }
    return 0;
}

int acumuladorDeFotos(LinkedList* lista)
{
    int i;
    Entidad* pEntidad = NULL;
    int acum;
    int retorno = 0;
    if (lista != NULL)
    {
        for (i=0; i<ll_len(lista); i++)
        {
            pEntidad = ll_get(lista, i);
            entidad_getCantidad(pEntidad, &acum);
            retorno = retorno + acum;
        }
    }
    return retorno;
}


int criterioMayor150(void* pEntidad)
{
    int retorno = 0;
    float precio;
    if (pEntidad != NULL)
    {
        entidad_getPrecio(pEntidad, &precio);
        if (precio > 150)
        {
            retorno = 1;
        }
    }
    return retorno;
}

int criterioMayor300(void* pEntidad)
{
    int retorno = 0;
    float precio;
    if (pEntidad != NULL)
    {
        entidad_getPrecio(pEntidad, &precio);
        if (precio > 300)
        {
            retorno = 1;
        }
    }
    return retorno;
}

int criterioPolaroid(void* pEntidad)
{
    int retorno = 0;
    char foto[30];
    if (pEntidad != NULL)
    {
        entidad_getFoto(pEntidad, foto);
        if(strncmp(foto, "POLAROID_11x9", 13) == 0 || strncmp(foto, "POLAROID_10x10", 14) == 0)
        {
            retorno = 1;
        }
    }
    return retorno;
}
