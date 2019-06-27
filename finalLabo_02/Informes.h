#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

int Informes_ContadorAcumulado(LinkedList* pArrayList, int* contadorGold, int* contadorRegular, int* contadorPlus, int* acumuladoCantidad, int* promedioCantidad, int* promedioImporte);
int informeEntrega_saveAsText(char* path , LinkedList* pArrayList);

#endif // INFORMES_H_INCLUDED
