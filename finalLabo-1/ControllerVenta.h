#ifndef CONTROLLERVENTA_H_INCLUDED
#define CONTROLLERVENTA_H_INCLUDED

int controllerVenta_loadFromText(char* path , LinkedList* pArrayList);
int controllerVenta_loadFromBinary(char* path , LinkedList* pArrayList);
int controllerVenta_addVenta(LinkedList* pArrayList, int* ultimoId);
int controllerVenta_editVenta(LinkedList* pArrayList);
int controllerVenta_removeVenta(LinkedList* pArrayList);
int controllerVenta_ListVenta(LinkedList* pArrayList);
int controllerVenta_sortVenta(LinkedList* pArrayList);
int controllerVenta_saveAsText(char* path , LinkedList* pArrayList);
int controllerVenta_saveAsBinary(char* path , LinkedList* pArrayList);

#endif // CONTROLLERVENTA_H_INCLUDED
