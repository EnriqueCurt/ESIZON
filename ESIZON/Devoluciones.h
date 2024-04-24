#ifndef DEVOLUCIONES_H
#define DEVOLUCIONES_H
#include "Structs.h"

void devolucionCliente(devoluciones *devolucion, int *numdevoluciones, pedidos *pedidos, int *numpedidos,int id_cliente, productos *productos, int *numproductos, productos_pedidos *productos_pedidos, int *numproductos_pedido);
int buscarPedido(pedidos *pedidos, int numpedidos, char id_pedido[8]);
int buscarProductoPedido(productos_pedidos *productos_pedidos, int numproductos_pedido, char id_pedido[8], char id_prod[8]);
void listarDevolucionesPendientes(devoluciones *devolucion, int numdevoluciones, int id_cliente,pedidos *pedidos, int numpedidos);
void listarDevolucionesAceptadas(devoluciones *devolucion, int numdevoluciones, int id_cliente,pedidos *pedidos, int numpedidos);
void listarDevolucionesRechazadas(devoluciones *devolucion, int numdevoluciones, int id_cliente,pedidos *pedidos, int numpedidos);
void listarDevolucionesEnviadas(devoluciones *devolucion, int numdevoluciones, int id_cliente,pedidos *pedidos, int numpedidos);
void listarPedidosCliente(pedidos *pedidos, int numpedidos, int id_cliente);
void listarProductosPedido(productos_pedidos *productos_pedidos, int numproductos_pedido, char id_pedido[8]);

void devolucionesAdmin(devoluciones *devolucion, int *numdevoluciones, pedidos *pedidos, int numpedidos, productos *productos, int *numproductos, productos_pedidos *productos_pedidos, int *numproductos_pedido);
void listarDevolucionesPendientesAdmin(devoluciones *devolucion, int numdevoluciones);
void listarDevolucionesAceptadasAdmin(devoluciones *devolucion, int numdevoluciones);
void listarDevolucionesRechazadasAdmin(devoluciones *devolucion, int numdevoluciones);
void listarDevolucionesEnviadasAdmin(devoluciones *devolucion, int numdevoluciones);

#endif // !DEVOLUCIONES_H