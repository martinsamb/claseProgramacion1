#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

#include "LinkedList.h"

struct S_Empleado
{
  int id;
  char nombre[128];
  int horasTrabajadas;
  int sueldo;
};
typedef struct S_Empleado Empleado;

void em_calcularSueldo(void* p);

#endif // EMPLEADO_H_INCLUDED

Empleado* employee_new();
Empleado* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo);
Empleado* employee_newBinario(Empleado empleado);

void employee_delete();

int employee_setIdStr(Empleado* this,char* id);
int employee_setId(Empleado* this,int id);
int employee_getId(Empleado* this,int* id);

int employee_setNombre(Empleado* this,char* nombre);
int employee_getNombre(Empleado* this,char* nombre);

int employee_setHorasTrabajadasStr(Empleado* this,char* horasTrabajadas);
int employee_setHorasTrabajadas(Empleado* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Empleado* this,int* horasTrabajadas);

int employee_setSueldoStr(Empleado* this,char* sueldo);
int employee_setSueldo(Empleado* this,int sueldo);
int employee_getSueldo(Empleado* this,int* sueldo);

int employee_cmpId(void* punteroI, void* punteroJ);
int employee_cmpName(void* this1, void* this2);
int employee_cmpIdCriterio(void* this1, void* criterio);


int employee_searchId(LinkedList* pArrayListEmployee, int valorBuscado, int* index);
int employee_searchMaxId(LinkedList* pArrayListEmployee, int* maxID);
