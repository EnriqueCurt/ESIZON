#ifndef FICHEROS_H
#define FICHEROS_H

#include "Structs.h"

void cargarclientes(clientes *clientes, int *numclientes);
void guardarclientes(clientes *clientes, int numclientes);

void cargartransportistas(transportistas *transportistas, int *numtransportistas);
void guardartransportistas(transportistas *transportistas, int numtransportistas);

void cargarproductos_pedidos(productos_pedidos *productos_pedidos, int *numproductos_pedido);
void guardarproductos_pedidos(productos_pedidos *productos_pedidos, int numproductos_pedido);

void cargarproductos(productos *productos, int *numproductos);
void guardarproductos(productos *productos, int numproductos);

void cargarcategorias(categorias *categorias, int *numcategorias);
void guardarcategorias(categorias *categorias, int numcategorias);

void cargardescuentos(descuentos *descuentos, int *numdescuentos);
void guardardescuentos(descuentos *descuentos, int numdescuentos);

void cargardescuentosclientes(descuentos_clientes *descuentosclientes, int *numdescuentosclientes);
void guardardescuentosclientes(descuentos_clientes *descuentosclientes, int numdescuentosclientes);

void cargarlockers(lockers *lockers, int *numlockers);
void guardarlockers(lockers *lockers, int numlockers);

void cargarcompartimentoslockers(compartimentos_lockers *compartimentoslockers, int *numcompartimentoslockers);
void guardarcompartimentoslockers(compartimentos_lockers *compartimentoslockers, int numcompartimentoslockers);

void cargaradmin_prov(admin_prov *admin_prov, int *numadmin_prov);
void guardaradmin_prov(admin_prov *admin_prov, int numadmin_prov);

void cargarpedidos(pedidos *pedidos, int *numpedidos);
void guardarpedidos(pedidos *pedidos, int numpedidos);

void cargardevoluciones(devoluciones *devoluciones, int *numdevoluciones);
void guardardevoluciones(devoluciones *devoluciones, int numdevoluciones);

#endif