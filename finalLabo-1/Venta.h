#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED

#define STR_SIZE 128

typedef struct
{
    int id;
    int idCliente;
    int codeProducto;
    int cantidad;
    float precio;
}Venta;

Venta* venta_new();
Venta* venta_newParametros(char* idStr, char* idClienteStr, char* codeProductoStr,char* cantidadStr, char* precioStr);
Venta* venta_newBinario(Venta venta);

void venta_delete();

int venta_setIdStr(Venta* char* id);

int venta_setIdClienteStr(Venta* this,char* isCliente);

int venta_setCodeProductoStr(Venta* this,char* codeProducto);

int venta_setCantidadStr(Venta* this,char* cantidad);

int venta_




#endif // VENTA_H_INCLUDED
