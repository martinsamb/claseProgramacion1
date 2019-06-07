#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno =-1;
    FILE *pFile = NULL;
    Employee auxEmpleado;
    Employee *pEmpleado;
    if(path != NULL && pArrayListEmployee != NULL)
    {
		pFile = fopen(path,"r");
		if(pFile != NULL)
		{
			while(!feof(pFile))
			{
				fread(&auxEmpleado,sizeof(Employee), 1, pFile);
				//printf("%s\n",auxEmpleado.nombre);
				pEmpleado = employee new();
				if(!employee_setId(pEmpleado,auxEmpleado.id)&&
				!employee_setNombre(pEmpleado,auxEmpleado.nombre)&&
				!employee_setHorasTrabajadas(pEmpleados,auxEmpleado.horasTrabajadas)&&
				!employee_setSueldo(pEmpleado.suledo))
				{
					ll_add(pArrayListEmployee,pEmpleado);
				}
				else
				{
					employee_delete(pEmpleado);
				}
			}
		}
		fclose(pFile)
    }
    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno =-1;
    int i ;
    Employee *pEmployee = NULL;
    FILE*pFile = NULL;
    if(path != NULL && pArrayListEmployee != NULL)
    {
		pFile = fopen(path,"w");
		if(pFile != NULL)
		{
			for(i =  0;ll_len(pArrayListEmployee);i++)
			{
				pEmployee = ll_get(pArrayListEmployee,i);
				//printf("%s\n",pEmployee->nombre);
				fwrite(pEmployee,sizeof(Employee),1,pFile);
			}
		}
		retorno = 0;
		fclose(pFile);
    }
    return 1;
}

