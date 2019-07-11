#ifndef LLAMADA_H_INCLUDED
#define LLAMADA_H_INCLUDED

typedef struct
{
    int ID_Llamada;
    char fecha[20];
    int Numero_Cliente;
    int ID_problema;
    int Solucionado;
}Llamada;

int Llamada_delete(Llamada* this);


Llamada* llamada_newLlamada();
Llamada* llamada_newLlamadaParametros(char* id, char* fecha, char* foto, char* cantidad,
                                      char* precio, char* cuit);

int llamada_setId_LlamadaStr(Llamada* this, char* id);
int llamada_setId_Llamada(Llamada* this, char* id);
int llamada_getId_Llamada(Llamada* this, char* id);

int llamada_setFecha(Llamada* this,int* id);
int llamada_getFecha(Llamada* this,int* id);

int llamada_setNumero_Cliente(Llamada* this, char* id);
int llamada_getNumero_Cliente(Llamada* this, char* id);

int llamada_setID_Problema(Llamada* this, char* id);
int llamada_getID_Problema(Llamada* this, char* id);
int llamada_setID_ProblemaStr(Llamada* this,int ID_Problema);

int llamada_setSolucionado(Llamada* this, char* id);
int llamada_getSolucionado(Llamada* this, char* id);




#endif // LLAMADA_H_INCLUDED
