#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/
/*
findById para  modificar/baja recorre el array y compara los indices
moficar
dar de baja
Listar
Ordenar. Documentacion de arraylist, que queremos ordenar. Funcion criterio
Funcion criterio ,ordenar empleados, quick sort, burbujeo. Insercion.
Guardar en modo texto
Guardar en modo binario, guardar punteros,
Leo del archivo y lo llevo a empleado. auxEmpleado
AuxEmpleado, hago el constructor
Validar bits archivo para pasarlo a un constructor
hash: funcion matematicas que devuelve un valor para corroborar
Archivo binario, tengo que generarlo. Sensible a la estructura linux,win64,win32- Volcar
Primero genero binario,
Arraylist:


*/

int main()
{
	int auxInt;

    char bufferId[4096];
    char bufferNombre[4096];
    int bufferHorasTrabajadas;
    int bufferSueldo;


    FILE *pFile = NULL;
    FILE *pFileBkp = NULL;
    pFileBkp = fopen("data.csv","r");
    pFileBkp = fopen("data.csv","w");

    if(pFile != NULL && pFileBkp != NULL)
    {
        fscanf(pFile,"%[[^,],%[^,],%[^,],%[^\n]\n",
        bufferId,bufferNombre, bufferHorasTrabajadas, bufferSueldo);

        printf("%s\n", bufferNombre);
    }
    fclose(pFile);
    fclose(pFileBkp);

    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;

			case 2:
				controller_addEmployee(FILE* pFile , LinkedList* pArrayListEmployee);
				break;

			case 3:
				break;

        }
    }while(option != 10);
    return 0;
}
