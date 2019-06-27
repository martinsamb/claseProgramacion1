#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED

#define STR_SIZE 128

typedef struct                          //Replace Venta (tipo) y venta (f)     campos: IdCliente + idCliente // CodProducto + codProducto // Nombre2 + nombre2
{
    int id;
    int idCliente;
    int codProducto;
    int cantidad;
    float precio;
}Venta;

Venta* venta_new();
Venta* venta_newParametros(char* idStr,char* idClienteStr, char* codProductoStr,char* cantidadStr,char* precioStr);
Venta* venta_newBinario(Venta venta);

void venta_delete();

int venta_setIdStr(Venta* this,char* id);
int venta_setId(Venta* this,int id);
int venta_getId(Venta* this,int* id);

int venta_setIdClienteStr(Venta* this,char* idCliente);
int venta_setIdCliente(Venta* this,int idCliente);
int venta_getIdCliente(Venta* this,int* idCliente);

int venta_setCodProductoStr(Venta* this,char* codProducto);
int venta_setCodProducto(Venta* this,int codProducto);
int venta_getCodProducto(Venta* this,int* codProducto);

int venta_setCantidadStr(Venta* this,char* cantidad);
int venta_setCantidad(Venta* this,int cantidad);
int venta_getCantidad(Venta* this,int* cantidad);

int venta_setPrecioStr(Venta* this,char* precio);
int venta_setPrecio(Venta* this,float precio);
int venta_getPrecio(Venta* this,float* precio);

int venta_cmpId(void* punteroI, void* punteroJ);
int venta_cmpCodProducto(void* this1, void* this2);


int venta_searchId(LinkedList* pArrayList, int valorBuscado, int* index);
int venta_searchMaxId(LinkedList* pArrayList, int* maxID);

#endif // VENTA_H_INCLUDED
