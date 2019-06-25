#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include "LinkedList.h"


int parser_loadFromText(char* path , LinkedList* pArrayListEmployee);
int parser_parseEmpleados(FILE* fileName, LinkedList* listaEmpleados);
int generarArchivoSueldos(char* path , LinkedList* pArrayListEmployee);


#endif // PARSER_H_INCLUDED


