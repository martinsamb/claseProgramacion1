#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include "LinkedList.h"

int Apertura(char* archivo, LinkedList* ListaVenta);
int guardado(char* archivo, int total, int mayor150, int mayor300, int polaroids);

#endif // PARSER_H_INCLUDED
