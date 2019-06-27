#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "ControllerCliente.h"
#include "ControllerVenta.h"
#include "utn.h"
#include "Venta.h"
#include "Cliente.h"


/*
7. Informar​ ​ventas:​​ ​Se​ ​imprimirá​ ​por​ ​pantalla​ ​las​ ​ventas​ ​realizadas.
8. Informar ventas por producto​. Se pedirá que se ingrese el códigodeunproducto y se​ ​imprimirá​ ​por​ ​pantalla​ ​las​ ​ventas​ ​realizadas​ ​de​ ​dicho​ ​producto.
9. Generar informe de ventas: ​Se generará un archivo "informe.txt" con el mismo formato​ ​que​ ​el​ ​punto​ ​7.
10.Informar cantidad de ventas por cliente: Listará por pantalla a los clientes indicando la cantidad de compras que tienen asociadas cada uno y el monto total de dichas​ ​compras
*/

//7
/** \brief Listar Venta
 *
 * \param pArrayList LinkedList*
 * \return int -1 Error (parametros nulos) / 0 parametros validos
 *
 */
int informes_ListVenta(LinkedList* pArrayList)
{
    int retorno=-1;
    int i;
    int j;
    int bufferIDVenta;
    int bufferIdCliente;                       //cambiar
    int bufferCodProducto;
    int bufferCantidad;
    float bufferPrecio;
    float bufferMonto;
    char bufferNombre[STR_SIZE];
    char bufferApellido[STR_SIZE];
    char bufferDni[STR_SIZE];
    int size=ll_len(pArrayList);
    Venta* pVenta;
    Cliente* pCliente;

    if(pArrayList!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            pVenta=ll_get(pArrayList,i);
            venta_getId(pVenta,&bufferIDVenta);
            venta_getCantidad(pVenta,&bufferCantidad);
            venta_getPrecio(pVenta,&bufferPrecio);
            venta_getIdCliente(pVenta,&bufferIdCliente);                       //cambiar
            venta_getCodProducto(pVenta,&bufferCodProducto);

            cliente_searchId(pArrayList,bufferIdCliente,&j);
            pCliente=ll_get(pArrayList,j);
            cliente_getNombre(pCliente,bufferNombre);
            cliente_getApellido(pCliente,bufferNombre);
            cliente_getDni(pCliente,bufferDni);

            bufferMonto=bufferPrecio*bufferCantidad;

            printf("\n ID Venta: %d\t Nombre: %s\t Apellido: %s\t DNI: %s\t IdCliente: %d\t CodProducto: %d\t Monto facturado: %.2f",bufferIDVenta,bufferNombre,bufferApellido,bufferDni,bufferIdCliente,bufferCodProducto,bufferMonto);                       //cambiar
        }
        retorno=0;
    }
    return retorno;
}

//8         Se imprime el listado de ventas o la cantidad de ventas?
/** \brief Listar Venta
 *
 * \param pArrayList LinkedList*
 * \return int -1 Error (parametros nulos) / 0 parametros validos
 *
 */
int informes_ListVentaPorProducto(LinkedList* pArrayList)
{
    int retorno=-1;
    int i;
    int bufferID;
    int bufferIdCliente;                       //cambiar
    int bufferCodProducto;
    int bufferCantidad;
    float bufferPrecio;
    int size;
    Venta* puntero;
    LinkedList* sublista=NULL;
    int criterio;
    int* pCriterio;
    pCriterio=&criterio;

    if(pArrayList!=NULL)
    {
        utn_getUnsignedInt("\nCodigo de producto: ","\nError",0,5,1,&criterio);
        sublista=ll_filter(pArrayList,venta_cmpCodProducto,pCriterio,0);
        if(sublista!=NULL)
        {
            size=ll_len(sublista);
            for(i=0;i<size;i++)
            {
                puntero=ll_get(sublista,i);
                venta_getId(puntero,&bufferID);
                venta_getCantidad(puntero,&bufferCantidad);
                venta_getPrecio(puntero,&bufferPrecio);
                venta_getIdCliente(puntero,&bufferIdCliente);                       //cambiar
                venta_getCodProducto(puntero,&bufferCodProducto);

                printf("\n ID: %d  IdCliente: %d   CodProducto: %d   Cantidad: %d   Precio: %f",bufferID,bufferIdCliente,bufferCodProducto,bufferCantidad,bufferPrecio);                       //cambiar
            }
            retorno=0;
        }
    }
    return retorno;
}

//9. Generar informe de ventas: ​Se generará un archivo "informe.txt" con el mismo formato​ ​que​ ​el​ ​punto​ ​7.

/** \brief Guarda los datos de los empleados en el archivo indicado (modo texto).
 *
 * \param path char* Nombre del archivo
 * \param pArrayList LinkedList*
 * \return int -1 Error / 0 Apertura de archivo exitosa
 *
 */
int informes_saveAsText(char* path , LinkedList* pArrayListA, LinkedList* pArrayListB)
{
    int i;
    Venta* pVenta=NULL;
    int retorno=-1;
    FILE *pFile=NULL;
    int bufferIDVenta;
    int bufferIdCliente;                       //cambiar
    int bufferCodProducto;                       //cambiar
    int bufferCantidad;
    float bufferPrecio;
    int contador=0;

    int j;
    float bufferMonto;
    char bufferNombre[STR_SIZE];
    char bufferApellido[STR_SIZE];
    char bufferDni[STR_SIZE];
    Cliente* pCliente;

    if(path!=NULL && pArrayListA!=NULL && pArrayListB!=NULL)
    {
        pFile=fopen(path,"w");
        if(pFile!=NULL)
        {
            for(i=0;i<ll_len(pArrayListA);i++)
            {
                pVenta=ll_get(pArrayListA,i);
                venta_getId(pVenta,&bufferIDVenta);
                venta_getCantidad(pVenta,&bufferCantidad);
                venta_getPrecio(pVenta,&bufferPrecio);
                venta_getIdCliente(pVenta,&bufferIdCliente);                       //cambiar
                venta_getCodProducto(pVenta,&bufferCodProducto);

                cliente_searchId(pArrayListB,bufferIdCliente,&j);
                pCliente=ll_get(pArrayListB,j);
                cliente_getNombre(pCliente,bufferNombre);
                cliente_getApellido(pCliente,bufferNombre);
                cliente_getDni(pCliente,bufferDni);

                bufferMonto=bufferPrecio*bufferCantidad;

                if(fprintf(pFile,"\n ID Venta: %d\t Nombre: %s\t Apellido: %s\t DNI: %s\t IdCliente: %d\t CodProducto: %d\t Monto facturado: %.2f",bufferIDVenta,bufferNombre,bufferApellido,bufferDni,bufferIdCliente,bufferCodProducto,bufferMonto)>100)                       //cambiar
                    contador++;
            }
            retorno=0;
            fclose(pFile);
            printf("\nElementos guardados exitosamente: %d",contador);
        }
    }
    return retorno;
}

//10.Informar cantidad de ventas por cliente: Listará por pantalla a los clientes indicando la cantidad de compras que tienen asociadas cada uno y el monto total de dichas​ ​compras
/** \brief Busca un valor repetido y lo lista una sola vez, junto con otros elementos de dos arrays vinculados
* \param arrayA Tipo Array de Tipo
* \param arrayB Tipo Array de Tipo
* \param sizeI int Tamaño del arrayA
* \param sizeJ int Tamaño del arrayB
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*/
//Cuenta las veces que se cumple un criterio en un arrayA y lo imprime una sola vez
int Informes_listarCriterioContadorAcumulado(LinkedList* pArrayListA, LinkedList* pArrayListB)         //cambiar Tipo
{
    int retorno=-1;
    int i;
    int k;
    int contador=0;
    int acumulado=0;
    int flag=-1;
    int sizeI=ll_len(pArrayListA);
    int sizeJ=ll_len(pArrayListB);

    int bufferID;
    int bufferIdCliente;
    char bufferNombre[STR_SIZE];
    char bufferApellido[STR_SIZE];
    char bufferDni[STR_SIZE];
    int bufferCantidad;
    float bufferPrecio;
    Cliente* pCliente=NULL;
    Venta* pVenta=NULL;

    if(pArrayListA!=NULL && sizeI>0 && pArrayListB!=NULL)
    {
        for(i=0;i<sizeI;i++)
        {
                pCliente=ll_get(pArrayListA,i);
                cliente_getId(pCliente,&bufferID);
                cliente_getNombre(pCliente,bufferNombre);
                cliente_getApellido(pCliente,bufferNombre);
                cliente_getDni(pCliente,bufferDni);

                printf("\n ID: %d   Nombre: %s   Apellido: %s  DNI: %s",bufferID,bufferNombre,bufferApellido,bufferDni);                       //cambiar

                for(k=0,contador=0,acumulado=0;k<sizeJ;k++)                                                            //Recorro por segunda vez el mismo array
                {
                    pVenta=ll_get(pArrayListB,k);
                    venta_getIdCliente(pVenta,&bufferIdCliente);
                    venta_getPrecio(pVenta,&bufferPrecio);
                    venta_getCantidad(pVenta,&bufferCantidad);
                    if(bufferIdCliente==bufferID)     //Busco las coincidencias en el 2do array
                    {
                        contador++;
                        acumulado+=(bufferPrecio*bufferCantidad);
                        flag=0;
                    }
                }
                printf("Cantidad ventas: %d \nMonto acumulado: %d",contador,acumulado);
        }
        if(flag==-1)
            printf("\nNo se encontraron clientes ");
        retorno=0;
    }
    return retorno;
}

