#ifndef PRODUCTOS_H
#define PRODUCTOS_H
#ifndef PEDIDOS_H
#define PEDIDOS_H
#include "Structs.h"

void Cliente_MostrarProductos(productos *productos, int numProductos);
void Admin_GestionarProductos(productos *productos, int *numProductos);
void Proveedor_GestionarProductos(productos *productos, int *numProductos, admin_prov *admin, int id);


#endif
