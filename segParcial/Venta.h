#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED

typedef struct
{
    int id;
    char fecha[20];
    char foto[30];
    int cantidad;
    float precio;
    char cuit[15];
}Venta;

int venta_delete(Venta* this);


Venta* venta_newVenta();
Venta* venta_newVentaParametros(char* id, char* fecha, char* foto, char* cantidad,
                                      char* precio, char* cuit);

int venta_setId(Venta* this,int id);
int venta_getId(Venta* this,int* id);
int venta_setIdStr(Venta* this, char* id);

int venta_setFecha(Venta* this,char* fecha);
int venta_getFecha(Venta* this,char* fecha);

int venta_setFoto(Venta* this,char* foto);
int venta_getFoto(Venta* this,char* foto);

int venta_setCantidad(Venta* this,int cantidad);
int venta_getCantidad(Venta* this,int* cantidad);
int venta_setCantidadStr(Venta* this, char* cantidad);

int venta_setPrecio(Venta* this,float precio);
int venta_getPrecio(Venta* this,float* precio);
int venta_setPrecioStr(Venta* this, char* precio);

int venta_setCuit(Venta* this,char* cuit);
int venta_getCuit(Venta* this,char* cuit);



#endif // VENTA_H_INCLUDED
