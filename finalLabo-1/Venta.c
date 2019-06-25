#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "Venta.h"       //Replace Venta (tipo) y venta (f)     campos: IdCliente + idCliente // CodProducto + codProducto
#include "utn.h"


/*
-venta_new
-venta_newParametros
-venta_newBinario
-venta_delete
-venta_setIdStr
-venta_setId
-venta_getId
-venta_setIdClienteStr
-venta_setIdCliente
-venta_getIdCliente
-venta_setCodProductoStr
-venta_setCodProducto
-venta_getCodProducto
-venta_setCantidad
-venta_setCantidad
-venta_getCantidad
-venta_setPrecio
-venta_setPrecio
-venta_getPrecio
-venta_cmpId
-venta_searchId
-venta_searchMaxId
*/

/** \brief Reserva espacio en memoria para un Venta
 *
 * \param void
 * \return Venta*
 *
 */
Venta* venta_new(void)       //constructor         //nuevo Venta
{
    return (Venta*) malloc(sizeof(Venta));
}

/** \brief Valida los campos y los carga en una variable Venta
 *
 * \param idStr char*
 * \param cantidadStr char*
 * \param idClienteStr char*
 * \param codProductoStr char*
 * \return Venta*
 *
 */
Venta* venta_newParametros(char* idStr,char* idClienteStr, char* codProductoStr,char* cantidadStr,char* precioStr)
{
    Venta* retorno=NULL;
    Venta* bufferP;

    if(idStr!=NULL && cantidadStr!=NULL && idClienteStr!=NULL && codProductoStr!=NULL && precioStr!=NULL)
    {
        bufferP=venta_new();
        if(bufferP!=NULL)
        {
            if(!venta_setIdStr(bufferP,idStr) &&
                !venta_setCantidadStr(bufferP,cantidadStr) &&
                !venta_setPrecioStr(bufferP,precioStr) &&
                !venta_setIdClienteStr(bufferP,idClienteStr) &&
                !venta_setCodProductoStr(bufferP,codProductoStr))
            {
                retorno=bufferP;
            }
            else
            {
                venta_delete(bufferP);
            }
        }
    }
    return retorno;
}

/** \brief Valida los campos y los carga en una variable Venta
 *
 * \param venta Venta
 * \return Venta*
 *
 *//*
Venta* venta_newBinario(Venta venta)
{
    Venta* retorno=NULL;
    Venta* bufferP;
    char arrayBuffers[5][STR_SIZE];
    sprintf(arrayBuffers[0],"%d",venta.id);
    sprintf(arrayBuffers[1],"%d",venta.idCliente);
    sprintf(arrayBuffers[2],"%d",venta.codProducto);
    sprintf(arrayBuffers[3],"%d",venta.cantidad);
    sprintf(arrayBuffers[4],"%d",venta.precio);
    if(arrayBuffers[0]!=NULL && venta.nombre!=NULL && arrayBuffers[1]!=NULL && arrayBuffers[2]!=NULL && arrayBuffers[3]!=NULL && arrayBuffers[4]!=NULL)
    {
        bufferP=venta_new();
        if(bufferP!=NULL)
        {
            if(!venta_setIdStr(bufferP,arrayBuffers[0]) &&
                !venta_setIdClienteStr(bufferP,arrayBuffers[1]) &&
                !venta_setCodProductoStr(bufferP,arrayBuffers[2]) &&
               !venta_setCantidad(bufferP,arrayBuffers[3]) &&
               !venta_setPrecio(bufferP,arrayBuffers[4]))
            {
                retorno=bufferP;
            }
            else
            {
                venta_delete(bufferP);
            }
        }
    }
    return retorno;
}*/

/** \brief Libera el espacio reservado en memoria para un venta
 *
 * \param this Venta*
 * \return void
 *
 */
void venta_delete(Venta* this)
{
    if(this!=NULL)
    {
        free(this);
    }
}

//********************************************************************************************************************
//Setter+getters


/** \brief Valida un campo y lo carga en la variable Venta
 *
 * \param this Venta*
 * \param id char*
 * \return int
 *
 */
int venta_setIdStr(Venta* this,char* id)
{
    int retorno=-1;
    if(this!=NULL && id!=NULL && isValidNumber(id))
    {
        retorno=venta_setId(this,atoi(id));
    }
    return retorno;
}

/** \brief Valida un campo y lo carga en la variable Venta
 *
 * \param this Venta*
 * \param id int
 * \return int
 *
 */
int venta_setId(Venta* this,int id)
{
    int retorno=-1;
    if(this!=NULL && id>=0)
    {
        this->id=id;
        retorno=0;
    }
    return retorno;
}

/** \brief Devulve el valor contenido en un campo de una variable Venta
 *
 * \param this Venta*
 * \param id int*
 * \return int
 *
 */
int venta_getId(Venta* this,int* id)
{
    int retorno=-1;
    if(this!=NULL && id!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

/** \brief Valida un campo y lo carga en la variable Venta
 *
 * \param this Venta*
 * \param idCliente char*
 * \return int
 *
 */
int venta_setIdClienteStr(Venta* this,char* idCliente)
{
    int retorno=-1;
    if(this!=NULL && idCliente!=NULL && isValidNumber(idCliente))
    {
        retorno=venta_setIdCliente(this,atoi(idCliente));
    }
    return retorno;
}

/** \brief Valida un campo y lo carga en la variable Venta
 *
 * \param this Venta*
 * \param idCliente int
 * \return int
 *
 */
int venta_setIdCliente(Venta* this,int idCliente)
{
    int retorno=-1;
    if(this!=NULL && idCliente>=0)
    {
        this->idCliente=idCliente;
        retorno=0;
    }
    return retorno;
}

/** \brief Devulve el valor contenido en un campo de una variable Venta
 *
 * \param this Venta*
 * \param idCliente int*
 * \return int
 *
 */
int venta_getIdCliente(Venta* this,int* idCliente)
{
    int retorno=-1;
    if(this!=NULL && idCliente!=NULL)
    {
        *idCliente=this->idCliente;
        retorno=0;
    }
    return retorno;
}

/** \brief Valida un campo y lo carga en la variable Venta
 *
 * \param this Venta*
 * \param codProducto char*
 * \return int
 *
 */
int venta_setCodProductoStr(Venta* this,char* codProducto)
{
    int retorno=-1;
    if(this!=NULL && codProducto!=NULL && isValidNumber(codProducto))
    {
        retorno=venta_setCodProducto(this,atoi(codProducto));
    }
    return retorno;
}

/** \brief Valida un campo y lo carga en la variable Venta
 *
 * \param this Venta*
 * \param codProducto int
 * \return int
 *
 */
int venta_setCodProducto(Venta* this,int codProducto)
{
    int retorno=-1;
    if(this!=NULL && codProducto>=0)
    {
        this->codProducto=codProducto;
        retorno=0;
    }
    return retorno;
}

/** \brief Devulve el valor contenido en un campo de una variable Venta
 *
 * \param this Venta*
 * \param codProducto int*
 * \return int
 *
 */
int venta_getCodProducto(Venta* this,int* codProducto)
{
    int retorno=-1;
    if(this!=NULL && codProducto!=NULL)
    {
        *codProducto=this->codProducto;
        retorno=0;
    }
    return retorno;
}

/** \brief Valida un campo y lo carga en la variable Venta
 *
 * \param this Venta*
 * \param cantidad char*
 * \return int
 *
 */
int venta_setCantidadStr(Venta* this,char* cantidad)
{
    int retorno=-1;
    if(this!=NULL && cantidad!=NULL && isValidNumber(cantidad))
    {
        retorno=venta_setCodProducto(this,atoi(cantidad));
    }
    return retorno;
}

/** \brief Valida un campo y lo carga en la variable Venta
 *
 * \param this Venta*
 * \param cantidad int
 * \return int
 *
 */
int venta_setCantidad(Venta* this,int cantidad)
{
    int retorno=-1;
    if(this!=NULL && cantidad>=0)
    {
        this->cantidad=cantidad;
        retorno=0;
    }
    return retorno;
}

/** \brief Devulve el valor contenido en un campo de una variable Venta
 *
 * \param this Venta*
 * \param cantidad int*
 * \return int
 *
 */
int venta_getCantidad(Venta* this,int* cantidad)
{
    int retorno=-1;
    if(this!=NULL && cantidad!=NULL)
    {
        *cantidad=this->cantidad;
        retorno=0;
    }
    return retorno;
}

/** \brief Valida un campo y lo carga en la variable Venta
 *
 * \param this Venta*
 * \param precio char*
 * \return int
 *
 */
int venta_setPrecioStr(Venta* this,char* precio)
{
    int retorno=-1;
    if(this!=NULL && precio!=NULL && isValidNumber(precio))
    {
        retorno=venta_setCodProducto(this,atoi(precio));
    }
    return retorno;
}

/** \brief Valida un campo y lo carga en la variable Venta
 *
 * \param this Venta*
 * \param precio int
 * \return int
 *
 */
int venta_setPrecio(Venta* this,float precio)
{
    int retorno=-1;
    if(this!=NULL && precio>=0)
    {
        this->precio=precio;
        retorno=0;
    }
    return retorno;
}

/** \brief Devulve el valor contenido en un campo de una variable Venta
 *
 * \param this Venta*
 * \param precio float*
 * \return int
 *
 */
int venta_getPrecio(Venta* this,float* precio)
{
    int retorno=-1;
    if(this!=NULL && precio!=NULL)
    {
        *precio=this->precio;
        retorno=0;
    }
    return retorno;
}

//*******************************************************************

/** \brief Busca un ID y devuelve el indice
 *
 * \param pArrayList LinkedList*
 * \param valorBuscado int
 * \param index int*
 * \return int
 *
 */
int venta_searchId(LinkedList* pArrayList, int valorBuscado, int* index)
{
    int retorno=-1;
    int i;
    int bufferID;
    int size=ll_len(pArrayList);
    Venta* puntero=NULL;

    if(pArrayList!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            puntero=ll_get(pArrayList,i);
            venta_getId(puntero,&bufferID);

            if(valorBuscado==bufferID)
            {
                *index=i;
                retorno=0;
            }
        }
    }
    return retorno;
}

/** \brief Compara dos ID
 *
 * \param this1 void*
 * \param this2 void*
 * \return int (0) Si son iguales (1) Si el primero es mayor (-1) Si el primero es menor
 *
 */
int venta_cmpId(void* this1, void* this2)
{
    int retorno=-1;

    int bufferIdI;
    int bufferIdJ;

    if(this1!=NULL && this2!=NULL)
    {
        venta_getId((Venta*)this1,&bufferIdI);
        venta_getId((Venta*)this2,&bufferIdJ);
        if(bufferIdI==bufferIdJ)
            retorno=0;
        else if(bufferIdI>bufferIdJ)
            retorno=1;
        else if(bufferIdI<bufferIdJ)
            retorno=-1;
    }
    return retorno;
}

/** \brief Compara dos CodProducto
 * \param this1 void*
 * \param this2 void*
 * \return int (0) Si son iguales (1) Si el primero es mayor (-1) Si el primero es menor
 *
 */
int venta_cmpCodProducto(void* this1, void* this2)
{
    int retorno=-1;

    int bufferIdI;
    int bufferIdJ;

    if(this1!=NULL && this2!=NULL)
    {
        venta_getCodProducto((Venta*)this1,&bufferIdI);
        venta_getCodProducto((Venta*)this2,&bufferIdJ);
        if(bufferIdI==bufferIdJ)
            retorno=0;
        else if(bufferIdI>bufferIdJ)
            retorno=1;
        else if(bufferIdI<bufferIdJ)
            retorno=-1;
    }
    return retorno;
}

/** \brief Busca el maximo ID
 *
 * \param pArrayList LinkedList*
 * \param maxID int*
 * \return int
 *
 */
int venta_searchMaxId(LinkedList* pArrayList, int* maxID)
{
    int retorno=-1;
    Venta* puntero=NULL;
    int size=ll_len(pArrayList);
    int i;
    int bufferId;
    int bufferMaxId=*maxID;

    if(pArrayList!=NULL && maxID!=NULL)
    {
        for(i=0;i<size;i++)
        {
            puntero=ll_get(pArrayList,i);
            if(puntero!=NULL)
            {
                venta_getId(puntero,&bufferId);
                if(bufferId>bufferMaxId)
                    bufferMaxId=bufferId;
            }
        }
        *maxID=bufferMaxId;
        retorno=0;
    }
    return retorno;
}
© 2019 GitHub, Inc.
