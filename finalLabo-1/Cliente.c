#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "Cliente.h"       //Replace Cliente (tipo) y cliente (f)
#include "utn.h"


/*
-cliente_new
-cliente_newParametros
-cliente_newBinario
-cliente_delete
-cliente_setIdStr
-cliente_setId
-cliente_getId
-cliente_setNombre
-cliente_getNombre
-cliente_setApellido
-cliente_getApellido
-cliente_setDni
-cliente_getDni
-cliente_cmpId
-cliente_cmpName
-cliente_searchId
-cliente_searchMaxId
*/

/** \brief Reserva espacio en memoria para un Cliente
 *
 * \param void
 * \return Cliente*
 *
 */
Cliente* cliente_new(void)       //constructor         //nuevo Cliente
{
    return (Cliente*) malloc(sizeof(Cliente));
}

/** \brief Valida los campos y los carga en una variable Cliente
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param apellidoStr char*
 * \param dniStr char*
 * \return Cliente*
 *
 */
Cliente* cliente_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* dniStr)
{
    Cliente* retorno=NULL;
    Cliente* bufferP;

    if(idStr!=NULL && nombreStr!=NULL && apellidoStr!=NULL && dniStr!=NULL)
    {
        bufferP=cliente_new();
        if(bufferP!=NULL)
        {
            if(!cliente_setIdStr(bufferP,idStr) &&
                !cliente_setNombre(bufferP,nombreStr) &&
                !cliente_setApellido(bufferP,apellidoStr) &&
                !cliente_setDni(bufferP,dniStr))
            {
                retorno=bufferP;
            }
            else
            {
                cliente_delete(bufferP);
            }
        }
    }
    return retorno;
}

/** \brief Valida los campos y los carga en una variable Cliente
 *
 * \param cliente Cliente
 * \return Cliente*
 *
 */
Cliente* cliente_newBinario(Cliente cliente)
{
    Cliente* retorno=NULL;
    Cliente* bufferP;

    char arrayBuffers[1][STR_SIZE];

    sprintf(arrayBuffers[0],"%d",cliente.id);

    if(arrayBuffers[0]!=NULL)
    {
        bufferP=cliente_new();
        if(bufferP!=NULL)
        {
            if(!cliente_setIdStr(bufferP,arrayBuffers[0]) &&
                !cliente_setNombre(bufferP,cliente.nombre) &&
                !cliente_setNombre(bufferP,cliente.apellido) &&
                !cliente_setNombre(bufferP,cliente.dni))
            {
                retorno=bufferP;
            }
            else
            {
                cliente_delete(bufferP);
            }
        }
    }
    return retorno;
}

/** \brief Libera el espacio reservado en memoria para un cliente
 *
 * \param this Cliente*
 * \return void
 *
 */
void cliente_delete(Cliente* this)
{
    if(this!=NULL)
    {
        free(this);
    }
}

//********************************************************************************************************************
//Setter+getters


/** \brief Valida un campo y lo carga en la variable Cliente
 *
 * \param this Cliente*
 * \param id char*
 * \return int
 *
 */
int cliente_setIdStr(Cliente* this,char* id)
{
    int retorno=-1;
    if(this!=NULL && id!=NULL && isValidNumber(id))
    {
        retorno=cliente_setId(this,atoi(id));
    }
    return retorno;
}

/** \brief Valida un campo y lo carga en la variable Cliente
 *
 * \param this Cliente*
 * \param id int
 * \return int
 *
 */
int cliente_setId(Cliente* this,int id)
{
    int retorno=-1;
    if(this!=NULL && id>=0)
    {
        this->id=id;
        retorno=0;
    }
    return retorno;
}

/** \brief Devulve el valor contenido en un campo de una variable Cliente
 *
 * \param this Cliente*
 * \param id int*
 * \return int
 *
 */
int cliente_getId(Cliente* this,int* id)
{
    int retorno=-1;
    if(this!=NULL && id!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

/** \brief Valida un campo y lo carga en la variable Cliente
 *
 * \param this Cliente*
 * \param nombre char*
 * \return int
 *
 */
int cliente_setNombre(Cliente* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL && isValidName(nombre))
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

/** \brief Devulve el valor contenido en un campo de una variable Cliente
 *
 * \param this Cliente*
 * \param nombre char*
 * \return int
 *
 */
int cliente_getNombre(Cliente* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

/** \brief Valida un campo y lo carga en la variable Cliente
 *
 * \param this Cliente*
 * \param apellido char*
 * \return int
 *
 */
int cliente_setApellido(Cliente* this,char* apellido)
{
    int retorno=-1;
    if(this!=NULL && apellido!=NULL && isValidName(apellido))
    {
        strcpy(this->apellido,apellido);
        retorno=0;
    }
    return retorno;
}

/** \brief Devulve el valor contenido en un campo de una variable Cliente
 *
 * \param this Cliente*
 * \param apellido char*
 * \return int
 *
 */
int cliente_getApellido(Cliente* this,char* apellido)
{
    int retorno=-1;
    if(this!=NULL && apellido!=NULL)
    {
        strcpy(apellido,this->apellido);
        retorno=0;
    }
    return retorno;
}

/** \brief Valida un campo y lo carga en la variable Cliente
 *
 * \param this Cliente*
 * \param dni char*
 * \return int
 *
 */
int cliente_setDni(Cliente* this,char* dni)
{
    int retorno=-1;
    if(this!=NULL && dni!=NULL && isValidDNI(dni))
    {
        strcpy(this->dni,dni);
        retorno=0;
    }
    return retorno;
}

/** \brief Devulve el valor contenido en un campo de una variable Cliente
 *
 * \param this Cliente*
 * \param dni char*
 * \return int
 *
 */
int cliente_getDni(Cliente* this,char* dni)
{
    int retorno=-1;
    if(this!=NULL && dni!=NULL)
    {
        strcpy(dni,this->dni);
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
int cliente_searchId(LinkedList* pArrayList, int valorBuscado, int* index)
{
    int retorno=-1;
    int i;
    int bufferID;
    int size=ll_len(pArrayList);
    Cliente* puntero=NULL;

    if(pArrayList!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            puntero=ll_get(pArrayList,i);
            cliente_getId(puntero,&bufferID);

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
int cliente_cmpId(void* this1, void* this2)
{
    int retorno=-1;

    int bufferIdI;
    int bufferIdJ;

    if(this1!=NULL && this2!=NULL)
    {
        cliente_getId((Cliente*)this1,&bufferIdI);
        cliente_getId((Cliente*)this2,&bufferIdJ);
        if(bufferIdI==bufferIdJ)
            retorno=0;
        else if(bufferIdI>bufferIdJ)
            retorno=1;
        else if(bufferIdI<bufferIdJ)
            retorno=-1;
    }
    return retorno;
}

/** \brief Compara dos Nombres
 *
 * \param this1 void*
 * \param this2 void*
 * \return int (0) Si son iguales (1) Si el primero es mayor (-1) Si el primero es menor
 *
 */
int cliente_cmpName(void* this1, void* this2)          //el sort es generico asique se usa el puntero generico void
{
    int retorno=-1;

    char bufferI[STR_SIZE];
    char bufferJ[STR_SIZE];

    if(this1!=NULL && this2!=NULL)
    {
        cliente_getApellido((Cliente*)this1,bufferI);
        cliente_getApellido((Cliente*)this2,bufferJ);
        if(strcmp(bufferI,bufferJ)==0)
            retorno=0;
        if(strcmp(bufferI,bufferJ)>0)
            retorno=1;
        if(strcmp(bufferI,bufferJ)<0)
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
int cliente_searchMaxId(LinkedList* pArrayList, int* maxID)
{
    int retorno=-1;
    Cliente* puntero=NULL;
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
                cliente_getId(puntero,&bufferId);
                if(bufferId>bufferMaxId)
                    bufferMaxId=bufferId;
            }
        }
        *maxID=bufferMaxId;
        retorno=0;
    }
    return retorno;
}
