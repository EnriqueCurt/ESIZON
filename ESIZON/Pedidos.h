#ifndef PEDIDOS_H
#define PEDIDOS_H
#include "Structs.h"

void ClientePedidos(pedidos *pedidos, int *numpedidos);
void AdminPedidos(pedidos *pedidos, int *numpedidos);
void ProveedorPedidos(pedidos *pedidos, int *numpedidos, admin_prov *admin, int id);
void ModificarPedido(pedidos *pedido,productos_pedidos *productopedido,productos *producto,int *numpedidos,int *numproductos,int id);
void ConsultarPedido(pedidos *pedido,productos_pedidos *productopedido,productos *producto,int *numpedidos,int *numproductos,int id);
void EliminarPedido(pedidos *pedido,productos_pedidos *productopedido,productos *producto,int *numpedidos,int *numproductos,int id);
void RealizarPedido(pedidos *pedido,productos_pedidos *productopedido,productos *producto,int *numpedidos,int *numproductos,int id);
void AsignarLocker();
void AsignarTransportista();
#endif
