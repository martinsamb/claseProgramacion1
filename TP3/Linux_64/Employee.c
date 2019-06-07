#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
//#include "Validaciones.h"

Employee* employee_new(void)
{
    return (Employee*) malloc(sizeof(Employee));
}
Employee* employee_newParametros(char* idStr,
								char* nombreStr,
								char* horasTrabajadasStr)
{
    Employee* retorno = NULL;
    Employee* pAuxEmpleado;
    if(idStr != NULL && nombreStr !=NULL &&horasTrabajadasStr !=NULL)
    {
        pAuxEmpleado = employee_new();
        if(pAuxEmpleado != NULL)
        {

            if(!employee_setNombre(pAuxEmpleado,nombre)&&
            !employee_setHorasTrabajadas(pAuxEmpleado,horasTrabajadas)&&
            !employee_setIdStr(pAuxEmpleado,idStr))
            {
                retorno = pAuxEmpleado;
            }
            else
            {
                employee_delete(pAuxEmpleado);
            }
        }
    }

}


int employee_delete(Employee* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}

int employee_setId(Employee* this, int id)
{
    int retorno = -1;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}

int employee_setId(Empleado* this, char* id)
{
    int retorno = -1;
    if(this != NULL && id  != NULL && !isValidNumber(id))
    {
        retorno = employee_setId(this,atoi(id));;
    }
    return retorno;
}

int employee_getId(Employee* this, int* valor)
{
    int retorno = -1;
    if(this != NULL && valor != NULL)
    {
        *valor = this->id;
        retorno = 0;
    }
    return retorno;
}
int employee_getId(Employee* this,int* id)
{
    int retorno = -1;
    int bufferInt;
    if(this != NULL && valor != NULL)
    {
        employee_getId(this,&bufferInt);
        sprintf(valor,"%d",bufferInt);
        retorno = 0;
    }
    return retorno;
}
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL &&  VAL_int(horasTrabajadas,180))
    {
        this->horasTrabajadas = horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}
int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno = -1;
    if(this != NULL && sueldo(sueldo))
    {
        strncpy(this->sueldo,sueldo,sizeof(this->sueldo));
        retorno = 0;
    }
    return retorno;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno = -1;
    if(this != NULL && sueldo != NULL)
    {
        strncpy(sueldo,this->sueldo,sizeof(this->sueldo));
        retorno = 0;
    }
    return retorno;

}


int Emp_compararNombre(Empleado* this,Empleado* this1)
{
    int retorno = -2;
    if(this != NULL && this1 != NULL)
    {
        retorno = strncmp(this->nombre,this1->nombre,sizeof(this->nombre));
    }
    return retorno;
}

Employee* employee_add(char* nombre, int horasTrabajadas, int sueldo)
{
    Employee *retorno = NULL;
    Employee *employee = employee_new();
    if(employee != NULL && !employee_setNombre(employee,nombre) && !employee_setHorasTrabajadas(employee,horasTrabajadas)
        && !employee_setSueldo(employee,sueldo) && !employee_setId(employee, id))
    {
        retorno = employee;
    }else
        {
            free(employee);
        }
    return retorno;
}

Employee* employee_sort(char* nombre, int horasTrabajadass, int sueldo )
{
	Employee *retorno = NULL;
	Employee *employee = employee_new();
	if(employee != NULL && !employee_setNombre(employee, nombre)&& !employee_setHorasTrabajadads(employee, horasTrabajadas)
	&& !employee_setSueldo(employee, sueldo)&& !employee_setId(employee,id))
	{
		retorno = (employee);
	}
	return retorno;
}

int employee_compararPorNombre(void* this1, void*this2)
{
    char auxStrA[4096];
    char auxStrB[4096];
    employee_getNombre((Employee*)this1,auxStrA);
    employee_getNombre((Employee*)this2,auxStrB);
    if(strcmp(auxStrA,auxStrB)>0)
        return 1;
    else if(strcmp(auxStrA,auxStrB)<0)
    {
        return -1;
    }
    return 0;
}

int foo(int index, int (*pFun)(void*, void*), float peso)//Puntero a funcion(*pFUN)(void*,void*)
//funciones criterio
{
    pFunc(A,B);
}
