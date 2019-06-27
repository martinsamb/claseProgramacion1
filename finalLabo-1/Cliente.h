#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#define STR_SIZE 128

typedef struct
{
    int id;
    char nombre[STR_SIZE];
    char apellido[STR_SIZE];
    char dni[STR_SIZE];
}Cliente;

Cliente* cliente_new();
Cliente* cliente_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* dniStr);
Cliente* cliente_newBinario(Cliente cliente);

void cliente_delete();

int cliente_setIdStr(Cliente* this,char* id);
int cliente_setId(Cliente* this,int id);
int cliente_getId(Cliente* this,int* id);

int cliente_setNombre(Cliente* this,char* nombre);
int cliente_getNombre(Cliente* this,char* nombre);

int cliente_setApellido(Cliente* this,char* apellido);
int cliente_getApellido(Cliente* this,char* apellido);

int cliente_setDni(Cliente* this,char* dni);
int cliente_getDni(Cliente* this,char* dni);

int cliente_cmpId(void* punteroI, void* punteroJ);
int cliente_cmpName(void* this1, void* this2);

int cliente_searchId(LinkedList* pArrayList, int valorBuscado, int* index);
int cliente_searchMaxId(LinkedList* pArrayList, int* maxID);

#endif // CLIENTE_H_INCLUDED
