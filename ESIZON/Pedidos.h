#ifndef PEDIDOS_H
#define PEDIDOS_H
#include "Structs.h"

void ClientesPedidos(clientes * cliente, int id,pedidos *pedido,productos_pedidos *productopedido,productos *producto,int *numpedidos,int *numproductos, int numclientes);
void RealizarPedidoCliente(pedidos *pedido,productos_pedidos *productopedido,productos *producto,int *numpedidos,int *numproductos,int id);
void ModificarPedidoPropioCliente(clientes *cliente,int numclientes,pedidos *pedido,productos_pedidos *productopedido,productos *producto,int *numpedidos,int *numproductos,int id);
void ConsultarPedidoCliente(pedidos *pedido,productos_pedidos *productopedido,productos *producto,int *numpedidos,int *numproductos, int id);

void AdminPedidos(admin_prov * admin, int id,pedidos *pedido,productos_pedidos *productopedido,productos *producto,int *numpedidos,int *numproductos,lockers *locker,int numlockers,transportistas *transportista,int numtransportistas, int *productopedidos);
void RealizarPedidoAdmin(pedidos *pedido,productos_pedidos *productopedido,productos *producto,int *numpedidos,int *numproductos,int id);
void EliminarPedidoAdmin(pedidos *pedido,productos_pedidos *productopedido,productos *producto,int *numpedidos,int *numproductos,int id);
void ConsultarPedidoAdmin(pedidos *pedido,productos_pedidos *productopedido,productos *producto,int *numpedidos,int *numproductos);
void ModificarPedidoAdmin(pedidos *pedido,productos_pedidos *productopedido,productos *producto,int *numpedidos,int *numproductos,int id);

void ProveedorPedidos(admin_prov * admin, int id,pedidos *pedido,productos_pedidos *productopedido,productos *producto,int *numpedidos,int *numproductos,lockers *locker,int numlockers,transportistas *transportista,int numtransportistas, int *productopedidos);
void ConsultarPedidoProv(pedidos *pedido,productos_pedidos *productopedido,productos *producto,int *numpedidos,int *numproductos, int id);
void ModificarPedidoPropioProv(pedidos *pedido,productos_pedidos *productopedido,productos *producto,int *numpedidos,int *numproductos, int id);

void AsignarTransportista (pedidos *pedido,int *numpedidos,transportistas *transportista,int numtransportistas,productos_pedidos *productopedido,int numproductos_pedidos);
void AsignarLocker(pedidos *pedido,int *numpedidos,lockers *locker);
#endif
