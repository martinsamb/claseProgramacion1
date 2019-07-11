
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Llamada.h"
#include "LinkedList.h"
#include "validaciones.h"

#define FALSE 0
#define TRUE 1


Llamada* llamada_newLlamada ()
{
    return (Llamada*) malloc(sizeof(Llamada));
}

Llamada* llamada_newLlamadaParametros(char* Id_Llamada, char* Fecha, char* Numero_Cliente, char* ID_Problema,
                                         char* Solucionado)
{
    Llamada* pLlamada = Llamada_newLlamada();
    Llamada* retorno = NULL;
    if (ID_llamada != NULL && Fecha != NULL && Numero_Cliente != NULL && ID_problema != NULL &&
        Solucionado != NULL)
    {
        if (llamada_setId_LlamadaStr(pLlamada, id) && llamada_setFecha(pLlamada, fecha) &&
            llamada_setNumero_Cliente(pLlamada, cliente) && llamada_setID_Problema(pLlamada, problema) &&
            llamada_setSolucionado(pLlamada, solucionado))
        {

            retorno = pLlamada;
        } else
        {
            llamada_delete(pLlamada);        }    }
    return retorno;
}


int llamada_delete(Llamada* this)
{
    int retorno = FALSE;
    if(this != NULL)
    {
        free((void*)this);
        retorno = TRUE;
    }
    return retorno;
}


int llamada_setId_Llamada(Llamada* this,int id)
{
    int retorno = FALSE;
    if (this != NULL && id > 0)
    {
        this->id = id;
        retorno = TRUE;
    }
    return retorno;}

int llamada_getId_Llamada(Llamada* this,int* id)
{
    int retorno = FALSE;
    if (this != NULL && id != NULL)
    {
        *id = this->id;
        retorno = TRUE;
    }
    return retorno;}

int llamada_setId_LlamadaStr(Llamada* this, char* id)
{
    int retorno = FALSE;
    if (this != NULL && id != NULL)
    {
        if (isValidId(id))
        {

            if (llamada_setId_Llamada(this, atoi(id)))
            {
                retorno = TRUE;
            }
        }
    }
    return retorno;}


int llamada_setFecha(Llamada* this,char* fecha)
{
    int retorno = FALSE;
    if (this != NULL && fecha != NULL)
    {
        if (isValidFechaArchivo(fecha))
        {
            strncpy(this->fecha, fecha, sizeof(this->fecha));
            retorno = TRUE;
        }
    }
    return retorno;
}

int llamada_getFecha(Llamada* this,char* fecha)
{
    int retorno = FALSE;
    if (this != NULL && fecha != NULL)
    {
        if (isValidFechaArchivo(fecha))
        {
            strncpy(fecha, this->fecha, sizeof(this->fecha));
            retorno = TRUE;
        }
    }
    return retorno;}



int llamada_setNumero_Cliente(Llamada* this,char* Numero_Cliente)
{
    int retorno = FALSE;
    if (this != NULL && foto != NULL)
    {

        strncpy(this->Numero_Cliente, Numero_Cliente, sizeof(this->Numero_Cliente));
        retorno = TRUE;
    }
    return retorno;}

int llamada_getNumero_Cliente(Llamada* this,char* Numero_Cliente)
{
    int retorno = FALSE;
    if (this != NULL && foto != NULL)
    {
        strncpy(Numero_Cliente, this->Numero_Cliente, sizeof(this->Numero_Cliente));
        retorno = TRUE;
    }
    return retorno;}


int llamada_setID_Problema(Llamada* this,int ID_Problema)
{
    int retorno = FALSE;
    if (this != NULL && cantidad > 0)
    {
        this->cantidad = cantidad;
        retorno = TRUE;
    }
    return retorno;}

int llamada_getID_Problema(Llamada* this,int* ID_Problema)
{
    int retorno = FALSE;
    if (this != NULL && cantidad != NULL)
    {
        *ID_Problema = this->ID_Problema;
        retorno = TRUE;
    }
    return retorno;}

int llamada_setID_ProblemaStr(Llamada* this,int ID_Problema)
{
    int retorno = FALSE;
    if (this != NULL && cantidad != NULL)
    {
        if (isValidId(cantidad))
        {
            if (Llamada_setCantidad(this, atoi(cantidad)))
            {
                retorno = TRUE;
            }
        }
    }
    return retorno;
}



int llamada_setSolucionado(Llamada* this,int Solucionado)
{
    int retorno = FALSE;
    int cantidad;
    if (this != NULL && precio > 0)
    {
        if (Llamada_getCantidad(this, &cantidad))
        {
            precio = precio * cantidad;
            this->precio = precio;
            retorno = TRUE;        }
    }
    return retorno;
}

int llamada_getSolucionado(Llamada* this,int* solucionado)
{
    int retorno = FALSE;
    if (this != NULL && precio != NULL)
    {
        *precio = this->precio;
        retorno = TRUE;
    }
    return retorno;}


