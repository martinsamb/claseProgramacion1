#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "LinkedList.h"
#include "ControllerCliente.h"
#include "ControllerVenta.h"
#include "utn.h"


int main()
{
    int opcion;
    int ultimoIdCliente = 0;
    int ultimoIdVentas = 0;

    LinkedList* listaClientes = ll_newLinkedList();
    LinkedList* listaVentas = ll_newLinkedList();

    do{
        menuPrincipal();
        if(utn_getUnsignedInt(" ","\nError",1,sizeof(int),1,&option)!=0)
        {
            option=11;   //salir
        }
        else
        {
            switch(option)
            {
                case 1:
                    printf("\nAlta cliente");
                    controllerCliente_addCliente(listaClientes, &ultimoIdCliente);
                    break;

                case 2:
                    printf("\nModificacion cliente");
                    controllerCliente_editCliente;
                    break;

                case 3:
                    printf("\nBaja cliente");
                    if(1)
                    {
                        controllerCliente_removeCliente(listaClientes);
                    }
                    else
                    {
                        printf("\nEl cliente no se puede ser dado de baja , no tiene ventas");
                    }
                    break;

                case 4:
                    printf("\nListar clientes");
                    controllerCliente_sortCliente(listaClientes);
                    controllerCliente_listCliente(listaClientes);
                    break;

                case 5:
                    printf("\nAnular venta");
                    controllerVenta_addVenta(listaClientes. &ultimoIdVentas);
                    break;

                case 6:
                    printf("\nAnular venta");
                    controllerVenta_removeVenta(listaVentas);
                    break;

                case 7:
                    printf("\nInformar ventas");
                    controllerVenta_ListVenta(listaVentas);
                    break;

                case 8:
                    printf("\nInformar ventas por producto");
                    informes_ListVentaPorProducto(listaVentas);
                    break;

                case 9:
                    printf("\nGenerar informe de ventas");
                    informes_saveAsText("informe.txt",listaVentas,listaClientes);
                    break;

                case 10:
                    printf("\Informar cantidad de ventas por cliente");
                    informes_listarCriterioContadoAcumulado(listaClientes,listaVentas);
                    break;

                case 11:
                    break;
                default:
                    printf("\nOpcion no valida");
            }
        }
    }while(option != 11);

    return 0;
}
