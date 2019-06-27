#ifndef CONTROLLERCLIENTE_H_INCLUDED
#define CONTROLLERCLIENTE_H_INCLUDED

int controllerCliente_loadFromText(char* path , LinkedList* pArrayList);
//int controllerCliente_loadFromBinary(char* path , LinkedList* pArrayList);
int controllerCliente_addCliente(LinkedList* pArrayList, int* ultimoId);
int controllerCliente_editCliente(LinkedList* pArrayList);
int controllerCliente_removeCliente(LinkedList* pArrayList);
int controllerCliente_ListCliente(LinkedList* pArrayList);
int controllerCliente_sortCliente(LinkedList* pArrayList);
int controllerCliente_saveAsText(char* path , LinkedList* pArrayList);



#endif // CONTROLLERCLIENTE_H_INCLUDED
