#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

int informes_ListVenta(LinkedList* pArrayList);
int informes_ListVentaPorProducto(LinkedList* pArrayList);
int informes_saveAsText(char* path , LinkedList* pArrayListA, LinkedList* pArrayListB);
int Informes_listarCriterioContadorAcumulado(LinkedList* pArrayListA, LinkedList* pArrayListB);

#endif // INFORMES_H_INCLUDED
