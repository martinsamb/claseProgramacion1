#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Venta.h"
#include "LinkedList.h"
#include "validaciones.h"

#define FALSE 0
#define TRUE 1


Venta* venta_newVenta ()
{
    return (Venta*) malloc(sizeof(Venta));
}

Venta* venta_newVentaParametros(char* id, char* fecha, char* foto, char* cantidad,
                                         char* precio, char* cuit)
{
    Venta* pVenta = venta_newVenta();
    Venta* retorno = NULL;
    if (id != NULL && fecha != NULL && foto != NULL && cantidad != NULL &&
        precio != NULL && cuit != NULL)
    {
        if (venta_setIdStr(pVenta, id) && venta_setFecha(pVenta, fecha) &&
            venta_setFoto(pVenta, foto) && venta_setCantidadStr(pVenta, cantidad) &&
            venta_setPrecioStr(pVenta, precio) && venta_setCuit(pVenta, cuit))
        {

            retorno = pVenta;
        } else
        {
            venta_delete(pVenta);        }    }
    return retorno;
}


int venta_delete(Venta* this)
{
    int retorno = FALSE;
    if(this != NULL)
    {
        free((void*)this);
        retorno = TRUE;
    }
    return retorno;
}


int venta_setId(Venta* this,int id)
{
    int retorno = FALSE;
    if (this != NULL && id > 0)
    {
        this->id = id;
        retorno = TRUE;
    }
    return retorno;}

int venta_getId(Venta* this,int* id)
{
    int retorno = FALSE;
    if (this != NULL && id != NULL)
    {
        *id = this->id;
        retorno = TRUE;
    }
    return retorno;}

int venta_setIdStr(Venta* this, char* id)
{
    int retorno = FALSE;
    if (this != NULL && id != NULL)
    {
        if (isValidId(id))
        {

            if (venta_setId(this, atoi(id)))
            {
                retorno = TRUE;
            }
        }
    }
    return retorno;}


int venta_setFecha(Venta* this,char* fecha)
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

int venta_getFecha(Venta* this,char* fecha)
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



int venta_setFoto(Venta* this,char* foto)
{
    int retorno = FALSE;
    if (this != NULL && foto != NULL)
    {

        strncpy(this->foto, foto, sizeof(this->foto));
        retorno = TRUE;
    }
    return retorno;}

int venta_getFoto(Venta* this,char* foto)
{
    int retorno = FALSE;
    if (this != NULL && foto != NULL)
    {
        strncpy(foto, this->foto, sizeof(this->foto));
        retorno = TRUE;
    }
    return retorno;}


int venta_setCantidad(Venta* this,int cantidad)
{
    int retorno = FALSE;
    if (this != NULL && cantidad > 0)
    {
        this->cantidad = cantidad;
        retorno = TRUE;
    }
    return retorno;}

int venta_getCantidad(Venta* this,int* cantidad)
{
    int retorno = FALSE;
    if (this != NULL && cantidad != NULL)
    {
        *cantidad = this->cantidad;
        retorno = TRUE;
    }
    return retorno;}

int venta_setCantidadStr(Venta* this, char* cantidad)
{
    int retorno = FALSE;
    if (this != NULL && cantidad != NULL)
    {
        if (isValidId(cantidad))
        {
            if (venta_setCantidad(this, atoi(cantidad)))
            {
                retorno = TRUE;
            }
        }
    }
    return retorno;
}



int venta_setPrecio(Venta* this,float precio)
{
    int retorno = FALSE;
    int cantidad;
    if (this != NULL && precio > 0)
    {
        if (venta_getCantidad(this, &cantidad))
        {
            precio = precio * cantidad;
            this->precio = precio;
            retorno = TRUE;        }
    }
    return retorno;
}

int venta_getPrecio(Venta* this,float* precio)
{
    int retorno = FALSE;
    if (this != NULL && precio != NULL)
    {
        *precio = this->precio;
        retorno = TRUE;
    }
    return retorno;}

int venta_setPrecioStr(Venta* this, char* precio)
{
    int retorno = FALSE;
    if (this != NULL && precio != NULL)
    {
        if (isValidFLoatStr(precio))
        {
            if (venta_setPrecio(this, atof(precio)))
            {

                retorno = TRUE;
            }
        }
    }
    return retorno;
}


int venta_setCuit(Venta* this,char* cuit)
{
    int retorno = FALSE;
    if (this != NULL && cuit != NULL)
    {
        strncpy(this->cuit, cuit, sizeof(this->cuit));
        retorno = TRUE;
    }
    return retorno;}

int venta_getCuit(Venta* this,char* cuit)
{
    int retorno = FALSE;
    if (this != NULL && cuit != NULL)
    {
        strncpy(cuit, this->cuit, sizeof(this->cuit));
        retorno = TRUE;
    }
    return retorno;}


